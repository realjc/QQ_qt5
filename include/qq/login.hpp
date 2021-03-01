#ifndef QQ_LOGIN_HPP
#define QQ_LOGIN_HPP

#include <QWidget>
#include <QLabel>
#include <QDir>
#include <QImage>
#include "ui_login.h"

namespace Ui{
    class Login;
}

class Login : public QWidget
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_login_button_clicked();

private:
    Ui::Login *ui;

//    QPropertyAnimation *animation;
//    QByteArray byte_array;
};

#endif