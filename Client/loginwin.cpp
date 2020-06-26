#include "loginwin.h"
#include "ui_loginwin.h"

LoginWin::LoginWin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWin)
{
    ui->setupUi(this);
    str1 = ui->userName->text();
}

LoginWin::~LoginWin()
{
    delete ui;
}


void LoginWin::on_enterBtn_clicked()
{
    TcpClient *tcpclient = new TcpClient(str1);
    tcpclient->show();
    this->close();
}

