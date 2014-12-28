#include "v_phonemanager.h"

V_PhoneManager::V_PhoneManager(QObject *parent) :
    QObject(parent)
{
}

void V_PhoneManager::addSms(SmsStruct *p)
{
    SmsPool.push_back(p);
}

void V_PhoneManager::addPhone(QString phonenum, QString ip,QTcpSocket *tcpsocket )
{
   // PhonePool.insert(phonenum,ip);
   // PhoneSocketPool.insert(phonenum,tcpsocket);
    PhonePool[phonenum]=ip;
    PhoneSocketPool[phonenum]=tcpsocket;
    PhoneIsOn[phonenum]=1;
}

void V_PhoneManager::TurnOffPhone(QString phonenum)
{
    PhoneIsOn[phonenum]=0;
}

QString V_PhoneManager::getPhoneNumByIP(QString IP)
{
    QMap<QString,QString>::iterator itr=PhonePool.begin();
    for(;itr!=PhonePool.end();itr++)
    {
        if(itr.value()==IP)
            return itr.key();
    }
    return "";
}

QString V_PhoneManager::getPhoneNumBySocket(QTcpSocket *tcpsocket)
{
    QMap<QString,QTcpSocket *>::iterator itr=PhoneSocketPool.begin();
    for(;itr!=PhoneSocketPool.end();itr++)
    {
        if(itr.value()==tcpsocket)
            return itr.key();
    }
    return "";
}

bool V_PhoneManager::getPhoneState(QString Num)
{
    return PhoneIsOn[Num];
}
