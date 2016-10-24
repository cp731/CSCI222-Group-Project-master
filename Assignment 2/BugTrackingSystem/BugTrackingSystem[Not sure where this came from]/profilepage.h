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

private slots:
    void on_radioButton_clicked();

private:
    Ui::ProfilePage *ui;
};

#endif // PROFILEPAGE_H
