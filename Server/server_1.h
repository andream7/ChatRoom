#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include "tcpclientsocket.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    QList<TcpClientSocket*> tcpClientSocketList;

public slots:
    //更新客户端的信息
    void updateClients(QString);
    void slotDisconnected(int);

signals:
    //发送信号给服务端使服务端界面更新信息
     void updateServer(QString);
protected:
     //只要出现一个新的连接，就会自动调用这个函数
    void incomingConnection(qintptr socketDescriptor);
};

#endif // SERVER_H
