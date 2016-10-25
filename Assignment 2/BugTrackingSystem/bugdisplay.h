#ifndef BUGDISPLAY_H
#define BUGDISPLAY_H

//#include <QMainWindow>
#include "profilepage.h"
#include "buglist.h"
#include "login.h"
#include "connect.h"

namespace Ui {
class BugDisplay;
}

class BugDisplay : public QMainWindow
{
    Q_OBJECT

public:
    explicit BugDisplay(QWidget *parent = 0, int bugIDNum = 0, int currentUserType = -1);
    ~BugDisplay();
    void setCurrentUser(QString uname, int t);

private slots:
    void on_loginButton_clicked();

    void on_currentUserLabel_clicked();

    void on_backButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::BugDisplay *ui;
    QString currentUser;
    int currentType;
    int bugId;
};

#endif // BUGDISPLAY_H
