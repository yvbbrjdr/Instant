#include "tcpserver.h"

TcpServer::TcpServer(QObject *parent):QTcpServer(parent) {}

void TcpServer::incomingConnection(qintptr handle) {
    TcpSocket *socket=new TcpSocket;
    socket->setSocketDescriptor(handle);
    emit newConnection(socket);
}
