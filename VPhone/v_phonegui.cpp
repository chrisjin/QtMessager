#include "v_phonegui.h"

V_PhoneGUI::V_PhoneGUI(QWidget *parent) :
    QWidget(parent)
{
    QFile conffile("backgroundimage");
    conffile.open(QFile::ReadOnly|QFile::Text);
    QPalette pal;
    pal.setBrush(backgroundRole(),QBrush(QPixmap(conffile.readAll())));
    setPalette(pal);
    conffile.close();

    resize(QSize(350,600));
   // setWindowTitle();

    StackWidget=new QStackedWidget;
    MessageWnd=new QWidget;
    PeopleWnd=new QWidget;
    PersonAddWnd=new QWidget;
    VBoxMessageWndLayout=new QVBoxLayout;
    VBoxPeopleWndLayout=new QVBoxLayout;
    VBoxMailBoxWndLayout=new QVBoxLayout;
    MainLayout=new QVBoxLayout;
    VBoxPersonAddLayout=new QVBoxLayout;
    SendBtn=new QPushButton("Send");
    TurnonBtn=new QPushButton("");
    LineEdit=new V_TextEdit;
    PeopleListWidget=new V_PersonListWidget;
    MailBoxListWidget=new V_MailBoxListWidget;
    BackBtn=new QPushButton("");
    NameEdit=new QLineEdit;
    PhoneNumEdit=new QLineEdit;
    AddFinishedButton=new QPushButton("OK");
    MessageList=new V_MessageListWidget;
    //SwitchTab=new QTabWidget(this);
    MailBoxWnd=new QWidget;
    StartWnd=new QWidget;
    VBoxStartLayout=new QVBoxLayout;
    RecvorLabel=new QLabel("");
    AddPersonBtn=new QPushButton("");
    RubbishWnd=new QWidget;
    VBoxRubbishWndLayout=new QVBoxLayout;
    RubbishListWidget=new V_MailBoxListWidget;
    RubbishListWidget->setRubbishBin();
    PersonAddBackBtn=new QPushButton("");
    ConfigBtn=new QPushButton;
    ConfigWidget=new V_ConfigWidget;
    TipBtn=new QPushButton;
    TipWidget=new V_TipWidget;
  //  TurnonBtn=new QPushButton("ON");
  //  SwitchTab=new QTabWidget;
   // SwitchTab->addTab(MailBoxWnd,"sss");


    LineEdit->setLineWrapColumnOrWidth(10);
    MainLayout->addWidget(StackWidget);

    setLayout(MainLayout);

    buildStartUI();
    buildSendUI();
    buildPersonAddUI();


    StackWidget->setCurrentIndex(0);




    // StackWidget->show();
}

void V_PhoneGUI::buildStartUI()
{

////----------------------------------------------------------


    QPushButton *addpersonbtn=new QPushButton("");
    addpersonbtn->setIcon(QIcon("icon/addperson1.png"));
    addpersonbtn->setIconSize(QSize(64,32));
    connect(addpersonbtn,SIGNAL(clicked()),this,SLOT(onAddBtnClick()));

    QPushButton *deletepersonbtn=new QPushButton("");
    deletepersonbtn->setIcon(QIcon("icon/remove.png"));
    deletepersonbtn->setIconSize(QSize(32,32));
    connect(deletepersonbtn,SIGNAL(clicked()),this,SLOT(onDelBtnClick()));

    // VBoxPeopleWndLayout->addWidget(TurnonBtn);
    QHBoxLayout *hlayout=new QHBoxLayout;
    hlayout->addStretch(40);
    hlayout->addWidget(deletepersonbtn);
    hlayout->addWidget(addpersonbtn);
    VBoxPeopleWndLayout->addLayout(hlayout);
    VBoxPeopleWndLayout->addWidget(PeopleListWidget);
   // VBoxPeopleWndLayout->addWidget(&SwitchTab);
    PeopleWnd->setLayout(VBoxPeopleWndLayout);
    connect(PeopleListWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),
            this,SLOT(onItemClick(QListWidgetItem*)));

////----------------------------------------------------------
    VBoxMailBoxWndLayout->addWidget(MailBoxListWidget);
    connect(MailBoxListWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),
            this,SLOT(onMailBoxCheck(QListWidgetItem*)));

    MailBoxWnd->setLayout(VBoxMailBoxWndLayout);
