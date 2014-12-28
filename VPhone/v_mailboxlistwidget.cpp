#include "v_mailboxlistwidget.h"

V_MailBoxListWidget::V_MailBoxListWidget(QWidget *parent) :
    QListWidget(parent)
{
    setIconSize(QSize(62,62));
    QFont font;
    font.setPointSize(15);
    setFont(font);
    IsRubbishBin=0;
}
void V_MailBoxListWidget::addMailBoxItem(QString num,QString name,int smsnum)
{
    addItem(num+"("+QString::number(smsnum)+")"+"\n"+name);
    if(!IsRubbishBin)
    item(count()-1)->setIcon(QIcon("icon/gmail.png"));
    else
    item(count()-1)->setIcon(QIcon("icon/rubbish.png"));
}
void V_MailBoxListWidget::loadSmsManager(
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

void V_MailBoxListWidget::setCheck(QString num)
{
    for(int i=0;i<this->count();i++)
    {
        if(getNumFromMailBox(item(i)->text()).trimmed()==num)
            item(i)->setBackgroundColor(QColor(255,0,0));
    }
}
void V_MailBoxListWidget::setUnCheck(QString num)
{
    for(int i=0;i<this->count();i++)
    {
        if(getNumFromMailBox(item(i)->text()).trimmed()==num)
            item(i)->setBackgroundColor(QColor(255,255,255));
    }
}

void V_MailBoxListWidget::setRubbishBin()
{
    IsRubbishBin=1;
}

QString V_MailBoxListWidget::getNumFromMailBox(QString fulltext)
{
    QStringList strlist=fulltext.split('(');
    return strlist[0];
}

void V_MailBoxListWidget::contextMenuEvent(QContextMenuEvent *)
{
    QListWidgetItem *item=itemAt(mapFromGlobal(QCursor::pos()));
    if(item==NULL)return;
    QMenu *menu=new QMenu(this);
    QString con;
    if(IsRubbishBin)
        con="Move To MailBox";
    else
        con="Move To RubbishBin";

    QAction *action=new QAction(con,this);
    connect(action,SIGNAL(triggered()),this,SLOT(onContextMenu()));
    menu->addAction(action);

    QAction *action1=new QAction("Delete",this);
    connect(action1,SIGNAL(triggered()),this,SLOT(onDelete()));
    if(IsRubbishBin)
    menu->addAction(action1);
    menu->exec(QCursor::pos());
}

void V_MailBoxListWidget::onContextMenu()
{
    QListWidgetItem *item=selectedItems()[0];
    takeItem(row(item));
    emit deleteItembyNumSignal(getNumFromMailBox(item->text()));
}

void V_MailBoxListWidget::onDelete()
{
    QListWidgetItem *item=selectedItems()[0];
    if(QMessageBox::information(NULL,"Warn","irreversible,continue?",QMessageBox::Yes|QMessageBox::Cancel)
            ==QMessageBox::Yes)
    {
    takeItem(row(item));
    emit deleteItemIrevbyNumSignal(getNumFromMailBox(item->text()));
    }
}
