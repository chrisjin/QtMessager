#ifndef SMSSTRUCT_H
#define SMSSTRUCT_H
#include<QString>
/////////////////////////////////////////////////////////////
////
////
////���Žṹ��
////
////
/////////////////////////////////////////////////////////////
struct SmsStruct
{
    int ID;           //ʵ����ÿ������Ψһ��ʶ
    QString PhoneNum; //�绰���룬����ʱ��ʾ���շ����룬��������ת��������ʱ��ʾ���ͷ�����
    QString Content;  //��������
    bool IsRet;       //�Ƿ��ǻ���
    bool IsRubbish;   //�Ƿ�����������
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
