#ifndef BUGLIST_H
#define BUGLIST_H

//#include <QMainWindow>
//#include <QtSql>
//#include <QDebug>
#include <QLabel>
//#include <QGroupBox>
#include "login.h"
#include "connect.h"
#include "reportbug.h"
#include "bugdisplay.h"
#include "developerpage.h"

namespace Ui {
class BugList;
}

class BugList : public QMainWindow
{
    Q_OBJECT

public:
    explicit BugList(QWidget *parent = 0, QString searchValue="", int currentUserType=-1);
    ~BugList();
    void setCurrentUser(QString uname, int t);

private slots:
    void on_searchButton_clicked();

    void on_loginButton_clicked();

    void on_currentUserLabel_clicked();

    void on_newBugButton_clicked();

    void on_bugButton_clicked(int);

    //void on_reportsButton_clicked();

signals:
    void bugButtonClicked(int);

private:
    Ui::BugList *ui;
    QSqlQuery bugQuery(QString searchTerm);
    void setList(QSqlQuery bugs);
    QString currentUser;
    int currentType;
};

#endif // BUGLIST_H
