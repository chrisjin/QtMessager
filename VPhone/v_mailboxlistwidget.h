#ifndef V_MAILBOXLISTWIDGET_H
#define V_MAILBOXLISTWIDGET_H

#include <QListWidget>
#include <QMenu>
#include"v_smsmanager.h"
#include<QMessageBox>
#include"v_personmanager.h"
/////////////////////////////////////////////////////////////
////
////
////收件箱，垃圾箱列表控件
////
////
/////////////////////////////////////////////////////////////
class V_MailBoxListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit V_MailBoxListWidget(QWidget *parent = 0);
    bool IsRubbishBin;
    void loadSmsManager(V_SmsManager *smsmanager, V_PersonManager *personmanager, bool isrubbish=0);
    void addMailBoxItem(QString num, QString name, int smsnum);
    void setCheck(QString num);
    void setUnCheck(QString num);
    void setRubbishBin();
    static QString getNumFromMailBox(QString fulltext);

protected:
    void contextMenuEvent(QContextMenuEvent *);
signals:
    void deleteItembyNumSignal(QString con);
    void deleteItemIrevbyNumSignal(QString con);
public slots:
    void onContextMenu();
    void onDelete();
};

#endif // V_MAILBOXLISTWIDGET_H
