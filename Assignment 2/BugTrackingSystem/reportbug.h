#ifndef REPORTBUG_H
#define REPORTBUG_H
#include "buglist.h"
#include "profile.h"
#include "connect.h"
#include <QMainWindow>

namespace Ui {
class Reportbug;
}

class Reportbug : public QMainWindow
{
    Q_OBJECT

public:
    explicit Reportbug(QWidget *parent = 0);
    ~Reportbug();
    void setCurrentUser(QString, int);
    int getLatestEntry();

private slots:
    void on_loginButton_clicked();

    void on_currentUserLabel_clicked();

    void on_submitButton_clicked();

private:
    Ui::Reportbug *ui;
    QString currentUser;
    int currentType;
};

#endif // REPORTBUG_H
