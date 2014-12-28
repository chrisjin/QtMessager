#include "v_phone.h"
#include"v_xmlpaser.h"
#include<QNetworkInterface>
#include<QFile>
//QString PHONENUM="15140053439";
//QString SERVERIP="192.168.232.1";
V_Phone::V_Phone(QObject *parent) :
    QObject(parent)
{
  IsOn=0;
  //  PhoneNum=PHONENUM;

}

bool V_Phone::checkSms(QString con)
{

    QStringList stringlist=KeyWords.split(";");
    QString exp="";
    for(int i=0;i<stringlist.size();i++)
    {
        if(stringlist.at(i).trimmed()=="")
            continue;
        if(i==0)
            exp+=QString("(\w*")+stringlist.at(i)+"\w*)";
        else
            exp+=QString("|(\w*")+stringlist.at(i)+"\w*)";

    }

    QRegExp regexp(exp);
    if(regexp.indexIn(con)==-1)
    return 1;
    else
    return 0;
}

void V_Phone::init()
{
    ////////////////////////////////////
    ////GET  LOCAL IP
    ////////////////////////////////////
    QList<QHostAddress> AddressList = QNetworkInterface::allAddresses();
    QHostAddress result;
    foreach(QHostAddress address, AddressList)
    {
        if(address.protocol() == QAbstractSocket::IPv4Protocol &&
        address != QHostAddress::Null &&
        address != QHostAddress::LocalHost)
        {
            if (address.toString().contains("127.0."))
            {
                continue;
            }
            result = address;
            break;
        }
    }
    IP=result.toString();
    ////////////////////////////////////
    ////GET   LOCAL CONFIG
    ////////////////////////////////////
    QFile configfile("config");
    if(!configfile.open(QFile::ReadOnly|QFile::Text))
    {
        qDebug()<<"Error file";
    }
    QDomDocument configdoc;
    configdoc.setContent(&configfile,false);
    QDomElement phonenum =configdoc.elementsByTagName("phonenum").item(0).toElement();
    QDomElement serverip =configdoc.elementsByTagName("serverip").item(0).toElement();
    PhoneNum=phonenum.text().trimmed();
    ServerIP=serverip.text().trimmed();
    qDebug()<<PhoneNum<<ServerIP;


    ////////////////////////////////////
    ////CONNECT signal
    ////////////////////////////////////
    connect(&ConnectSocket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    //connect(&ConnectSocket,SIGNAL(connected()),&ConnectSocket,SLOT(onConnected()));
    connect(&ConnectSocket,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(PhoneGUI.TurnonBtn,SIGNAL(clicked()),this,SLOT(onTurnonBtn()));
    connect(PhoneGUI.SendBtn,SIGNAL(clicked()),this,SLOT(onSendBtn()));
    connect(this,SIGNAL(destroyed()),this,SLOT(onDestroy()));
    connect(&PhoneGUI,SIGNAL(closeSignal()),this,SLOT(onClose()));
    connect(&PhoneGUI,SIGNAL(enterMessageList()),this,SLOT(onMessageList()));
    connect(&PhoneGUI,SIGNAL(addPersonSignal(QString,QString)),
            this,SLOT(onAddPerson(QString,QString)));
    connect(PhoneGUI.MessageList,SIGNAL(deleteItemSignal(int)),
            this,SLOT(onDeleteItem(int)));
    connect(PhoneGUI.MailBoxListWidget,SIGNAL(deleteItembyNumSignal(QString)),
            this,SLOT(onDeleteItembyNum(QString)));
    connect(PhoneGUI.RubbishListWidget,SIGNAL(deleteItemIrevbyNumSignal(QString)),
            this,SLOT(onDeleteIrevByNum(QString)));
    connect(PhoneGUI.RubbishListWidget,SIGNAL(deleteItembyNumSignal(QString)),
            this,SLOT(onDeleteItembyNum(QString)));
    connect(PhoneGUI.PeopleListWidget,SIGNAL(setBlackSignal(QString)),
            this,SLOT(onSetBlack(QString)));
    connect(PhoneGUI.PeopleListWidget,SIGNAL(deletePerson(QString)),
            this,SLOT(onDeletePerson(QString)));
    ////////////////////////////////////
    ////
    ////////////////////////////////////
    SmsManager.load("sms.xml");


    PersonManager.load("person.xml");
    updatePerson();
    updateMessage();
    updateMailBox();
    updateRubbishBin();


    QFile conffile2("key.txt");
    conffile2.open(QFile::ReadOnly|QFile::Text);
    KeyWords=conffile2.readAll();

   // QPushButton *bt=new QPushButton(KeyWords.split(";")[0]);
   // bt->show();
}

void V_Phone::show()
{
    PhoneGUI.setWindowTitle(PhoneNum);
    PhoneGUI.show();
}
void V_Phone::turnOn()
{

    ConnectSocket.connectToHost(ServerIP,1573);


}
void V_Phone::turnOff()
{
     ConnectSocket.writeContent(V_XMLPaser::TurnOffMessage(PhoneNum,IP));
     ConnectSocket.disconnectFromHost();
     SmsManager.save("sms.xml");
     PersonManager.save("person.xml");
     PhoneGUI.TurnonBtn->setIcon(QIcon("icon/turnon.png"));
     IsOn=0;
}

void V_Phone::sendMessage(QString Num, QString con)
{
    SmsStruct* smsstruct=new SmsStruct;
    smsstruct->IsRet=1;
    smsstruct->PhoneNum=Num;
    smsstruct->Content=con;
    SmsManager.addSms(smsstruct);
    PhoneGUI.MailBoxListWidget->loadSmsManager(&SmsManager,&PersonManager);
    PhoneGUI.MessageList->loadSms(&SmsManager,PhoneGUI.CurrentNum);
    ConnectSocket.writeContent(V_XMLPaser::ShortMessage(Num,con));
}

void V_Phone::onReadyRead()
{
    QTcpSocket* sc=dynamic_cast<QTcpSocket*>(sender());
    if(sc==0)return;
    char *con=new char[sc->bytesAvailable()+1];
    memset(con,0,sc->bytesAvailable()+1);
    sc->read(con,sc->bytesAvailable());
    QString Content=con;
    if(Content=="turnonsuccess")
    {
        PhoneGUI.TurnonBtn->setIcon(QIcon("icon/on.png"));
        IsOn=1;

    }





    SmsStruct *smsstruct=new SmsStruct;
    bool ret=V_XMLPaser::parse(Content,smsstruct);
    if(ret)
    {
        smsstruct->IsRet=0;
        if(PersonManager.IsBlack[smsstruct->PhoneNum]
          ||checkSms(smsstruct->Content)==0    )
            smsstruct->IsRubbish=1;
        else
            smsstruct->IsRubbish=0;
        SmsManager.addSms(smsstruct);

        updateMessage();
        updateMailBox();
        updateRubbishBin();
        if(!smsstruct->IsRubbish)
            PhoneGUI.MailBoxListWidget->setCheck(smsstruct->PhoneNum);
    }

    //PhoneGUI.MessageList->loadSms(&SmsManager,PhoneGUI.CurrentNum);
    //PhoneGUI.MailBoxListWidget->loadSmsManager(&SmsManager,&PersonManager);

    //updateRubbishBin();

 //   QPushButton *bt=new QPushButton;
 //   bt->setText(Content+"   !!!!!local"+PhoneNum+"pool"+QString::number(SmsManager.SmsSearchPool.size()));
 //   bt->show();
}

void V_Phone::onConnected()
{

    ConnectSocket.writeContent(
                V_XMLPaser::TurnOnMessage(this->PhoneNum,IP));


}

void V_Phone::onSendBtn()
{
    QString con=PhoneGUI.LineEdit->toPlainText();
    //QPushButton *bt=new QPushButton;
    //bt->setText(PhoneGUI.CurrentNum);
    //bt->show();

    sendMessage(PhoneGUI.CurrentNum,con);

}

void V_Phone::onDestroy()
{
    // qDebug()<<"sddddd";
}

void V_Phone::onClose()
{
    //QPushButton *bt=new QPushButton;
    //bt->setText("AAAAAAA");
    //bt->show();
    turnOff();

}

void V_Phone::onMessageList()
{
    PhoneGUI.MessageList->loadSms(&SmsManager,PhoneGUI.CurrentNum);
    PhoneGUI.MailBoxListWidget->setUnCheck(PhoneGUI.CurrentNum);
    //QPushButton *bt=new QPushButton;
   //bt->setText(QString::number(SmsManager.SmsSearchPool[PhoneGUI.CurrentNum].size()));
   // bt->show();
    // SmsManager.SmsSearchPool["2222"];
}

void V_Phone::onAddPerson(QString a, QString b)
{
    PersonManager.addPerson(a,b);
}

void V_Phone::onDeleteItem(int ID)
{
    //QPushButton *bt=new QPushButton(con);
    //bt->show();
    SmsManager.removeByID(ID);
    updateRubbishBin();
    updateMailBox();
}

void V_Phone::onDeleteItembyNum(QString Num)
{
    //QPushButton *bt=new QPushButton(Num);
    //bt->show();
    V_MailBoxListWidget *listwidget=(V_MailBoxListWidget *)sender();
    if(listwidget->IsRubbishBin)
    SmsManager.recoverByNum(Num);
    else
        SmsManager.removeByNum(Num);
    updateRubbishBin();
    updateMailBox();
}

void V_Phone::onSetBlack(QString Num)
{
    //QPushButton *bt=new QPushButton(Num);
    //bt->show();
    PersonManager.revBlack(Num);
    updatePerson();
}

void V_Phone::onTurnonBtn()
{
    //QPushButton *bt=dynamic_cast<QPushButton*>(sender());
    if(!IsOn)
    {

        turnOn();
    }
    else
        turnOff();
}

void V_Phone::onDeletePerson(QString Num)
{
   // QPushButton *bt=new QPushButton;
   // bt->show();
    PersonManager.deletePerson(Num);
}

void V_Phone::onDeleteIrevByNum(QString Num)
{
    //QPushButton *bt=new QPushButton;
    //bt->show();

    SmsManager.deleteRubByNum(Num);
}

void V_Phone::updatePerson()
{
    PhoneGUI.PeopleListWidget->loadPersonManager(&PersonManager);
}

void V_Phone::updateMessage()
{
    PhoneGUI.MessageList->loadSms(&SmsManager,PhoneGUI.CurrentNum);
}

void V_Phone::updateMailBox()
{
    PhoneGUI.MailBoxListWidget->loadSmsManager(&SmsManager,&PersonManager);
}

void V_Phone::updateRubbishBin()
{
    PhoneGUI.RubbishListWidget->loadSmsManager(&SmsManager,&PersonManager,1);
}
