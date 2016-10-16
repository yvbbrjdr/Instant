#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QTcpSocket>
#include <QVariantMap>
#include <QJsonDocument>
#include <QByteArray>

class TcpSocket : public QTcpSocket {
    Q_OBJECT
public:
    explicit TcpSocket(QObject *parent = 0);
private:
    QByteArray buffer;
signals:
    void SendData(const QVariantMap &qvm);
    void RecvData(const QVariantMap &qvm);
private slots:
    void SendDataSlot(const QVariantMap &qvm);
    void RecvDataSlot();
};

#endif // TCPSOCKET_H
