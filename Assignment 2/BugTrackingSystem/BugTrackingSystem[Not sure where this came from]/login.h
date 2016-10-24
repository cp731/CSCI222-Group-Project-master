#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QApplication>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <string>

#include "profilepage.h"
#include "adminprofile.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

//public:
    //QSqlDatabase mydb;


public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Login *ui;

    ProfilePage *newProfilePage;
    AdminProfile *newAdminProfile;
};

#endif // LOGIN_H
