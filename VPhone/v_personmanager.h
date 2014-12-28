#ifndef V_PERSONMANAGER_H
#define V_PERSONMANAGER_H

#include <QObject>
#include<QMap>
#include <QString>
#include <QFile>
#include<QDomDocument>
#include<QDomElement>
#include <QDomNodeList>
/////////////////////////////////////////////////////////////
////
////
////��ϵ�˹����ࡣ��ӣ�ɾ�������ң����棬����
////
////
/////////////////////////////////////////////////////////////
class V_PersonManager : public QObject
{
    Q_OBJECT
public:
    explicit V_PersonManager(QObject *parent = 0);
    QMap<QString,QString> PhoneNum2Name;
    QMap<QString,int>     IsBlack;
    void addPerson(QString num,QString name,bool black=0);
    QString getNameByNum(QString num);
    void deletePerson(QString Num);
    void setBlack(QString Num);
    void save(QString filename);
    void load(QString filename);
    void revBlack(QString Num);
signals:
    
public slots:
    
};

#endif // V_PERSONMANAGER_H
