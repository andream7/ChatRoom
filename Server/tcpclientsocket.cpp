#include "tcpclientsocket.h"

TcpClientSocket::TcpClientSocket(QObject *parent) : QTcpSocket(parent)
{
    connect(this,SIGNAL(readyRead()),this,SLOT(dataReceived()));
    connect(this,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
}
void TcpClientSocket::dataReceived()
{
    QByteArray array = readAll();
    QString msg = array;
    emit updateClients(msg);
}

void TcpClientSocket::slotDisconnected()
{
    emit disconnected(this->socketDescriptor());
}
