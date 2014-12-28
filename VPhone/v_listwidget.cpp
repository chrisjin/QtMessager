#include "v_listwidget.h"

V_ListWidget::V_ListWidget(QWidget *parent) :
    QListWidget(parent)
{
    setIconSize(QSize(62,62));
    QFont font;
    font.setPointSize(15);
    setFont(font);
}

void V_ListWidget::addPersonItem(QString num, QString name)
{
    addItem(num+"\n"+name);
    item(count()-1)->setIcon(QIcon("o.bmp"));
   // QImage pix("o.png");
   // pix.scaled(QSize(1,1));
   // item(count()-1)->setBackground(QBrush(pix.scaled(QSize(600,600))));
    //item(count()-1)->setWhatsThis();
}
void V_ListWidget::addMailBoxItem(QString num,QString name,int smsnum)
{
    addItem(num+"("+QString::number(smsnum)+")"+"\n"+name);
    item(count()-1)->setIcon(QIcon("o.bmp"));
}
void V_ListWidget::loadSmsManager(
        V_SmsManager *smsmanager,V_PersonManager *personmanager,bool isrubbish)
{
    clear();
    QMap< QString,QVector<SmsStruct*> >::iterator itr
            =smsmanager->SmsSearchPool.begin();
    QMap<QString,int> Count;
    for(;itr!=smsmanager->SmsSearchPool.end();itr++)
    {
        int co=0;
        for(int i=0;i<itr.value().size();i++)
        {
            if(itr.value()[i]->IsRet==0
                    &&itr.value()[i]->IsRubbish==isrubbish)
            co++;
        }
        Count[itr.key()]=co;
    }
    itr=smsmanager->SmsSearchPool.begin();
    for(;itr!=smsmanager->SmsSearchPool.end();itr++)
    {
        if(Count[itr.key()])
        addMailBoxItem(itr.key(),
                       personmanager->getNameByNum(itr.key()),
                       Count[itr.key()]);
    }

 // setCheck("63140180");
}
void V_ListWidget::loadPersonManager(V_PersonManager *personmanager)
{
    clear();
    QMap<QString,QString>::iterator itr=personmanager->PhoneNum2Name.begin();
    for(;itr!=personmanager->PhoneNum2Name.end();itr++)
    {
        addPersonItem(itr.key(),itr.value());
    }

   // setCheck("63140180");
}

void V_ListWidget::setCheck(QString num)
{
    for(int i=0;i<this->count();i++)
    {
        if(getNumFromMailBox(item(i)->text()).trimmed()==num)
            item(i)->setBackgroundColor(QColor(255,0,0));
    }
}
void V_ListWidget::setUnCheck(QString num)
{
    for(int i=0;i<this->count();i++)
    {
        if(getNumFromMailBox(item(i)->text()).trimmed()==num)
            item(i)->setBackgroundColor(QColor(255,255,255));
    }
}
QString V_ListWidget::getNum(QString fulltext)
{
    QStringList strlist=fulltext.split('\n');
    return strlist[0];
}

QString V_ListWidget::getNumFromMailBox(QString fulltext)
{
    QStringList strlist=fulltext.split('(');
    return strlist[0];
}
