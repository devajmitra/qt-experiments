#include "displaydialog.h"
#include "ui_displaydialog.h"
#include<QTextEdit>
#include<QPushButton>
#include "bank.h"

DisplayDialog::DisplayDialog(const QString &title, const account_info *record, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplayDialog)
{
    ui->setupUi(this);
    setWindowTitle(title);

    fnameLabel = new QLabel(tr("First Name:"));
    addressLabel = new QLabel(tr("Address:"));
    addressLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    mnameLabel = new QLabel(tr("Middle Name:"));
    lnameLabel = new QLabel(tr("Last Name:"));
    mobileLabel = new QLabel(tr("Mobile Number:"));
    emailLabel = new QLabel(tr("Email: "));

    fnameEdit = new QLineEdit(record->fname);
    mnameEdit = new QLineEdit(record->mname);
    lnameEdit = new QLineEdit(record->lname);
    mobileEdit = new QLineEdit(record->mobile_no);
    addressEdit = new QTextEdit(record->address);
    emailEdit = new QLineEdit(record->email);

    fnameEdit->setDisabled(true);
    mnameEdit->setDisabled(true);
    lnameEdit->setDisabled(true);
    mobileEdit->setDisabled(true);
    addressEdit->setDisabled(true);
    emailEdit->setDisabled(true);

    QPushButton *done = new QPushButton(tr("Done"));
    QPushButton *edit = new QPushButton(tr("Edit"));
    QPushButton *update = new QPushButton(tr("Update"));
    QPushButton *remove = new QPushButton(tr("Delete"));

    connect(done, SIGNAL(clicked()), this, SLOT(accept()));
    connect(edit, SIGNAL(clicked()), this, SLOT(setEditable()));
    connect(remove, SIGNAL(clicked()), this, SLOT(reject()));

    buttonBox = new QDialogButtonBox(Qt::Vertical);

    buttonBox->addButton(edit, QDialogButtonBox::ActionRole);
    buttonBox->addButton(done, QDialogButtonBox::AcceptRole);
    buttonBox->addButton(update, QDialogButtonBox::ActionRole);
    buttonBox->addButton(remove, QDialogButtonBox::ActionRole);

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
    mainLayout->addWidget(emailEdit, 6, 1, 1, 3);
    mainLayout->addWidget(buttonBox, 0, 5);

    setLayout(mainLayout);
}

void DisplayDialog :: setEditable() {
    fnameEdit->setDisabled(false);
    mnameEdit->setDisabled(false);
    lnameEdit->setDisabled(false);
    mobileEdit->setDisabled(false);
    addressEdit->setDisabled(false);
    emailEdit->setDisabled(false);
}

DisplayDialog::~DisplayDialog()
{
    delete ui;
}
