#include "mainform.h"
#include "ui_mainform.h"

MainForm::MainForm(TcpSocket *socket,const QString &Nickname,QWidget *parent):QWidget(parent),ui(new Ui::MainForm),socket(socket),Nickname(Nickname) {
    ui->setupUi(this);
    connect(socket,SIGNAL(RecvData(QVariantMap)),this,SLOT(RecvData(QVariantMap)));
    connect(ui->Local,SIGNAL(textChanged(QString)),this,SLOT(textChanged(QString)));
    connect(ui->Local,SIGNAL(returnPressed()),this,SLOT(returnPressed()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(close()));
    connect(ui->HistoryButton,SIGNAL(clicked(bool)),this,SLOT(HistoryPressed()));
    setWindowTitle("Instant - "+Nickname);
    hd=new HistoryDialog(this);
}

MainForm::~MainForm() {
    delete ui;
}

void MainForm::RecvData(const QVariantMap &qvm) {
    if (qvm["type"]=="edit") {
        ui->Peer->setText(qvm["content"].toString());
    } else if (qvm["type"]=="send") {
        ui->Peer->setText("");
        History+=QString("<p style=\"color:blue;\">%1 %2<br>%3</p>").arg(QDateTime::currentDateTime().toString("yyyy-M-d HH:mm:ss")).arg(qvm["nickname"].toString().toHtmlEscaped()).arg(qvm["content"].toString().toHtmlEscaped());
        hd->Update(History);
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
    History+=QString("<p style=\"text-align:right;color:green;\">%1 %2<br>%3</p>").arg(QDateTime::currentDateTime().toString("yyyy-M-d HH:mm:ss")).arg(Nickname.toHtmlEscaped()).arg(ui->Local->text().toHtmlEscaped());
    hd->Update(History);
    QVariantMap qvm;
    qvm.insert("type","send");
    qvm.insert("nickname",Nickname);
    qvm.insert("content",ui->Local->text());
    socket->SendData(qvm);
    ui->Local->setText("");
}

void MainForm::HistoryPressed() {
    hd->show();
}
