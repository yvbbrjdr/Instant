#This project is created by yvbbrjdr

QT += core gui widgets network

TARGET = Instant

TEMPLATE = app

SOURCES += main.cpp \
    logindialog.cpp \
    mainform.cpp \
    tcpsocket.cpp \
    tcpserver.cpp

FORMS += logindialog.ui \
    mainform.ui

HEADERS += logindialog.h \
    mainform.h \
    tcpsocket.h \
    tcpserver.h
