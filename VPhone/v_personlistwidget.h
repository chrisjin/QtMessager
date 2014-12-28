#ifndef V_PERSONLISTWIDGET_H
#define V_PERSONLISTWIDGET_H

#include <QListWidget>
#include"v_personmanager.h"
#include<QMenu>
#include<QPushButton>
/////////////////////////////////////////////////////////////
////
////
////联系人列表控件
////
////
/////////////////////////////////////////////////////////////
class V_PersonListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit V_PersonListWidget(QWidget *parent = 0);
    
    void addPersonItem(QString num, QString name);
    void loadPersonManager(V_PersonManager *personmanager);
    static QString getNum(QString fulltext);
    void setCheck(QString num);
    void setUnCheck(QString num);


protected:
    void contextMenuEvent(QContextMenuEvent *);
signals:
    void setBlackSignal(QString);
    void deletePerson(QString);
public slots:
    void onContextMenu();
    void onDeletePerson();
    
};

#endif // V_PERSONLISTWIDGET_H
