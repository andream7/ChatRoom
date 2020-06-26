#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QObject>
#include <QTcpSocket>

class TcpClientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit TcpClientSocket(QObject *parent = nullptr);

signals:
    //用来告诉tcpserver需要更新界面的显示
    void updateClients(QString);
    //告诉server有客户端断开连接
    void disconnected(int);

protected slots:
    //处理readyRead信号读取数据
    void dataReceived();
    //客户端断开连接触发disconnected信号，这个槽函数用来处理这个信号
    void slotDisconnected();
};

#endif // TCPCLIENTSOCKET_H
