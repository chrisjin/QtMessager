#include<QApplication>
#include<QPushButton>
#include"v_smsmanager.h"
#include<QDomDocument>
#include<QDomElement>
#include<QDomNodeList>
#include<QXmlStreamReader>
#include<QTextCodec>
#include<QSplashScreen>
#include"v_xmlpaser.h"
#include"V_phone.h"
#include"v_splashdialog.h"
int main(int argc, char *argv[])
{

//    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
//    V_SmsManager man;
//    QDomDocument dom;
//    QString str="<a><li>1111   </li><lk>ccccc</lk></a>   <b>nnn</b>";


//    QString str1="<a>vvvvv</a>   <b>aaaaaa</b>";
//    dom.setContent(str1);
//    QDomElement ele= dom.elementsByTagName("a").item(0).toElement();
//    qDebug()<<ele.nextSiblingElement().text();



//    V_XMLPaser parser;
//    parser.parse(str);


    qDebug()<<V_XMLPaser::ShortMessage("123","127.0.0.1");

    QApplication app(argc,argv);
    QTextCodec::setCodecForCStrings(
                QTextCodec::codecForName("UTF-8"));


    V_Phone phone;

    phone.init();


    V_SplashDialog SplashDialog;
    SplashDialog.setText(QString::fromLocal8Bit("±¾»úºÅÂë")+phone.PhoneNum);
    SplashDialog.exec();
    //phone.turnOn();
    phone.show();


    return app.exec();

}
