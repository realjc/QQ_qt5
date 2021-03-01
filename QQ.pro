QT       += core gui
QT       += network
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = login
TEMPLATE = app

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += $$PWD/include

SOURCES += \
        src/main.cpp \
        src/login.cpp

FORMS += \
    ui/login.ui

HEADERS += \
    include/qq/login.hpp
