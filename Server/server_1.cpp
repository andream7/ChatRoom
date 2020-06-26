#include "server.h"

Server::Server(QObject *parent) : QTcpServer(parent)
{
    listen(QHostAddress::Any,4444);
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    //只要有新的连接就生成一个新的通信套接字
    TcpClientSocket *tcpClientSocket=new TcpClientSocket(this);

    //将新创建的通信套接字描述符指定为参数socketDescriptor
    tcpClientSocket->setSocketDescriptor(socketDescriptor);

    //接收tcpclientsocket发送过来的更新界面的信号
    connect(tcpClientSocket,SIGNAL(updateClients(QString)),this,SLOT(updateClients(QString)));
    connect(tcpClientSocket,SIGNAL(disconnected(int)),this,SLOT(slotDisconnected(int)));

    //将这个套接字加入客户端套接字列表中
    tcpClientSocketList.append(tcpClientSocket);

}

void Server::updateClients(QString msg)
{
    //将这个信号发送给服务端界面
    emit updateServer(msg);
    //将收到的信息发送给每个客户端,从套接字列表中找到需要接收的套接字
    for(int i=0;i<tcpClientSocketList.count();i++)
    {
        QTcpSocket *item = tcpClientSocketList.at(i);
        item->write(msg.toUtf8().data());
    }
}
//如果有客户端断开连接， 就将列表中的套接字删除
void Server::slotDisconnected(int descriptor)
{
    for(int i=0;i<tcpClientSocketList.count();i++)
    {
        QTcpSocket *item = tcpClientSocketList.at(i);
        if(item->socketDescriptor()==descriptor)
        {
            tcpClientSocketList.removeAt(i);
            return;
        }
    }
    return;
}
