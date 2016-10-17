#include "historydialog.h"
#include "ui_historydialog.h"

HistoryDialog::HistoryDialog(QWidget *parent):QDialog(parent),ui(new Ui::HistoryDialog) {
    ui->setupUi(this);
}

HistoryDialog::~HistoryDialog() {
    delete ui;
}

void HistoryDialog::Update(const QString &History) {
    ui->textEdit->setHtml(History);
    QTextCursor qtc(ui->textEdit->textCursor());
    qtc.movePosition(QTextCursor::End);
    ui->textEdit->setTextCursor(qtc);
}
