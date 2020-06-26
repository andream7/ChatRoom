#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include "logindig.h"
#include <QTcpSocket>

namespace Ui {
class TcpClient;
}

class TcpClient : public QWidget
{
    Q_OBJECT

public:
    explicit TcpClient(QString n,QWidget *parent = nullptr);
    ~TcpClient();

    LoginDig m1;

public slots:
    //用来处理连接成功的信号
    void slotConnected();
    //用来处理离开服务器断开的信号
    void slotDisconnected();
    //接收服务器传过来的信息
    void dataReceived();

private slots:
    void on_logoutBtn_clicked();

    void on_sendBtn_clicked();

    void on_contentListWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::TcpClient *ui;

    QString str1;

    QTcpSocket *tcpSocket;
};

#endif // TCPCLIENT_H
