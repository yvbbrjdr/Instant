#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include "tcpsocket.h"

class TcpServer : public QTcpServer {
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = 0);
protected:
    void incomingConnection(qintptr handle);
signals:
    void newConnection(TcpSocket *socket);
};

#endif // TCPSERVER_H
