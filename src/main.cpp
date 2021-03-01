#include <QApplication>
//#include "qq/form.h"
#include "qq/login.hpp"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Login login;
    login.show();
    return app.exec();
}
