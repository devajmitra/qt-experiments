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

    QString getfName() const;
    QString getmName() const;
    QString getlName() const;
    QString getAddress() const;
    QString getMobile() const;
    QString getEmail() const;
    QString getDeposit() const;

    int deleteFlag() ;
    int updateFlag();
    ~DisplayDialog();

private slots:
    void setEditable();
    void deleteAccount();
    void updateAccount();
    
private:
    Ui::DisplayDialog *ui;

    int deleteF;
    int updateF;

    QLabel *fnameLabel;
    QLabel *mnameLabel;
    QLabel *lnameLabel;
    QLabel *addressLabel;
    QLabel *mobileLabel;
    QLabel *emailLabel;
    QLabel *depositLabel;

    QLineEdit *fnameEdit;
    QLineEdit *mnameEdit;
    QLineEdit *lnameEdit;
    QLineEdit *mobileEdit;
    QLineEdit *emailEdit;
    QTextEdit *addressEdit;
    QLineEdit *depositEdit;

    QDialogButtonBox *buttonBox;

};

#endif // DISPLAYDIALOG_H
