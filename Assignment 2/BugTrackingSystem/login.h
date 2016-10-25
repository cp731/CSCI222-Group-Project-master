#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QApplication>
#include <QtSql>
#include <QDebug>
//#include <QFileInfo>
//#include <QString>

#include "profilepage.h"
#include "adminprofile.h"

// Everyones password is potato123


namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT
private:
    QString currentUser;
    int currentType;

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    void setCurrentUser(QString, int);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
