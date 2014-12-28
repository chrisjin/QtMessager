#ifndef V_LISTWIDGET_H
#define V_LISTWIDGET_H

#include <QListWidget>
#include"v_smsmanager.h"
#include"v_personmanager.h"
/////////////////////////////////////////////////////////////
////
////
////Obsolete
////
////
/////////////////////////////////////////////////////////////
class V_ListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit V_ListWidget(QWidget *parent = 0);
    void addPersonItem(QString num,QString name="");
    void addMailBoxItem(QString num,QString name,int smsnum);
    static QString getNum(QString fulltext);
    static QString getNumFromMailBox(QString fulltext);


    void loadSmsManager(V_SmsManager *smsmanager,V_PersonManager *personmanager,bool isrubbish=0);
    void loadPersonManager(V_PersonManager *personmanager);

    void setCheck(QString num);
    void setUnCheck(QString num);
signals:
    
public slots:
    
};

#endif // V_LISTWIDGET_H
