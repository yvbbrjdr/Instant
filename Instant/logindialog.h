#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "tcpserver.h"
#include "tcpsocket.h"
#include "mainform.h"
#include <QMessageBox>

namespace Ui {
    class LoginDialog;
}

class LoginDialog : public QDialog {
    Q_OBJECT
public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
private:
    Ui::LoginDialog *ui;
    TcpServer *server;
    TcpSocket *socket;
    MainForm *form;
private slots:
    void ClientClick();
    void ServerClick();
    void newConnection(TcpSocket *socket);
    void stateChanged(QAbstractSocket::SocketState state);
};

#endif // LOGINDIALOG_H
