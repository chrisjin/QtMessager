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
////XML 解析类，解析XML，构造短信配置等的XML
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
    //解析短息XML数据包，存储在短信结构体Sms所指的地址内
    ////////////////////////////////////////////////////////
    static bool parse(QString content,SmsStruct* Sms)
    {
       QDomDocument Dom;
       Dom.setContent(content,false);
       //if(Dom.isSupported())

       QDomNode root=Dom.documentElement();

       //////////////判断是否是短信包格式
       if(root.toElement().tagName().trimmed()!="Sms")
       {
          Sms->PhoneNum="";
          Sms->Content="";
          return 0;
       }
       QDomNode child1=root.firstChild();////号码标签
       QDomNode child2=child1.nextSibling();////内容标签
       //////填充Sms结构体
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
    //构造开机数据包，根节点为turnon标签
    //开机数据包有phonenum和ip两个标签组成，把电话号码和ip对应关系发送给服务器
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
    //构造关机数据包，根节点为turnoff标签
    //格式和开机数据包大致相同
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
    //构造短信数据包
    //两部分:Number和content
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
    //解析一般的只有一层子节点的XML文本
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
    //获得第index个子节点对象
    ////////////////////////////////////////////////////////
    QDomElement get(int index)
    {
        return Tags[index];
    }

signals:
    
public slots:
    
};

#endif // V_XMLPASER_H
