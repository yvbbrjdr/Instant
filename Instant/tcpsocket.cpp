#include "tcpsocket.h"

TcpSocket::TcpSocket(QObject *parent):QTcpSocket(parent) {
    connect(this,SIGNAL(SendData(QVariantMap)),this,SLOT(SendDataSlot(QVariantMap)));
    connect(this,SIGNAL(readyRead()),this,SLOT(RecvDataSlot()));
}

void TcpSocket::SendDataSlot(const QVariantMap &qvm) {
    write(QJsonDocument::fromVariant(qvm).toJson()+char(23));
}

void TcpSocket::RecvDataSlot() {
    buffer+=readAll();
    int p;
    while ((p=buffer.indexOf(23))!=-1) {
        emit RecvData(QJsonDocument::fromJson(buffer.left(p)).toVariant().toMap());
        buffer=buffer.mid(p+1);
    }
}