////----------------------------------------------------------
    VBoxRubbishWndLayout->addWidget(RubbishListWidget);
    RubbishWnd->setLayout(VBoxRubbishWndLayout);
////----------------------------------------------------------



    SwitchTab.setIconSize(QSize(32,32));
    SwitchTab.addTab(MailBoxWnd,QIcon("icon/mailc.png"),"MailBox");
    SwitchTab.addTab(PeopleWnd,QIcon("icon/mac.png"),"Person");
    SwitchTab.addTab(RubbishWnd,QIcon("icon/trush.png"),"RubBin");




    TurnonBtn->setIcon(QIcon("icon/turnon.png"));
    TurnonBtn->setIconSize(QSize(32,32));

    ConfigBtn->setIcon(QIcon("icon/configuration.png"));
    ConfigBtn->setIconSize(QSize(32,32));
    connect(ConfigBtn,SIGNAL(clicked()),this,SLOT(onConfig()));
    TipBtn->setIcon(QIcon("icon/alert.png"));
    TipBtn->setIconSize(QSize(32,32));
    connect(TipBtn,SIGNAL(clicked()),this,SLOT(onTip()));
    QHBoxLayout* HLayout=new QHBoxLayout;
    HLayout->addStretch(40);
    HLayout->addWidget(TipBtn);
    HLayout->addWidget(ConfigBtn);
    HLayout->addWidget(TurnonBtn);

    VBoxStartLayout->addLayout(HLayout,40);
   // TurnonBtn->move(QPoint(0,0));
    VBoxStartLayout->addWidget(&SwitchTab);
    StartWnd->setLayout(VBoxStartLayout);
    StackWidget->addWidget(StartWnd);
}

void V_PhoneGUI::buildSendUI()
{
    RecvorLabel->setStyleSheet("font-size:30px;color:yellow;\
                               font:bold;\
                               border-style:inset;\
                               border-width:2px;border-color:#339;\
                               background-color:gray");

    BackBtn->setIcon(QIcon("icon/left.png"));
    BackBtn->setIconSize(QSize(32,32));
    AddPersonBtn->setIcon(QIcon("icon/addperson1.png"));
    SendBtn->setIcon(QIcon("icon/maila.png"));
    SendBtn->setIconSize(QSize(16,16));
    AddPersonBtn->setIconSize(QSize(64,32));
    QHBoxLayout *Hboxlayout=new QHBoxLayout;
    Hboxlayout->addStretch(40);
    Hboxlayout->addWidget(BackBtn);
    VBoxMessageWndLayout->addLayout(Hboxlayout);

    VBoxMessageWndLayout->addWidget(MessageList,50);
    QHBoxLayout *Hboxlayout1=new QHBoxLayout;
    Hboxlayout1->addWidget(RecvorLabel,40);
    Hboxlayout1->addWidget(AddPersonBtn);
    VBoxMessageWndLayout->addLayout(Hboxlayout1);

    VBoxMessageWndLayout->addWidget(LineEdit,20);

    QHBoxLayout *Hboxlayout2=new QHBoxLayout;
    Hboxlayout2->addWidget(SendBtn,40);
   // Hboxlayout2->addWidget(BackBtn);

    VBoxMessageWndLayout->addLayout(Hboxlayout2);
    MessageWnd->setLayout(VBoxMessageWndLayout);
    connect(BackBtn,SIGNAL(clicked()),this,SLOT(onBackClick()));
    connect(AddPersonBtn,SIGNAL(clicked()),this,SLOT(onPersonAdd()));
    StackWidget->addWidget(MessageWnd);
}

