#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent):QDialog(parent),ui(new Ui::LoginDialog) {
    ui->setupUi(this);
    connect(ui->Client,SIGNAL(clicked(bool)),this,SLOT(ClientClick()));
    connect(ui->Server,SIGNAL(clicked(bool)),this,SLOT(ServerClick()));
}

LoginDialog::~LoginDialog() {
    delete ui;
}

void LoginDialog::ClientClick() {
    if (ui->Nickname->text().size()==0||ui->Host->text().size()==0||ui->Port->text().size()==0) {
        QMessageBox::critical(this,"Instant","You have to fill in the blank!");
        return;
    }
    socket=new TcpSocket;
    connect(socket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(stateChanged(QAbstractSocket::SocketState)));
    socket->connectToHost(ui->Host->text(),ui->Port->text().toUShort());
    ui->Nickname->setEnabled(false);
    ui->Host->setEnabled(false);
    ui->Port->setEnabled(false);
    ui->Client->setEnabled(false);
    ui->Server->setEnabled(false);
}

void LoginDialog::ServerClick() {
    if (ui->Nickname->text().size()==0||ui->Port->text().size()==0) {
        QMessageBox::critical(this,"Instant","You have to fill in the blank!");
        return;
    }
    server=new TcpServer;
    connect(server,SIGNAL(newConnection(TcpSocket*)),this,SLOT(newConnection(TcpSocket*)));
    server->listen(QHostAddress::Any,ui->Port->text().toUShort());
    ui->Nickname->setEnabled(false);
    ui->Host->setEnabled(false);
    ui->Port->setEnabled(false);
    ui->Client->setEnabled(false);
    ui->Server->setEnabled(false);
}

void LoginDialog::newConnection(TcpSocket *socket) {
    server->close();
    form=new MainForm(socket,ui->Nickname->text());
    form->show();
    close();
}

void LoginDialog::stateChanged(QAbstractSocket::SocketState state) {
    if (state!=QAbstractSocket::ConnectedState)
        return;
    form=new MainForm(socket,ui->Nickname->text());
    form->show();
    close();
}
