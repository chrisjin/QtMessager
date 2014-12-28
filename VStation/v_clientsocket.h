#ifndef V_CLIENTSOCKET_H
#define V_CLIENTSOCKET_H

#include <QTcpSocket>
#include<QDataStream>
#include<QPushButton>
class V_ClientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit V_ClientSocket(QObject *parent = 0);
    QString Content;
    void writeContent(QString content);
signals:
    
public slots:
    void read()
    {

        char *con=new char[bytesAvailable()+1];
        memset(con,0,bytesAvailable()+1);

        readData(con,bytesAvailable());
        this->Content=con;

        //QPushButton *pushbutton=new QPushButton;
        //pushbutton->setText(Content.trimmed()+"Ser");
        //pushbutton->show();
        write("sssss",8);
    }
};

#endif // V_CLIENTSOCKET_H
