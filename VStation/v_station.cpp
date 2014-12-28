#include "v_station.h"

V_Station::V_Station(QObject *parent) :
    QTcpServer(parent)
{
}

void V_Station::run()
{
   // connect(&ServerSocket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
  //  connect(this,SIGNAL(connect()),)
    if(!listen(QHostAddress::Any,1573))
    {
        QPushButton* pushbutton1=new QPushButton;
        pushbutton1->show();
    }
    PhoneTableWidget.show();
}

void V_Station::incomingConnection(int sockid)
{

        V_ClientSocket *tcpsocket=new V_ClientSocket(this);
        tcpsocket->setSocketDescriptor(sockid);
        connect(tcpsocket,SIGNAL(readyRead()),tcpsocket->parent(),SLOT(onReadyRead()));
        connect(tcpsocket,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
        connect(tcpsocket,SIGNAL(error(QAbstractSocket::SocketError)),
                this,SLOT(onSocketError(QAbstractSocket::SocketError)));
     //   QPushButton *pushbutton=new QPushButton;
     //   pushbutton->setText("this->con");
     //   pushbutton->show();

}

void V_Station::onReadyRead()
{
    QTcpSocket* sc=dynamic_cast<QTcpSocket*>(sender());
    if(sc==0)return;
    char *con=new char[sc->bytesAvailable()+1];
    memset(con,0,sc->bytesAvailable()+1);
    sc->read(con,sc->bytesAvailable());
    QString Content=con;








    ////解析客户端信息
    V_XMLPaser parser;
    parser.parse(Content);


    qDebug()<<"______"<<"Start";

    SmsStruct *sms=new SmsStruct;
    if(parser.Name=="turnon")
    {
        PhoneManager.addPhone(parser.get(0).text(),parser.get(1).text(),sc);
        QVector<SmsStruct*>::iterator itr=PhoneManager.SmsPool.begin();

        for(;itr<PhoneManager.SmsPool.end();itr++)
        {
            if((*itr)!=0)
                if((*itr)->PhoneNum==parser.get(0).text())
               {
                  // V_ClientSocket socket;
                   //socket.connectToHost(parser.get(1).text(),80);
                  // socket.writeContent(
                  //             V_XMLPaser::ShortMessage((*itr)->PhoneNum,(*itr)->Content));
                   QString str= V_XMLPaser::ShortMessage((*itr)->SenderNum,(*itr)->Content);
                   sc->write(str.toStdString().c_str(),str.length()+1);
                   qDebug()<<"_____"<<QString::number(PhoneManager.SmsPool.size());

                   PhoneManager.SmsPool.erase(itr);

                   qDebug()<<"___kkk"<<QString::number(PhoneManager.SmsPool.size());
                   if(PhoneManager.SmsPool.size()==0)break;
               }
        }
        qDebug()<<"___nnn"<<QString::number(PhoneManager.SmsPool.size());

         sc->write("turnonsuccess",14);
    }
    else if(parser.Name=="Sms")
    {

        V_XMLPaser::parse(Content,sms);
        sms->SenderNum=PhoneManager.getPhoneNumBySocket(sc);
        QMap<QString,QTcpSocket*>::iterator itr=
                PhoneManager.PhoneSocketPool.find(sms->PhoneNum);
        if(itr!=PhoneManager.PhoneSocketPool.end()&&PhoneManager.PhoneIsOn[sms->PhoneNum])
        {
            QString con=V_XMLPaser::ShortMessage(PhoneManager.getPhoneNumBySocket(sc),sms->Content);
            itr.value()->write(con.toStdString().c_str(),con.length()+1);
        }
        else
        {
            PhoneManager.addSms(sms);
        }
    }
    else if(parser.Name=="turnoff")
    {
        PhoneManager.TurnOffPhone(parser.get(0).text().trimmed());

    }



    qDebug()<<"_______"<<parser.Name;




    //QPushButton *pushbutton=new QPushButton;
   // pushbutton->setText(parser.Name);
   // pushbutton->show();

    PhoneTableWidget.loadPhoneManager(&PhoneManager);

}

void V_Station::onDisconnected()
{
    QTcpSocket* sc=dynamic_cast<QTcpSocket*>(sender());
    if(sc==0)return;
    PhoneManager.TurnOffPhone(PhoneManager.getPhoneNumBySocket(sc));
    PhoneTableWidget.loadPhoneManager(&PhoneManager);

}

void V_Station::onSocketError(QAbstractSocket::SocketError err)
{
    QTcpSocket* sc=dynamic_cast<QTcpSocket*>(sender());
    if(sc==0)return;
    PhoneManager.TurnOffPhone(PhoneManager.getPhoneNumBySocket(sc));
    PhoneTableWidget.loadPhoneManager(&PhoneManager);
}
