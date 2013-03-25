#ifndef DISPLAYDIALOG_H
#define DISPLAYDIALOG_H

#include <QDialog>
#include<QtWidgets>
#include "bank.h"

namespace Ui {
class DisplayDialog;
}

class DisplayDialog : public QDialog
{
    Q_OBJECT
    
public:

    explicit DisplayDialog(const QString &title, const account_info *record, QWidget *parent = 0);
    ~DisplayDialog();

private slots:
    void setEditable();
    
private:
    Ui::DisplayDialog *ui;

    QLabel *fnameLabel;
    QLabel *mnameLabel;
    QLabel *lnameLabel;
    QLabel *addressLabel;
    QLabel *mobileLabel;
    QLabel *emailLabel;

    QLineEdit *fnameEdit;
    QLineEdit *mnameEdit;
    QLineEdit *lnameEdit;
    QLineEdit *mobileEdit;
    QLineEdit *emailEdit;
    QTextEdit *addressEdit;

    QDialogButtonBox *buttonBox;

};

#endif // DISPLAYDIALOG_H
