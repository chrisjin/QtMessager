#ifndef V_CONNECTSOCKET_H
#define V_CONNECTSOCKET_H

#include <QTcpSocket>
#include<QPushButton>
#include<QDataStream>
/////////////////////////////////////////////////////////////
////
////
////�Զ����Socket
////
////
/////////////////////////////////////////////////////////////
class V_ConnectSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit V_ConnectSocket(QObject *parent = 0);
    void writeContent(QString content);
signals:
    
public slots:

};

#endif // V_CONNECTSOCKET_H
