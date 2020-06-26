#ifndef LOGINWIN_H
#define LOGINWIN_H

#include <QWidget>
#include "tcpclient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWin; }
QT_END_NAMESPACE

class LoginWin : public QWidget
{
    Q_OBJECT

public:
    LoginWin(QWidget *parent = nullptr);
    ~LoginWin();

    QString str1;

private slots:
    void on_enterBtn_clicked();

private:
    Ui::LoginWin *ui;
};
#endif // LOGINWIN_H
