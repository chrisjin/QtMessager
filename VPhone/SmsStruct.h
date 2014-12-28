#ifndef SMSSTRUCT_H
#define SMSSTRUCT_H
#include<QString>
/////////////////////////////////////////////////////////////
////
////
////短信结构体
////
////
/////////////////////////////////////////////////////////////
struct SmsStruct
{
    int ID;           //实例里每条短信唯一标识
    QString PhoneNum; //电话号码，发送时表示接收方号码，经服务器转换，接收时表示发送方号码
    QString Content;  //短信内容
    bool IsRet;       //是否是回信
    bool IsRubbish;   //是否是垃圾短信
    bool IsDelete;
    SmsStruct(){IsRubbish=0;IsDelete=0;}
    SmsStruct(QString a,QString con)
    {
      //ID++;
      IsRubbish=0;
      IsDelete=0;
      PhoneNum=a;
      Content=con;
    }
};
#endif // SMSSTRUCT_H
