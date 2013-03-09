#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "detailsdialog.h"
#include<QDialog>
#include<QDebug>

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


    setWindowTitle(tr("Accounts Manager"));

    count = 0;
}

void MainWindow::openDialog()
{
    DetailsDialog dialog(tr("Enter Customer Details"), this);

    if (dialog.exec() == QDialog::Accepted) {
        const char *fName = dialog.getfName().toStdString().c_str();
        const char *mName = dialog.getmName().toStdString().c_str();
        const char *lName = dialog.getlName().toStdString().c_str();
        const char *address = dialog.getAddress().toStdString().c_str();
        const char *mobile = dialog.getMobile().toStdString().c_str();
        //const char *email = dialog.getEmail().toStdString().c_str();

        b.createAccount(count++, fName, mName,lName, address,"123", mobile/*, email*/, 3000);

        //qDebug() << count<<endl;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
