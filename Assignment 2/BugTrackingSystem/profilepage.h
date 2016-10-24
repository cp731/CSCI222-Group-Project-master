#ifndef PROFILEPAGE_H
#define PROFILEPAGE_H

#include <QMainWindow>

namespace Ui {
class ProfilePage;
}

class ProfilePage : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProfilePage(QWidget *parent = 0);
    ~ProfilePage();
    void setCurrentUser(QString, int);


private slots:
    void on_pushButton_3_clicked();

private:
    Ui::ProfilePage *ui;
    QString currentUser;
    int currentType;
};

#endif // PROFILEPAGE_H
