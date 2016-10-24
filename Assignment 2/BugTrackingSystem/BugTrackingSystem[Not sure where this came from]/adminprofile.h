#ifndef ADMINPROFILE_H
#define ADMINPROFILE_H

#include <QMainWindow>
#include "adduser.h"

namespace Ui {
class AdminProfile;
}

class AdminProfile : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminProfile(QWidget *parent = 0);
    ~AdminProfile();

private slots:
    void on_pushButton_newUser_clicked();

    void on_pushButton_load_clicked();

private:
    Ui::AdminProfile *ui;
    addUser *newAdduser;
};

#endif // ADMINPROFILE_H
