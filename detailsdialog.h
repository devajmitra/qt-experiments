#ifndef DETAILSDIALOG_H
#define DETAILSDIALOG_H

#include <QDialog>
#include<QtWidgets>

namespace Ui {
class DetailsDialog;
}

class DetailsDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit DetailsDialog(const QString &title, QWidget *parent = 0);
    QString getfName() const;
    QString getmName() const;
    QString getlName() const;
    QString getAddress() const;
    QString getMobile() const;
    QString getEmail() const;
    ~DetailsDialog();

public slots:
    void verify();
    
private:
    Ui::DetailsDialog *ui;

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

#endif // DETAILSDIALOG_H
