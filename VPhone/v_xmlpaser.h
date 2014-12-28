#ifndef V_XMLPASER_H
#define V_XMLPASER_H
#include<QDomDocument>
#include<QDomElement>
#include <QObject>
#include <QVector>
#include"SmsStruct.h"
#include<Qdebug>
#include<QPushButton>
/////////////////////////////////////////////////////////////
////
////
////XML �����࣬����XML������������õȵ�XML
////
////
/////////////////////////////////////////////////////////////
class V_XMLPaser : public QObject
{
    Q_OBJECT
public:
    explicit V_XMLPaser::V_XMLPaser(QObject *parent=0) :
        QObject(parent)
    {
    }
    ////////////////////////////////////////////////////////
    //������ϢXML���ݰ����洢�ڶ��Žṹ��Sms��ָ�ĵ�ַ��
    ////////////////////////////////////////////////////////
    static bool parse(QString content,SmsStruct* Sms)
    {
       QDomDocument Dom;
       Dom.setContent(content,false);
       //if(Dom.isSupported())

       QDomNode root=Dom.documentElement();

       //////////////�ж��Ƿ��Ƕ��Ű���ʽ
       if(root.toElement().tagName().trimmed()!="Sms")
       {
          Sms->PhoneNum="";
          Sms->Content="";
          return 0;
       }
       QDomNode child1=root.firstChild();////�����ǩ
       QDomNode child2=child1.nextSibling();////���ݱ�ǩ
       //////���Sms�ṹ��
       if(!child1.isNull())
       Sms->PhoneNum=child1.toElement().text();
       else
           Sms->PhoneNum="";
       if(!child2.isNull())
       Sms->Content=child2.toElement().text();
       else
           Sms->Content="";
       return 1;
     //  qDebug()<<Sms->PhoneNum;
    }
    ////////////////////////////////////////////////////////
    //���쿪�����ݰ������ڵ�Ϊturnon��ǩ
    //�������ݰ���phonenum��ip������ǩ��ɣ��ѵ绰�����ip��Ӧ��ϵ���͸�������
    ////////////////////////////////////////////////////////
    static QString TurnOnMessage(QString PhoneNum,QString IP)
    {
       QDomDocument Dom;
       QDomElement  root=Dom.createElement("turnon");
       QDomElement child1=Dom.createElement("phonenum");
       QDomElement child2=Dom.createElement("ip");
       child1.appendChild(Dom.createTextNode(PhoneNum));
       child2.appendChild(Dom.createTextNode(IP));
       Dom.appendChild(root);
       root.appendChild(child1);
       root.appendChild(child2);
       return Dom.toString();

    }
    ////////////////////////////////////////////////////////
    //����ػ����ݰ������ڵ�Ϊturnoff��ǩ
    //��ʽ�Ϳ������ݰ�������ͬ
    ////////////////////////////////////////////////////////
    static QString TurnOffMessage(QString PhoneNum,QString IP)
    {
       QDomDocument Dom;
       QDomElement  root=Dom.createElement("turnoff");
       QDomElement child1=Dom.createElement("phonenum");
       QDomElement child2=Dom.createElement("ip");
       child1.appendChild(Dom.createTextNode(PhoneNum));
       child2.appendChild(Dom.createTextNode(IP));
       Dom.appendChild(root);
       root.appendChild(child1);
       root.appendChild(child2);
       return Dom.toString();

    }
    ////////////////////////////////////////////////////////
    //����������ݰ�
    //������:Number��content
    ////////////////////////////////////////////////////////
    static QString ShortMessage(QString PhoneNum,QString Con)
    {
        QDomDocument Dom;
        QDomElement  root=Dom.createElement("Sms");
        QDomElement child1=Dom.createElement("Number");
        QDomElement child2=Dom.createElement("content");
        child1.appendChild(Dom.createTextNode(PhoneNum));
        child2.appendChild(Dom.createTextNode(Con));
        Dom.appendChild(root);
        root.appendChild(child1);
        root.appendChild(child2);
        return Dom.toString();

    }
    ////////////////////////////////////////////////////////
    //����һ���ֻ��һ���ӽڵ��XML�ı�
    ////////////////////////////////////////////////////////
    QDomDocument Dom;
    QVector< QDomElement > Tags;
    void parse(QString content)
    {
       Tags.clear();
       Dom.setContent(content,false);
       QDomNode root=Dom.documentElement();
       QDomElement ele;
       for(int i=0;;i++)
       {
           if(i==0)
               ele=root.firstChildElement();
           else
               ele=ele.nextSiblingElement();
           if(ele.isNull())
               break;
           Tags.push_back(ele);

       }
    }
    ////////////////////////////////////////////////////////
    //��õ�index���ӽڵ����
    ////////////////////////////////////////////////////////
    QDomElement get(int index)
    {
        return Tags[index];
    }

signals:
    
public slots:
    
};

#endif // V_XMLPASER_H
