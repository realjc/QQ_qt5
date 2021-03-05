QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
LIBS     += -std=c++11 -lmysqlpp -lmysqlclient
TARGET = login
TEMPLATE = app


DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += $$PWD/include

SOURCES += \
        src/main.cpp \
        src/login.cpp

FORMS += \
    ui/login.ui

HEADERS += \
    include/qq/login.hpp
    include/qq/setting.hpp
