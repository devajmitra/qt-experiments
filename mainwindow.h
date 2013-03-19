#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include<QtWidgets>
#include "bank.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void openDialog();
    void searchAccount();
    
private:
    bank b;
    Ui::MainWindow *ui;

    QLineEdit *searchEdit;
    QPushButton *searchButton;

};

#endif // MAINWINDOW_H
