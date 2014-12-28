#include "v_splashdialog.h"

V_SplashDialog::V_SplashDialog(QWidget *parent) :
    QDialog(parent)
{
    resize(200,100);
    QFile conffile("backgroundimage");
    conffile.open(QFile::ReadOnly|QFile::Text);
    QPalette pal;
    pal.setBrush(backgroundRole(),QBrush(QPixmap(conffile.readAll())));
    setPalette(pal);
    conffile.close();

    TextEdit=new QTextEdit;
    QPalette texteditpal=TextEdit->palette();
    texteditpal.setBrush(QPalette::Base,QBrush(QPixmap("./icon/slide.png")));
    TextEdit->setReadOnly(1);
    TextEdit->setPalette(texteditpal);
    OKBtn=new QPushButton("OK");
    connect(OKBtn,SIGNAL(clicked()),SLOT(onOK()));
    QHBoxLayout *hboxlayout=new QHBoxLayout;
    hboxlayout->addStretch(1);
    hboxlayout->addWidget(OKBtn);
    hboxlayout->addStretch(1);

    QVBoxLayout *vboxlayout=new QVBoxLayout;
    vboxlayout->addWidget(TextEdit);
    vboxlayout->addLayout(hboxlayout);

    setLayout(vboxlayout);

}

void V_SplashDialog::onOK()
{
   done(0);
}
void V_SplashDialog::setText(QString con)
{
    TextEdit->setHtml(QString("<center><h3>")+con+"</h3></center>");
}
