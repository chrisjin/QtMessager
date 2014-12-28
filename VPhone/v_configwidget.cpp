#include "v_configwidget.h"

V_ConfigWidget::V_ConfigWidget(QWidget *parent) :
    QWidget(parent)
{
    resize(500,200);
    QFile conffile("backgroundimage");
    conffile.open(QFile::ReadOnly|QFile::Text);
    QPalette pal;
    pal.setBrush(backgroundRole(),QBrush(QPixmap(conffile.readAll())));
    setPalette(pal);
    TextEdit=new QTextEdit(this);
    BackgroundLineEdit=new QLineEdit(this);
    FilterLabel=new QLabel    ("Filter Key Words",this);
    BackgroundLabel=new QLabel("BackGround Image",this);
    BrowseBackGroundBtn=new QPushButton("...",this);
    OkBtn=new QPushButton("OK");
    FileDialog=new QFileDialog;
    FilterLabel->setStyleSheet("font-size:10px;color:yellow;\
                               font:bold;\
                               border-style:inset;\
                               border-width:2px;border-color:#339;\
                               background-color:gray");
    BackgroundLabel->setStyleSheet("font-size:10px;color:yellow;\
                                   font:bold;\
                                   border-style:inset;\
                                   border-width:2px;border-color:#339;\
                                   background-color:gray");
    ////////////////////////


    QFile conffile1("backgroundimage");
    conffile1.open(QFile::ReadOnly|QFile::Text);
    QFile conffile2("key.txt");
    conffile2.open(QFile::ReadOnly|QFile::Text);

    BackgroundLineEdit->setText(conffile1.readAll());
    TextEdit->setText(conffile2.readAll());
    conffile1.close();
    conffile2.close();


    QHBoxLayout *Hlayout1=new QHBoxLayout;
    Hlayout1->addWidget(FilterLabel);
    Hlayout1->addWidget(TextEdit);

    QHBoxLayout *Hlayout2=new QHBoxLayout;
    Hlayout2->addWidget(BackgroundLabel);
    Hlayout2->addWidget(BackgroundLineEdit,9);
    Hlayout2->addWidget(BrowseBackGroundBtn,1);
    connect(BrowseBackGroundBtn,SIGNAL(clicked()),
            this,SLOT(onBrowseBtn()));

    QHBoxLayout *Hlayout3=new QHBoxLayout;
    Hlayout3->addStretch(30);
    Hlayout3->addWidget(OkBtn);
    connect(OkBtn,SIGNAL(clicked()),
            this,SLOT(onOKBtn()));

    QVBoxLayout *mainlayout=new QVBoxLayout;
    mainlayout->addLayout(Hlayout1);
    mainlayout->addLayout(Hlayout2);
    mainlayout->addLayout(Hlayout3);


    setLayout(mainlayout);
}

void V_ConfigWidget::save()
{
    QFile file("backgroundimage");
    file.open(QFile::WriteOnly|QFile::Text);
    file.write(BackgroundImagePath.toStdString().c_str());
    file.flush();
    file.close();

    QFile file1("key.txt");
    file1.open(QFile::WriteOnly|QFile::Text);
    file1.write(FilterKeyWords.toStdString().c_str());
    file1.flush();
    file1.close();
}

void V_ConfigWidget::onBrowseBtn()
{
   QString path=QFileDialog::getOpenFileName() ;
   BackgroundLineEdit->setText(path);
   BackgroundImagePath=path;

   // FileDialog->setAcceptMode();
}

void V_ConfigWidget::onOKBtn()
{
   BackgroundImagePath=BackgroundLineEdit->text();
   FilterKeyWords=TextEdit->toPlainText();
   save();
   hide();
   QMessageBox::information(0,"Warn",
                            "The configuration will be effective after restart",
                            QMessageBox::Yes);
   emit configOK();
}
