#include "v_personmanager.h"

V_PersonManager::V_PersonManager(QObject *parent) :
    QObject(parent)
{
}

void V_PersonManager::addPerson(QString num, QString name,bool isblack)
{
    PhoneNum2Name[num]=name;
    IsBlack[num]=isblack;
}

QString V_PersonManager::getNameByNum(QString num)
{
    QMap<QString,QString>::iterator itr=PhoneNum2Name.find(num);
    if(itr!=PhoneNum2Name.end())
    return itr.value();
    else
    return "";

}

void V_PersonManager::deletePerson(QString Num)
{
    QMap<QString,QString>::iterator itr=PhoneNum2Name.find(Num);
    IsBlack.remove(itr.key());
    if(itr!=PhoneNum2Name.end())
    PhoneNum2Name.erase(itr);

}

void V_PersonManager::setBlack(QString Num)
{
    QMap<QString,int>::iterator itr=IsBlack.find(Num);
    if(itr!=IsBlack.end())
    IsBlack[Num]=1;
}

void V_PersonManager::revBlack(QString Num)
{
    QMap<QString,int>::iterator itr=IsBlack.find(Num);
    if(itr!=IsBlack.end())
    IsBlack[Num]=1-IsBlack[Num];
}

void V_PersonManager::save(QString filename)
{
   QMap<QString,QString>::iterator itr=PhoneNum2Name.begin();
    QFile file(filename);
    file.open(QFile::WriteOnly|QFile::Text);

    file.write("<person>");
    //file<<"<Sms>";
    for(;itr!=PhoneNum2Name.end();itr++)
    {
        file.write("<phonenum>");
        file.write(itr.key().toStdString().c_str());
        file.write("</phonenum>");
        file.write("<name>");
        file.write(itr.value().toStdString().c_str());
        file.write("</name>");
        file.write("<isblack>");
        file.write(QString::number(IsBlack[itr.key()]).toStdString().c_str());
        file.write("</isblack>");

    }
    file.write("</person>");
    file.flush();
    file.close();
}

void V_PersonManager::load(QString filename)
{
    QDomDocument doc;
    QFile file(filename);
    file.open(QFile::ReadOnly|QFile::Text);
    doc.setContent(&file,false);
    QDomNodeList NumberList=doc.elementsByTagName("phonenum");
    QDomNodeList NameList=doc.elementsByTagName("name");
    QDomNodeList IsBlackList=doc.elementsByTagName("isblack");
    for(int i=0;i<NumberList.size();i++)
    {
       PhoneNum2Name.insert(NumberList.at(i).toElement().text()
                            ,NameList.at(i).toElement().text());
       IsBlack.insert(NumberList.at(i).toElement().text(),
                      IsBlackList.at(i).toElement().text().toShort());
    }
}
