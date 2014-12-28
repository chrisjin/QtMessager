#ifndef V_CONNECTSOCKET_H
#define V_CONNECTSOCKET_H

#include <QTcpSocket>
#include<QPushButton>
#include<QDataStream>
/////////////////////////////////////////////////////////////
////
////
////自定义的Socket
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
