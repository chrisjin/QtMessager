#include "v_clientsocket.h"

V_ClientSocket::V_ClientSocket(QObject *parent) :
    QTcpSocket(parent)
{
    // connect(this,SIGNAL(readyRead()),this,SLOT(read()));
}

void V_ClientSocket::writeContent(QString content)
{
     write(content.toStdString().c_str(),
           content.toStdString().length());
}
