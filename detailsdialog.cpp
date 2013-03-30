#include "detailsdialog.h"
#include "ui_detailsdialog.h"
#include<QtWidgets>
#include<QDebug>

DetailsDialog::DetailsDialog(const QString &title, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailsDialog)
{

    ui->setupUi(this);
    //accnoLabel = new QLabel(tr("Account number: "));
    fnameLabel = new QLabel(tr("First Name:"));
    addressLabel = new QLabel(tr("Address:"));
    addressLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    mnameLabel = new QLabel(tr("Middle Name:"));
    lnameLabel = new QLabel(tr("Last Name:"));
    mobileLabel = new QLabel(tr("Mobile Number:"));
    emailLabel = new QLabel(tr("Email: "));

    //accno = new QLabel(new QString(acc));
    fnameEdit = new QLineEdit;
    mnameEdit = new QLineEdit;
    lnameEdit = new QLineEdit;
    mobileEdit = new QLineEdit;
    addressEdit = new QTextEdit;
    emailEdit = new QLineEdit;

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(verify()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(fnameLabel, 0, 0);
    mainLayout->addWidget(fnameEdit, 0, 1);
    mainLayout->addWidget(mnameLabel, 0, 2);
    mainLayout->addWidget(mnameEdit, 0, 3);
    mainLayout->addWidget(lnameLabel, 1, 0);
    mainLayout->addWidget(lnameEdit, 1, 1);
    mainLayout->addWidget(addressLabel, 2, 0);
    mainLayout->addWidget(addressEdit, 2, 1, 3, 3);
    mainLayout->addWidget(mobileLabel, 5, 0);
    mainLayout->addWidget(mobileEdit, 5, 1, 1, 2);
    mainLayout->addWidget(emailLabel, 6, 0);
    mainLayout->addWidget(emailEdit, 6, 1, 1, 4);
    //mainLayout->addWidget(accnoLabel, 7, 0);
    //mainLayout->addWidget(accno, 7, 1);
    mainLayout->addWidget(buttonBox, 7, 0, 1, 5);

    //qDebug() << (acc+1);

    setLayout(mainLayout);

    setWindowTitle(title);
}

QString DetailsDialog::getfName() const
{
    return fnameEdit->text();
}
QString DetailsDialog::getmName() const
{
    return mnameEdit->text();
}
QString DetailsDialog::getlName() const
{
    return lnameEdit->text();
}

QString DetailsDialog::getAddress() const
{
    return addressEdit->toPlainText();
}

QString DetailsDialog::getMobile() const
{
    return mobileEdit->text();
}

QString DetailsDialog::getEmail() const
{
    return emailEdit->text();
}

DetailsDialog::~DetailsDialog()
{
    delete ui;
}

void DetailsDialog::verify()
{
    if (!fnameEdit->text().isEmpty() && !mnameEdit->text().isEmpty() && !lnameEdit->text().isEmpty() &&
            !addressEdit->toPlainText().isEmpty() && !mobileEdit->text().isEmpty() && !emailEdit->text().isEmpty() ) {
        accept();
        return;
    }

    QMessageBox::StandardButton answer;
    answer = QMessageBox::warning(this, tr("Incomplete Form"),
        tr("The form doedoes not exist!s not contain all the necessary information.\n"
           "Do you want to discard it?"),
        QMessageBox::Yes | QMessageBox::No);

    if (answer == QMessageBox::Yes)
        reject();
}
