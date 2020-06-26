#include "tcpclient.h"
#include "ui_tcpclient.h"
#include <QMessageBox>

TcpClient::TcpClient(QString n,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcpClient)
{
    ui->setupUi(this);
    str1 = n;
    ui->userName->setText(str1);

    ui->sendBtn->setEnabled(false);

    tcpSocket = new QTcpSocket(this);
    //检测链接信号
    connect(tcpSocket,SIGNAL(connected()),this,SLOT(slotConnected()));
    //检测如果断开
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
    //检测如果有新可以读信号
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(dataReceived()));
    //绑定连接的ip和port
    tcpSocket->connectToHost("127.0.0.1",4444);
}

TcpClient::~TcpClient()
{
    delete ui;
}

void TcpClient::on_logoutBtn_clicked()
{
    QString msg="["+str1+"]"+"Leave Chat Room";
    tcpSocket->write(msg.toUtf8().data());
    tcpSocket->disconnectFromHost();
    this->close();

}

void TcpClient::slotConnected()
{
    ui->sendBtn->setEnabled(true);
    QString msg="["+str1+"]"+"Enter Chat Room";
    tcpSocket->write(msg.toUtf8().data());
}

void TcpClient::on_sendBtn_clicked()
{
    if(ui->sendLineEdit->text()=="")
    {
        QMessageBox::information(this,tr("error"),tr("发送内容不能为空!"));
        return ;
    }

    QString msg="["+str1+"]"+ui->sendLineEdit->text();

    tcpSocket->write(msg.toUtf8().data());
    ui->sendLineEdit->clear();
}

void TcpClient::slotDisconnected()
{
    QByteArray array = "服务器已断开连接";
    ui->contentListWidget->addItem(array);
}

void TcpClient::dataReceived()
{
    QByteArray array = tcpSocket->readAll();
    ui->contentListWidget->addItem(array);
}

