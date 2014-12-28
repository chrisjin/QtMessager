#include "v_phonetablewidget.h"

V_PhoneTableWidget::V_PhoneTableWidget(QWidget *parent) :
    QTableWidget(parent)
{
    QStringList headerlabels;
    resize(350 ,300);
    headerlabels<<"PhoneNum"<<"IP"<<"STATE";
    setColumnCount(3);
    setHorizontalHeaderLabels(headerlabels);
    setRowCount(1);
    setItem(0,0,new QTableWidgetItem(""));
}

void V_PhoneTableWidget::loadPhoneManager(V_PhoneManager *phonemanager)
{
    int row=phonemanager->PhonePool.size();
    setRowCount(row);
    QMap<QString,QString>::iterator itr=phonemanager->PhonePool.begin();
    for(int i=0;itr!=phonemanager->PhonePool.end();itr++,i++)
    {
        setItem(i,0,new QTableWidgetItem(itr.key()));
        setItem(i,1,new QTableWidgetItem(itr.value()));
        if(phonemanager->PhoneIsOn[itr.key()])
            setItem(i,2,new QTableWidgetItem("ON"));
        else
            setItem(i,2,new QTableWidgetItem("OFF"));
    }
}
