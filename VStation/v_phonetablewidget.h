#ifndef V_PHONETABLEWIDGET_H
#define V_PHONETABLEWIDGET_H

#include <QTableWidget>
#include"v_phonemanager.h"
class V_PhoneTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    explicit V_PhoneTableWidget(QWidget *parent = 0);
    void loadPhoneManager(V_PhoneManager *phonemanager);
signals:
    
public slots:
    
};

#endif // V_PHONETABLEWIDGET_H
