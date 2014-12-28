#include "v_smsmanager.h"
#include<QPushButton>
V_SmsManager::V_SmsManager(QObject *parent) :
    QObject(parent)
{
    SmsID=0;
}

void V_SmsManager::addSms(SmsStruct* Sms)
{
    //QPushButton *bt=new QPushButton("add");
   // bt->show();
    SmsID++;
    Sms->ID=SmsID;
    SmsPool.push_back(Sms);
    SmsSearchPool[Sms->PhoneNum].push_back(Sms);
}

bool V_SmsManager::deleteByNum(QString Num)
{
   QVector<SmsStruct*>::iterator Sms_itr=SmsPool.begin();
   for(;Sms_itr!=SmsPool.end();Sms_itr++)
   {
      if((*Sms_itr)->PhoneNum==Num)
          SmsPool.erase(Sms_itr);
   }
   return SmsSearchPool.remove(Num);
}


bool V_SmsManager::removeByNumCon(QString num, QString con)
{
    for(int i=0;i<SmsPool.size();i++)
    {
        if(SmsPool[i]->IsRubbish==1)
            continue;
        if(SmsPool[i]->PhoneNum==num&&SmsPool[i]->Content==con)
        {

            SmsPool[i]->IsRubbish=1;
            return 1;
        }
    }
    return 1;
}

bool V_SmsManager::removeByNum(QString Num)
{
    for(int i=0;i<SmsPool.size();i++)
    {
        if(SmsPool[i]->PhoneNum==Num)
        {

            SmsPool[i]->IsRubbish=1;

        }
    }
    return 1;
}

bool V_SmsManager::removeByID(int  ID)
{
    for(int i=0;i<SmsPool.size();i++)
    {
        if(SmsPool[i]->ID==ID)
        {

            SmsPool[i]->IsRubbish=1;

        }
    }
    return 1;
}

bool V_SmsManager::recoverByNum(QString Num)
{
    for(int i=0;i<SmsPool.size();i++)
    {
        if(SmsPool[i]->PhoneNum==Num)
        {

            SmsPool[i]->IsRubbish=0;

        }
    }
    return 1;
}

bool V_SmsManager::deleteByID(int ID)
{
   QVector<SmsStruct*>::iterator Sms_itr=SmsPool.begin();
   QString Num;
   for(;Sms_itr!=SmsPool.end();Sms_itr++)
   {
      if((*Sms_itr)->ID==ID)
      {
          Num=(*Sms_itr)->PhoneNum;
          SmsPool.erase(Sms_itr);
      }
   }
   QMap<QString,QVector<SmsStruct*> >::iterator SmsSearch_itr=SmsSearchPool.find(Num);
   Sms_itr=SmsSearch_itr.value().begin();
   for(;Sms_itr!=SmsSearch_itr.value().end();Sms_itr++)
   {
       if((*Sms_itr)->ID==ID)
       {
           SmsSearch_itr.value().erase(Sms_itr);
       }

   }
   if(SmsSearch_itr.value().size()==0)
   {
       SmsSearchPool.remove(Num);
   }
   return 0;

}

bool V_SmsManager::deleteRubByNum(QString num)
{
    for(int i=0;i<SmsPool.size();i++)
    {
        if(SmsPool[i]->PhoneNum==num&&SmsPool[i]->IsRubbish==1)
        {

            SmsPool[i]->IsDelete=1;

        }
    }

   return 1;

}

bool V_SmsManager::deleteAllRubbish()
{
   QVector<SmsStruct*>::iterator Sms_itr=SmsPool.begin();
   QString Num;
   for(;Sms_itr!=SmsPool.end();Sms_itr++)
   {
      if((*Sms_itr)->IsRubbish==1)
      {
          Num=(*Sms_itr)->PhoneNum;
          SmsPool.erase(Sms_itr);
      }
   }
   QMap<QString,QVector<SmsStruct*> >::iterator SmsSearch_itr=SmsSearchPool.find(Num);
   Sms_itr=SmsSearch_itr.value().begin();
   for(;Sms_itr!=SmsSearch_itr.value().end();Sms_itr++)
   {
       if((*Sms_itr)->IsRubbish==1)
       {
           SmsSearch_itr.value().erase(Sms_itr);
       }

   }
   if(SmsSearch_itr.value().size()==0)
   {
       SmsSearchPool.remove(Num);
   }
   return 0;

}

void V_SmsManager::deleteAll()
{
   SmsPool.clear();
   SmsSearchPool.clear();
}

void V_SmsManager::save(QString filename)
{
   //QVector<SmsStruct*>::iterator Sms_itr=SmsPool.begin();
   QFile file(filename);
   file.open(QFile::WriteOnly|QFile::Text);

   file.write("<Sms>");
   //file<<"<Sms>";
   for(int i=0;i<SmsPool.size();i++)
   {
       if(SmsPool[i]->IsDelete)
           continue;
       file.write("<Number>");
       file.write(SmsPool[i]->PhoneNum.toStdString().c_str());
       file.write("</Number>");
       file.write("<content>");
       file.write(SmsPool[i]->Content.toStdString().c_str());
       file.write("</content>");
       file.write("<isret>");
       file.write(QString::number(SmsPool[i]->IsRet).toStdString().c_str());
       file.write("</isret>");
       file.write("<isrub>");
       file.write(QString::number(SmsPool[i]->IsRubbish).toStdString().c_str());
       file.write("</isrub>");
   }
   file.write("</Sms>");
   file.flush();
   file.close();
  // file<<"</Sms>";
}

void V_SmsManager::load(QString filename)
{
    QDomDocument doc;
    QFile file(filename);
    file.open(QFile::ReadOnly|QFile::Text);
    doc.setContent(&file,false);
    QDomNodeList NumberList=doc.elementsByTagName("Number");
    QDomNodeList ContentList=doc.elementsByTagName("content");
    QDomNodeList IsRetList=doc.elementsByTagName("isret");
    QDomNodeList IsRubList=doc.elementsByTagName("isrub");
    SmsStruct *smsstruct;
    for(int i=0;i<NumberList.size();i++)
    {

        smsstruct=new SmsStruct;
        smsstruct->PhoneNum=NumberList.at(i).toElement().text();
        smsstruct->Content=ContentList.at(i).toElement().text();
        smsstruct->IsRet=IsRetList.at(i).toElement().text().toShort();
        smsstruct->IsRubbish=IsRubList.at(i).toElement().text().toShort();
        addSms(smsstruct);

    }


}
