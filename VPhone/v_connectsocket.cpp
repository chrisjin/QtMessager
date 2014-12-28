#include "v_connectsocket.h"

V_ConnectSocket::V_ConnectSocket(QObject *parent) :
    QTcpSocket(parent)
{
 //   connect(this,SIGNAL(readyRead()),this,SLOT(readContent()));
    //   connect(this,SIGNAL(connected()),this,SLOT(onConnected()));
}

void V_ConnectSocket::writeContent(QString content)
{

   write(content.toStdString().c_str(),content.toStdString().length());

}
