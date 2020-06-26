#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QDialog>
#include "server.h"
#include "tcpclientsocket.h"
QT_BEGIN_NAMESPACE
namespace Ui { class TcpServer; }
QT_END_NAMESPACE

class TcpServer : public QDialog
{
    Q_OBJECT

public:
    TcpServer(QWidget *parent = nullptr);
    ~TcpServer();

public slots:
    //接收到server发过来的信号就更新界面的信息
    void updateServer(QString);

private slots:

    void on_startBtn_clicked();

private:
    Ui::TcpServer *ui;
    Server *server;
};
#endif // TCPSERVER_H
