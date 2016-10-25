#ifndef ADMINPROFILE_H
#define ADMINPROFILE_H

#include <QMainWindow>
#include "adduser.h"
#include "enable_disable.h"

namespace Ui {
class AdminProfile;
}

class AdminProfile : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminProfile(QWidget *parent = 0);
    ~AdminProfile();
    void setCurrentUser(QString, int);

private slots:
    void on_pushButton_newUser_clicked();

    void on_pushButton_load_clicked();

    void on_pushButton_able_clicked();


private:
    Ui::AdminProfile *ui;
    addUser *newAdduser;
    enable_disable *newAble;
    QString currentUser;
    int currentType;
};

#endif // ADMINPROFILE_H
