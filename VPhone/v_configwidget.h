#ifndef V_CONFIGWIDGET_H
#define V_CONFIGWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include<QHBoxLayout>
#include<QFileDialog>
#include<QLineEdit>
#include<QLabel>
#include<QPushButton>
#include<QUrl>
#include<QMessageBox>
/////////////////////////////////////////////////////////////
////
////
////≈‰÷√ΩÁ√Ê
////
////
/////////////////////////////////////////////////////////////
class V_ConfigWidget : public QWidget
{
    Q_OBJECT
public:
    explicit V_ConfigWidget(QWidget *parent = 0);
    QLabel   *FilterLabel;
    QTextEdit *TextEdit;

    QLabel    *BackgroundLabel;
    QFileDialog *FileDialog;
    QLineEdit *BackgroundLineEdit;
    QPushButton *BrowseBackGroundBtn;

    QPushButton *OkBtn;

    QString BackgroundImagePath;
    QString FilterKeyWords;

    void save();
signals:
    void configOK();
public slots:
    void onBrowseBtn();
    void onOKBtn();
};

#endif // V_CONFIGWIDGET_H
