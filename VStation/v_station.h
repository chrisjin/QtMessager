#ifndef V_STATION_H
#define V_STATION_H

#include <QObject>
#include <QTcpServer>
#include <QWidget>
#include<QVBoxLayout>
#include"v_xmlparser.h"
#include"v_clientsocket.h"
#include"v_phonemanager.h"
#include"v_phonetablewidget.h"
class V_Station : public QTcpServer
{
    Q_OBJECT
public:
    explicit V_Station(QObject *parent = 0);
    V_PhoneManager PhoneManager;
    V_PhoneTableWidget PhoneTableWidget;
    void run();

    //V_ServerSocket ServerSocket;
    void incomingConnection(int sockid);

signals:
    
public slots:
    void onReadyRead();
    void onDisconnected();
    void onSocketError(QAbstractSocket::SocketError err);
};

#endif // V_STATION_H
