#This project is created by yvbbrjdr

QT += core gui widgets network

TARGET = Instant

TEMPLATE = app

SOURCES += main.cpp \
    logindialog.cpp \
    mainform.cpp \
    tcpsocket.cpp \
    tcpserver.cpp \
    historydialog.cpp

FORMS += logindialog.ui \
    mainform.ui \
    historydialog.ui

HEADERS += logindialog.h \
    mainform.h \
    tcpsocket.h \
    tcpserver.h \
    historydialog.h
