#ifndef V_SPLASHDIALOG_H
#define V_SPLASHDIALOG_H

#include <QDialog>
#include<QFile>
#include<QTextEdit>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QPushButton>
/////////////////////////////////////////////////////////////
////
////
////程序启动前弹出的说明对话框
////
////
/////////////////////////////////////////////////////////////
class V_SplashDialog : public QDialog
{
    Q_OBJECT
public:
    explicit V_SplashDialog(QWidget *parent = 0);
    QTextEdit *TextEdit;
    QPushButton *OKBtn;
    void setText(QString con);
signals:
    
public slots:
    void onOK();
};

#endif // V_SPLASHDIALOG_H
