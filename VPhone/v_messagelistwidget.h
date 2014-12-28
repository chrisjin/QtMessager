#ifndef V_MESSAGELISTWIDGET_H
#define V_MESSAGELISTWIDGET_H

#include <QListWidget>
#include <QMenu>
#include <QPushButton>
#include <QLineEdit>
#include <QMap>
#include"v_smsmanager.h"
/////////////////////////////////////////////////////////////
////
////
////短信列表控件
////
////
/////////////////////////////////////////////////////////////
class V_MessageListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit V_MessageListWidget(QWidget *parent = 0);
    void loadSms(V_SmsManager *smsmanage,QString phonenum);
    QMap<QListWidgetItem*,int>  ListWidgetItem2SmsID;
    QString AnsIcon;
    QString RecvIcon;
protected:
    void contextMenuEvent(QContextMenuEvent *);
signals:
    void deleteItemSignal(int ID);
public slots:
    void onContextMenu();
    
};

#endif // V_MESSAGELISTWIDGET_H
