#include "logindig.h"
#include "ui_logindig.h"
#include <QMessageBox>

LoginDig::LoginDig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDig)
{
    ui->setupUi(this);
}

LoginDig::~LoginDig()
{
    delete ui;
}

void LoginDig::on_enterBtn_clicked()
{
    if(ui->userName->text()=="")
    {
        QMessageBox::information(this,tr("error"),tr("用户名不能为空!"));
        return;
    }
    else{
    str1 = ui->userName->text();
    accept();
    }
}
