#include "v_tipwidget.h"

V_TipWidget::V_TipWidget(QWidget *parent) :
    QWidget(parent)
{
    resize(400,500);
    QFile conffile("backgroundimage");
    conffile.open(QFile::ReadOnly|QFile::Text);
    QPalette pal;
    pal.setBrush(backgroundRole(),QBrush(QPixmap(conffile.readAll())));
    setPalette(pal);


    QFile tipfile("tip.html");
    tipfile.open(QFile::ReadOnly|QFile::Text);

    QTextEdit *TipTextEdit=new QTextEdit;
    TipTextEdit->setReadOnly(1);

    TipTextEdit->setHtml(QString::fromLocal8Bit(tipfile.readAll()));


    QVBoxLayout *VBoxLayout=new QVBoxLayout;
    VBoxLayout->addWidget(TipTextEdit);
    setLayout(VBoxLayout);
}

