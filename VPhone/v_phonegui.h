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
////����������
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
    QStackedWidget *StackWidget;//�����棬�����շ����棬�����ϵ�˽����л��ؼ�
    QVBoxLayout *MainLayout;
    QString CurrentNum;


    //////////////////////////////////
    /////������(�ռ��䣬��ϵ�ˣ�������)
    ////////////////////////////////
    QWidget     *StartWnd;
    QPushButton *TurnonBtn;  /////������ť
    QPushButton *ConfigBtn;  //���ð�ť
    QPushButton *TipBtn;     //˵����ť
    QVBoxLayout *VBoxStartLayout;
    QWidget     *PeopleWnd;  //��ϵ�˽���
    QVBoxLayout *VBoxPeopleWndLayout;
    QWidget     *MailBoxWnd; //�ռ������
    QVBoxLayout *VBoxMailBoxWndLayout;
    QWidget     *RubbishWnd; //���������
    QVBoxLayout *VBoxRubbishWndLayout;
    QTabWidget  SwitchTab;   //��ϵ�ˣ��ռ��䣬������������ֱ�Ϊ����Tab
    QVBoxLayout *VBoxLayout;
    V_PersonListWidget *PeopleListWidget; //��ϵ���б�ؼ�
    V_MailBoxListWidget *MailBoxListWidget; //�����б�ؼ�
    V_MailBoxListWidget *RubbishListWidget; //�������б�ؼ�
    //////////////////////////////////
    /////�����շ�����
    ////////////////////////////////

    QWidget     *MessageWnd;
    QVBoxLayout *VBoxMessageWndLayout;
    QPushButton *AddPersonBtn;
    QPushButton *SendBtn;   //���Ͱ�ť
    QPushButton *BackBtn;   //�����ϸ����水ť
    V_TextEdit   *LineEdit; //���������
    V_MessageListWidget *MessageList; //�����б�
    QLabel *RecvorLabel;
    //////////////////////////////////
    /////������ϵ�˽���
    ////////////////////////////////


    QWidget *PersonAddWnd;
    QVBoxLayout *VBoxPersonAddLayout;
    QHBoxLayout *HBoxPersonAddLayout;
    QLineEdit *NameEdit;   //���������
    QLineEdit *PhoneNumEdit;  //�绰���������
    QPushButton *AddFinishedButton; //�����ϵ��
    QPushButton *PersonAddBackBtn;  //�����ϼ�����


    //////////////////////////////////
    /////���ú�˵���Ի���
    ////////////////////////////////
    V_ConfigWidget *ConfigWidget; //���ý���
    V_TipWidget    *TipWidget;    //˵������
    void buildStartUI();    //����������
    void buildSendUI();     //�����շ����Ž���
    void buildPersonAddUI(); //��������ϵ�˽���
    void setBackgroundImage(QString filename);


protected:
    void closeEvent ( QCloseEvent * event );
signals:
    void closeSignal();
    //////////////////////////////////
    /////��������շ�����ʱ����
    ////////////////////////////////
    void enterMessageList();//��������շ������ź�
    //////////////////////////////////
    /////������ϵ��ʱ������V_Phone����
    ////////////////////////////////
    void addPersonSignal(QString a,QString b);//����ϵ���ź�
public slots:
    //////////////////////////////////
    /////������            ��ϵ����Ŀ���ʱ����
    ////////////////////////////////
    void onItemClick(QListWidgetItem * item);
    //////////////////////////////////
    /////������            �ռ�����Ŀ���ʱ����
    ////////////////////////////////
    void onMailBoxCheck(QListWidgetItem * item);
    //////////////////////////////////
    /////����������
    ////////////////////////////////
    void onBackClick();
    //////////////////////////////////
    /////������            ������ϵ�˰�ť�����
    ////////////////////////////////
    void onAddBtnClick();
    //////////////////////////////////
    /////������            ɾ����ϵ�˰�ť�����
    ////////////////////////////////
    void onDelBtnClick();
    //////////////////////////////////
    /////�����ϵ�˽���     OK��ť�����
    ////////////////////////////////
    void onAddFinishedBtnClick();
    //////////////////////////////////
    /////��Ϣ�շ�����       ����ϵ�˰�ť�����
    ////////////////////////////////
    void onPersonAdd();
    //////////////////////////////////
    /////������            ���ð�ť�����
    ////////////////////////////////
    void onConfig();
    //////////////////////////////////
    /////������            ˵����ť�����
    ////////////////////////////////
    void onTip();
    //////////////////////////////////
    /////Obsolete
    ////////////////////////////////
    void onConfigOK();
};

#endif // V_PHONEGUI_H
