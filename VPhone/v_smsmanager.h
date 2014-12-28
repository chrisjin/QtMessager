#ifndef V_SMSMANAGER_H
#define V_SMSMANAGER_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QVector>
#include<QFile>
#include<QDomDocument>
#include<QDomElement>
#include <QDomNodeList>
#include"SmsStruct.h"
/////////////////////////////////////////////////////////////
////
////
////短信管理类。查找，添加，删除，保存，导入
////
////
/////////////////////////////////////////////////////////////
class V_SmsManager : public QObject
{
    Q_OBJECT
public:
    int SmsID;
    explicit V_SmsManager(QObject *parent = 0);
    QVector<SmsStruct*> SmsPool;
    QMap< QString,QVector<SmsStruct*> > SmsSearchPool;//PhoneNum->Set of sms
    void addSms(SmsStruct *Sms);
    bool deleteByNum(QString Num);
    bool removeByNumCon(QString num,QString con);
    bool removeByNum(QString Num);
    bool deleteByID(int ID);
    void deleteAll();
    void save(QString filename);
    void load(QString filename);


    bool recoverByNum(QString Num);
    bool removeByID(int ID);
    bool deleteAllRubbish();
    bool deleteRubByNum(QString num);
signals:
    
public slots:
    
};

#endif // V_SMSMANAGER_H
