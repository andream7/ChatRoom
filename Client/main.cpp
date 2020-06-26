#include "logindig.h"
#include "tcpclient.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString str1;

    LoginDig login;

    login.setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/new/prefix1/alena-aenami-aenami-away-in-silence-art-art-by-alena-aenami.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    login.setPalette(palette);


    if(login.exec() == QDialog::Accepted)
    {
        str1 = login.str1;
        TcpClient w(str1);

        w.setAutoFillBackground(true);
        QPalette palette;
        QPixmap pixmap(":/new/prefix1/alena-aenami19.jpg");
        palette.setBrush(QPalette::Window, QBrush(pixmap));
        w.setPalette(palette);

        w.show();
        return a.exec();
    }
    else{
        return 0;
    }
}
