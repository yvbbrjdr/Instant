#ifndef HISTORYDIALOG_H
#define HISTORYDIALOG_H

#include <QDialog>
#include <QTextCursor>

namespace Ui {
    class HistoryDialog;
}

class HistoryDialog : public QDialog {
    Q_OBJECT
public:
    explicit HistoryDialog(QWidget *parent = 0);
    ~HistoryDialog();
    void Update(const QString &History);
private:
    Ui::HistoryDialog *ui;
};

#endif // HISTORYDIALOG_H
