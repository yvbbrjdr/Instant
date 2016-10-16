#include "mainform.h"
#include "ui_mainform.h"

MainForm::MainForm(TcpSocket *socket,const QString &Nickname,QWidget *parent):QWidget(parent),ui(new Ui::MainForm),socket(socket),Nickname(Nickname) {
    ui->setupUi(this);
    connect(socket,SIGNAL(RecvData(QVariantMap)),this,SLOT(RecvData(QVariantMap)));
    connect(ui->Local,SIGNAL(textChanged(QString)),this,SLOT(textChanged(QString)));
    connect(ui->Local,SIGNAL(returnPressed()),this,SLOT(returnPressed()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(close()));
    setWindowTitle("Instant - "+Nickname);
}

MainForm::~MainForm() {
    delete ui;
}

void MainForm::RecvData(const QVariantMap &qvm) {
    if (qvm["type"]=="edit") {
        ui->Peer->setText(qvm["content"].toString());
    } else if (qvm["type"]=="send") {
        ui->Peer->setText("");
        ui->Common->append(QString("%1 %2\n%3\n").arg(QDateTime::currentDateTime().toString("yyyy-M-d hh:mm:ss")).arg(qvm["nickname"].toString()).arg(qvm["content"].toString()));
    }
}

void MainForm::textChanged(const QString &text) {
    QVariantMap qvm;
    qvm.insert("type","edit");
    qvm.insert("content",text);
    socket->SendData(qvm);
}

void MainForm::returnPressed() {
    if (ui->Local->text().size()==0)
        return;
    ui->Common->append(QString("%1 %2\n%3\n").arg(QDateTime::currentDateTime().toString("yyyy-M-d hh:mm:ss")).arg(Nickname).arg(ui->Local->text()));
    QVariantMap qvm;
    qvm.insert("type","send");
    qvm.insert("nickname",Nickname);
    qvm.insert("content",ui->Local->text());
    socket->SendData(qvm);
    ui->Local->setText("");
}
