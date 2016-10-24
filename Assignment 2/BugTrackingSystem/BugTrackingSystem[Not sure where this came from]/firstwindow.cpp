#include "firstwindow.h"
#include "ui_firstwindow.h"
#include "currentuser.h"

FirstWindow::FirstWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FirstWindow)
{
    ui->setupUi(this);

    CurrentUser browser;
}

FirstWindow::~FirstWindow()
{
    delete ui;
}

void FirstWindow::on_pushButton_clicked()
{
    newLogin = new Login();
    newLogin->show();
    this->hide();
}