void V_PhoneGUI::buildPersonAddUI()
{
    HBoxPersonAddLayout=new QHBoxLayout;
    QLabel *label=new QLabel("Name    :",this);
    label->setStyleSheet("font-size:10px;color:yellow;\
                                   border-style:inset;\
                                   border-width:2px;border-color:#339;\
                                   background-color:gray");
    PersonAddBackBtn->setIcon(QIcon("icon/left.png"));
    PersonAddBackBtn->setIconSize(QSize(32,32));
    QHBoxLayout *hlayout=new QHBoxLayout;
    hlayout->addStretch(40);
    hlayout->addWidget(PersonAddBackBtn);
    VBoxPersonAddLayout->addLayout(hlayout);

    HBoxPersonAddLayout->addWidget(label);
    HBoxPersonAddLayout->addWidget(NameEdit);
    VBoxPersonAddLayout->addLayout(HBoxPersonAddLayout);


    HBoxPersonAddLayout=new QHBoxLayout;
    label=new QLabel("PhoneNum:");
    label->setStyleSheet("font-size:10px;color:yellow;\
                                   border-style:inset;\
                                   border-width:2px;border-color:#339;\
                                   background-color:gray");
    HBoxPersonAddLayout->addWidget(label);
    HBoxPersonAddLayout->addWidget(PhoneNumEdit);
    QRegExp reg("^[0-9]*$");
    QValidator *regvalidator=new QRegExpValidator(reg,this);
    PhoneNumEdit->setValidator(regvalidator);
    VBoxPersonAddLayout->addLayout(HBoxPersonAddLayout);



    QHBoxLayout *Hboxlayout=new QHBoxLayout;
    Hboxlayout->addWidget(AddFinishedButton,40);
    //Hboxlayout->addWidget(PersonAddBackBtn);
    connect(PersonAddBackBtn,SIGNAL(clicked()),this,SLOT(onBackClick()));
    VBoxPersonAddLayout->addLayout(Hboxlayout);
    connect(AddFinishedButton,SIGNAL(clicked()),this,SLOT(onAddFinishedBtnClick()));

    VBoxPersonAddLayout->addStretch(100);


    PersonAddWnd->setLayout(VBoxPersonAddLayout);
    StackWidget->addWidget(PersonAddWnd);
}

void V_PhoneGUI::setBackgroundImage(QString filename)
{
    QPalette pal;
    pal.setBrush(backgroundRole(),QBrush(QPixmap(filename)));
    setPalette(pal);
}

void V_PhoneGUI::closeEvent(QCloseEvent *event)
{
    emit closeSignal();
   // QTabWidget hhh;
}

void V_PhoneGUI::onItemClick(QListWidgetItem *item)
{
    StackWidget->setCurrentIndex(1);

    CurrentNum=V_ListWidget::getNum(item->text().trimmed());
    emit enterMessageList();
    RecvorLabel->setText(QString("To:")+CurrentNum);
}

void V_PhoneGUI::onMailBoxCheck(QListWidgetItem *item)
{
    StackWidget->setCurrentIndex(1);
    CurrentNum=V_ListWidget::getNumFromMailBox(item->text().trimmed());
    emit enterMessageList();
    RecvorLabel->setText(QString("To:")+CurrentNum);

}

void V_PhoneGUI::onBackClick()
{
    StackWidget->setCurrentIndex(0);
   // new QTabWidget;
}

void V_PhoneGUI::onAddBtnClick()
{
    StackWidget->setCurrentIndex(2);
}

void V_PhoneGUI::onDelBtnClick()
{
    if(QMessageBox::Yes==QMessageBox::information(0,"Warn",
                             "Sure to Delete",
                             QMessageBox::Yes|QMessageBox::Cancel)
            )
    PeopleListWidget->onDeletePerson();
}

void V_PhoneGUI::onAddFinishedBtnClick()
{

    PeopleListWidget->addPersonItem(PhoneNumEdit->text().trimmed()
                              ,NameEdit->text().trimmed());
    StackWidget->setCurrentIndex(0);
    emit addPersonSignal(PhoneNumEdit->text().trimmed(),NameEdit->text().trimmed());
}

void V_PhoneGUI::onPersonAdd()
{
    StackWidget->setCurrentIndex(2);
    PhoneNumEdit->setText(CurrentNum);
}

void V_PhoneGUI::onConfig()
{
    connect(ConfigWidget,SIGNAL(configOK()),
            this,SLOT(onConfigOK()));
    ConfigWidget->show();

}
void V_PhoneGUI::onTip()
{
    TipWidget->show();

}
void V_PhoneGUI::onConfigOK()
{
   // QPushButton *bt=new QPushButton;
   // bt->show();
   // setBackgroundImage(ConfigWidget->BackgroundImagePath);
}


