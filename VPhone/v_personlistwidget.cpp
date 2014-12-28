#include "v_personlistwidget.h"

V_PersonListWidget::V_PersonListWidget(QWidget *parent) :
    QListWidget(parent)
{
    setIconSize(QSize(62,62));
    QFont font;
    font.setPointSize(15);
    setFont(font);
}

void V_PersonListWidget::addPersonItem(QString num, QString name)
{
    addItem(num+"\n"+name);
    item(count()-1)->setIcon(QIcon("icon/Tux.png"));
   // QImage pix("o.png");
   // pix.scaled(QSize(1,1));
   // item(count()-1)->setBackground(QBrush(pix.scaled(QSize(600,600))));
    //item(count()-1)->setWhatsThis();
}

void V_PersonListWidget::loadPersonManager(V_PersonManager *personmanager)
{
    clear();
    QMap<QString,QString>::iterator itr=personmanager->PhoneNum2Name.begin();
    for(;itr!=personmanager->PhoneNum2Name.end();itr++)
    {
        addPersonItem(itr.key(),itr.value());
        if(personmanager->IsBlack[itr.key()])
            setCheck(itr.key());
    }

   // setCheck("63140180");
}

QString V_PersonListWidget::getNum(QString fulltext)
{
    QStringList strlist=fulltext.split('\n');
    return strlist[0];
}

void V_PersonListWidget::setCheck(QString num)
{
    for(int i=0;i<this->count();i++)
    {
        if(getNum(item(i)->text()).trimmed()==num)
        {
            item(i)->setBackgroundColor(QColor(0,0,0));
            item(i)->setTextColor(QColor(255,255,255));
        }
    }
}
void V_PersonListWidget::setUnCheck(QString num)
{
    for(int i=0;i<this->count();i++)
    {
        if(getNum(item(i)->text()).trimmed()==num)
        {
            item(i)->setBackgroundColor(QColor(255,255,255));
            item(i)->setTextColor(QColor(0,0,0));
        }
    }
}

void V_PersonListWidget::contextMenuEvent(QContextMenuEvent *)
{
    QListWidgetItem *item=itemAt(mapFromGlobal(QCursor::pos()));
    if(item==NULL)return;
    QMenu *menu=new QMenu(this);
    QString con;
    QListWidgetItem *selitem=selectedItems()[0];
    QColor color=selitem->backgroundColor();
    color.toRgb();
    if(color.black()<100)
        con="Add to Black";
    else
        con="Add to White";
    QAction *action=new QAction(con,this);
    connect(action,SIGNAL(triggered()),this,SLOT(onContextMenu()));
    QAction *action1=new QAction("Delete",this);
    connect(action1,SIGNAL(triggered()),this,SLOT(onDeletePerson()));

    menu->addAction(action);
    menu->addAction(action1);
    menu->exec(QCursor::pos());
}

void V_PersonListWidget::onContextMenu()
{
  //  QPushButton *bt=new QPushButton;
  //  bt->show();
    QListWidgetItem *item=selectedItems()[0];
    //takeItem(row(item));
    emit setBlackSignal(getNum(item->text()));
    //remove()
}

void V_PersonListWidget::onDeletePerson()
{
    QListWidgetItem *item=selectedItems()[0];
    takeItem(row(item));
    emit deletePerson(getNum(item->text()));
}
