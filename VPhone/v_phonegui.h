#ifndef V_PHONEGUI_H
#define V_PHONEGUI_H

#include <QWidget>
#include <QPushButton>
#include<QGridLayout>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QStackedWidget>
#include<QListWidget>
#include<QLabel>
#include<QTabWidget>
#include<QTextEdit>
#include"v_listwidget.h"
#include"v_textedit.h"
#include"v_messagelistwidget.h"
#include"v_mailboxlistwidget.h"
#include"v_personlistwidget.h"
#include"v_configwidget.h"
#include"v_tipwidget.h"
/////////////////////////////////////////////////////////////
////
////
////程序主界面
////
////
/////////////////////////////////////////////////////////////
class V_PhoneGUI : public QWidget
{
    Q_OBJECT
public:
    explicit V_PhoneGUI(QWidget *parent = 0);

    ////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////
    QStackedWidget *StackWidget;//主界面，短信收发界面，添加联系人界面切换控件
    QVBoxLayout *MainLayout;
    QString CurrentNum;


    //////////////////////////////////
    /////主界面(收件箱，联系人，垃圾箱)
    ////////////////////////////////
    QWidget     *StartWnd;
    QPushButton *TurnonBtn;  /////开机按钮
    QPushButton *ConfigBtn;  //配置按钮
    QPushButton *TipBtn;     //说明按钮
    QVBoxLayout *VBoxStartLayout;
    QWidget     *PeopleWnd;  //联系人界面
    QVBoxLayout *VBoxPeopleWndLayout;
    QWidget     *MailBoxWnd; //收件箱界面
    QVBoxLayout *VBoxMailBoxWndLayout;
    QWidget     *RubbishWnd; //垃圾箱界面
    QVBoxLayout *VBoxRubbishWndLayout;
    QTabWidget  SwitchTab;   //联系人，收件箱，垃圾箱三界面分别为三个Tab
    QVBoxLayout *VBoxLayout;
    V_PersonListWidget *PeopleListWidget; //联系人列表控件
    V_MailBoxListWidget *MailBoxListWidget; //信箱列表控件
    V_MailBoxListWidget *RubbishListWidget; //垃圾箱列表控件
    //////////////////////////////////
    /////短信收发界面
    ////////////////////////////////

    QWidget     *MessageWnd;
    QVBoxLayout *VBoxMessageWndLayout;
    QPushButton *AddPersonBtn;
    QPushButton *SendBtn;   //发送按钮
    QPushButton *BackBtn;   //返回上个界面按钮
    V_TextEdit   *LineEdit; //短信输入框
    V_MessageListWidget *MessageList; //短信列表
    QLabel *RecvorLabel;
    //////////////////////////////////
    /////增加联系人界面
    ////////////////////////////////


    QWidget *PersonAddWnd;
    QVBoxLayout *VBoxPersonAddLayout;
    QHBoxLayout *HBoxPersonAddLayout;
    QLineEdit *NameEdit;   //姓名输入框
    QLineEdit *PhoneNumEdit;  //电话号码输入框
    QPushButton *AddFinishedButton; //添加联系人
    QPushButton *PersonAddBackBtn;  //返回上级界面


    //////////////////////////////////
    /////配置和说明对话框
    ////////////////////////////////
    V_ConfigWidget *ConfigWidget; //配置界面
    V_TipWidget    *TipWidget;    //说明界面
    void buildStartUI();    //构建主界面
    void buildSendUI();     //构建收发短信界面
    void buildPersonAddUI(); //构建加联系人界面
    void setBackgroundImage(QString filename);


protected:
    void closeEvent ( QCloseEvent * event );
signals:
    void closeSignal();
    //////////////////////////////////
    /////进入短信收发界面时发出
    ////////////////////////////////
    void enterMessageList();//进入短信收发界面信号
    //////////////////////////////////
    /////增加联系人时发出跟V_Phone交互
    ////////////////////////////////
    void addPersonSignal(QString a,QString b);//加联系人信号
public slots:
    //////////////////////////////////
    /////主界面            联系人条目点击时调用
    ////////////////////////////////
    void onItemClick(QListWidgetItem * item);
    //////////////////////////////////
    /////主界面            收件箱条目点击时调用
    ////////////////////////////////
    void onMailBoxCheck(QListWidgetItem * item);
    //////////////////////////////////
    /////返回主界面
    ////////////////////////////////
    void onBackClick();
    //////////////////////////////////
    /////主界面            增加联系人按钮被点击
    ////////////////////////////////
    void onAddBtnClick();
    //////////////////////////////////
    /////主界面            删除联系人按钮被点击
    ////////////////////////////////
    void onDelBtnClick();
    //////////////////////////////////
    /////添加联系人界面     OK按钮被点击
    ////////////////////////////////
    void onAddFinishedBtnClick();
    //////////////////////////////////
    /////短息收发界面       加联系人按钮被点击
    ////////////////////////////////
    void onPersonAdd();
    //////////////////////////////////
    /////主界面            配置按钮被点击
    ////////////////////////////////
    void onConfig();
    //////////////////////////////////
    /////主界面            说明按钮被点击
    ////////////////////////////////
    void onTip();
    //////////////////////////////////
    /////Obsolete
    ////////////////////////////////
    void onConfigOK();
};

#endif // V_PHONEGUI_H
