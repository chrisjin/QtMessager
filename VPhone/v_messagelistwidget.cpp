#include "v_messagelistwidget.h"

V_MessageListWidget::V_MessageListWidget(QWidget *parent) :
    QListWidget(parent)
{
 //   setFlow();
    setIconSize(QSize(62,62));
    QFont font;
  //  font.setPointSize(15);
    setFont(font);
  //  setWrapping(true);
    //setFlow(QListWidget::);
    AnsIcon="icon/ret4.png";
    RecvIcon="icon/recv2.png";
}

void V_MessageListWidget::loadSms(V_SmsManager *smsmanage,QString phonenum)
{
    //remove()
    clear();

    QVector< SmsStruct* > sms;
    if(smsmanage->SmsSearchPool.find(phonenum)!=smsmanage->SmsSearchPool.end())
    sms=smsmanage->SmsSearchPool[phonenum];
    else
        return;
    for(int i=0;i<sms.size();i++)
    {
        if(sms[i]->IsRubbish)
            continue;
        if(sms[i]&&sms[i]->IsRet)
        {
            addItem(":"+sms[i]->Content);
            item(count()-1)->setIcon(QIcon(AnsIcon));
        }
        else
        {
            addItem(sms[i]->Content);
            item(count()-1)->setIcon(QIcon(RecvIcon));
        }
        QListWidgetItem* listitem=item(count()-1);
        listitem->setTextAlignment(Qt::AlignLeft);
        ListWidgetItem2SmsID[listitem]=sms[i]->ID;
    }
    scrollToBottom();
  //  QModelIndex index;
  //  setIndexWidget(index, new QLineEdit(this));
}

void V_MessageListWidget::contextMenuEvent(QContextMenuEvent *)
{
    QListWidgetItem *item=itemAt(mapFromGlobal(QCursor::pos()));
    if(item==NULL)return;
    QMenu *menu=new QMenu(this);
    QAction *action=new QAction("Move To Rubbishbin",this);
    connect(action,SIGNAL(triggered()),this,SLOT(onContextMenu()));
    menu->addAction(action);
    menu->exec(QCursor::pos());
}

void V_MessageListWidget::onContextMenu()
{
  //  QPushButton *bt=new QPushButton;
  //  bt->show();
    QListWidgetItem *item=selectedItems()[0];
    takeItem(row(item));
    emit deleteItemSignal(ListWidgetItem2SmsID[item]);
    //remove()
}


