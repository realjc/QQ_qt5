#ifndef QQ_LOGIN_HPP
#define QQ_LOGIN_HPP

#include <QWidget>
#include <QLabel>
#include <QDir>
#include <QImage>
#include <bits/stdc++.h>

#include "ui_login.h"
#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
using namespace std;
using namespace mysqlpp;

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
    void connMysql();

private:
    Ui::Login *ui;
    Connection *mysql_conn_;
//    QPropertyAnimation *animation;
//    QByteArray byte_array;
};

#endif