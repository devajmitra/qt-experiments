#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "detailsdialog.h"
#include "displaydialog.h"
#include<QDialog>
#include<QDebug>
#include<cstring>
#include<QLineEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    QMenu *fileMenu = new QMenu(tr("&File"), this);
    QAction *newAction = fileMenu->addAction(tr("&New..."));
    QAction *quitAction = fileMenu->addAction(tr("E&xit"));
    menuBar()->addMenu(fileMenu);

    connect(newAction, SIGNAL(triggered()), this, SLOT(openDialog()));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

    QGridLayout *mainLayout = new QGridLayout;

    searchEdit = new QLineEdit();
    searchButton = new QPushButton("Search");
    searchEdit->setPlaceholderText("Account number...");
    connect(searchEdit, SIGNAL(returnPressed()), this, SLOT(searchAccount()));


    mainLayout->addWidget(searchEdit, 0,2,1,3);
    mainLayout->addWidget(searchButton, 1,3,1,1);

    QWidget *central = new QWidget;
    central->setLayout(mainLayout);
    setCentralWidget(central);
    searchButton->setFocus();

    connect(searchButton, SIGNAL(clicked()), this, SLOT(searchAccount()));

    setWindowTitle(tr("Accounts Manager"));

}


void MainWindow::openDialog()
{
    DetailsDialog dialog(tr("Enter Customer Details"), this);
    dialog.resize(640, 480);
    if (dialog.exec() == QDialog::Accepted) {


        char fName[50], mName[50], lName[50], address[200], mobile[10], email[50];
        long balance;

        strcpy(fName, dialog.getfName().toStdString().c_str());
        strcpy(mName, dialog.getmName().toStdString().c_str());
        strcpy(lName, dialog.getlName().toStdString().c_str());
        strcpy(address, dialog.getAddress().toStdString().c_str());
        strcpy(mobile, dialog.getMobile().toStdString().c_str());
        strcpy(email, dialog.getEmail().toStdString().c_str());

        balance = dialog.getDeposit().toLong();

        char *accno = b.createAccount(fName, mName,lName, address, mobile, email, balance);
        qDebug() << accno;
        QMessageBox::warning(this, tr("Account no"), "Account number : " +tr( accno));
        //qDebug() << accno;
    }
}

void MainWindow::searchAccount(){
    char accno[50];
    strcpy(accno, searchEdit->text().toStdString().c_str());
    account_info *found = b.searchAccount(accno);
    if(found) {
        DisplayDialog dialog(tr("View/Delete/Update"), found, this);
        dialog.resize(640, 480);
        if(dialog.exec() == QDialog::Rejected && dialog.deleteFlag() == 1) {
            b.deleteAccount(found);
        }
        else if(dialog.result() == QDialog::Accepted && dialog.updateFlag() == 1) {
            char fName[50], mName[50], lName[50], address[200], mobile[10], email[50];
            long balance;

            strcpy(fName, dialog.getfName().toStdString().c_str());
            strcpy(mName, dialog.getmName().toStdString().c_str());
            strcpy(lName, dialog.getlName().toStdString().c_str());
            strcpy(address, dialog.getAddress().toStdString().c_str());
            strcpy(mobile, dialog.getMobile().toStdString().c_str());
            strcpy(email, dialog.getEmail().toStdString().c_str());
            balance = dialog.getDeposit().toLong();


            //qDebug() << "Update";

            b.updateAccount(found, fName, mName,lName, address, mobile, email, balance);
        }
        //qDebug() << found->fname<<" "<<found->lname << endl;
    }
    else
        QMessageBox::warning(this, tr("Not found"), "Account does not exist!" );

    searchEdit->clear();
    searchButton->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}
