#ifndef SMSSTRUCT_H
#define SMSSTRUCT_H
#include<QString>
struct SmsStruct
{
    int ID;
    QString PhoneNum;
    QString Content;
    QString SenderNum;
    SmsStruct(){}
    SmsStruct(int a,QString con)
    {
      PhoneNum=a;
      Content=con;
    }
};
#endif // SMSSTRUCT_H
