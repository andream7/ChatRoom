#include "tcpserver.h"
#include "ui_tcpserver.h"
TcpServer::TcpServer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TcpServer)
{
    ui->setupUi(this);
}

TcpServer::~TcpServer()
{
    delete ui;
}

void TcpServer::on_startBtn_clicked()
{
    //新建一个server对象
    server = new Server(this);

    connect(server,SIGNAL(updateServer(QString)),this,SLOT(updateServer(QString)));
    //将按钮变成无法按下的状态
    ui->startBtn->setEnabled(false);
}
void TcpServer::updateServer(QString msg)
{
    //将信息显示在ContentListWidget中
    ui->ContentListWidget->addItem(msg);
}
