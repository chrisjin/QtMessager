#ifndef V_XMLPASER_H
#define V_XMLPASER_H
#include<QDomDocument>
#include<QDomElement>
#include <QObject>
#include <QVector>
#include"SmsStruct.h"

struct XMLTag
{
    QString TagName;
    QString Content;
};
class V_XMLPaser : public QObject
{
    Q_OBJECT
public:
    explicit V_XMLPaser::V_XMLPaser(QObject *parent=0) :
        QObject(parent)
    {
    }


    static void parse(QString content,SmsStruct* Sms)
    {
       QDomDocument Dom;
       Dom.setContent(content,false);
       QDomNode root=Dom.documentElement();
       QDomNode child1=root.firstChild();
       QDomNode child2=child1.nextSibling();
       Sms->PhoneNum=child1.toElement().text();
       Sms->Content=child2.toElement().text();
    }
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
    QDomDocument Dom;
    QVector< QDomElement > Tags;
    QString Name;
    void parse(QString content)
    {
       Tags.clear();
       Dom.setContent(content,false);
       QDomNode root=Dom.documentElement();
       QDomElement ele;
       Name=root.toElement().tagName();
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
    QDomElement get(int index)
    {
        return Tags[index];
    }

signals:

public slots:

};

#endif // V_XMLPASER_H
