#-------------------------------------------------
#
# Project created by QtCreator 2018-07-05T16:01:29
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DCXT
TEMPLATE = app


SOURCES += main.cpp\
    chef.cpp \
    logindialog.cpp \
    menu.cpp \
    order.cpp \
    restmap.cpp

HEADERS  += logindialog.h \
    chef.h \
    menu.h \
    order.h \
    restmap.h

FORMS    += logindialog.ui \
    chef.ui \
    menu.ui \
    order.ui \
    restmap.ui

RESOURCES += \
    img.qrc




