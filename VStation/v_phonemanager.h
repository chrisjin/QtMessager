#ifndef V_PHONEMANAGER_H
#define V_PHONEMANAGER_H

#include <QObject>
#include<QMap>
#include<QVector>
#include"SmsStruct.h"
#include<QTcpSocket>
#include<vector>
#include"V_ClientSocket.h"
using namespace std;
class V_PhoneManager : public QObject
{
    Q_OBJECT
public:
    explicit V_PhoneManager(QObject *parent = 0);
    QMap<QString,QString> PhonePool;   //phone  ->  ip
    QMap<QString,QTcpSocket* > PhoneSocketPool;
    QMap<QString,bool>   PhoneIsOn;
    QVector<SmsStruct* > SmsPool;
    void addSms(SmsStruct *p);
    void addPhone(QString phonenum,QString ip,QTcpSocket *tcpsocket);
    void TurnOffPhone(QString phonenum);
    //QMap<QString,QString>
    QString getPhoneNumByIP(QString IP);
    QString getPhoneNumBySocket(QTcpSocket* tcpsocket);
    bool    getPhoneState(QString Num);
signals:
    
public slots:
    
};

#endif // V_PHONEMANAGER_H
