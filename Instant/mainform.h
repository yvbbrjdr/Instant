#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include "tcpsocket.h"
#include <QVariantMap>
#include <QDateTime>
#include <QMessageBox>
#include "historydialog.h"

namespace Ui {
    class MainForm;
}

class MainForm : public QWidget {
    Q_OBJECT
public:
    explicit MainForm(TcpSocket *socket,const QString &Nickname,QWidget *parent = 0);
    ~MainForm();
private:
    Ui::MainForm *ui;
    TcpSocket *socket;
    QString Nickname;
    QString History;
    HistoryDialog *hd;
private slots:
    void disconnected();
    void RecvData(const QVariantMap &qvm);
    void textChanged(const QString &text);
    void returnPressed();
    void HistoryPressed();
};

#endif // MAINFORM_H
