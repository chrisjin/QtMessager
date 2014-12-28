#include<QApplication>
#include<QPushButton>
#include<QTcpServer>
#include<QTcpSocket>
#include<QDataStream>
#include<QHostAddress>
#include<QRegExp>
#include"v_station.h"
bool checkSms(QString con,QString KeyWords)
{

    QStringList stringlist=KeyWords.split(";");
    QString exp="";
    for(int i=0;i<stringlist.size();i++)
    {
        if(stringlist.at(i)=="")
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

int main(int argc, char *argv[])
{
    QVector<int>  tet;
    tet.push_back(1);
    tet.erase(tet.begin());


    QApplication app(argc,argv);
    V_Station ser;
    ser.run();

  //  QPushButton *bt=new QPushButton(QString::number(checkSms("hellsvvvv","hhhh;llll;hello;")));
  //  bt->show();

    return app.exec();

}
