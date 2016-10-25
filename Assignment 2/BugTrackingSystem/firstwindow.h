#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include <QMainWindow>
#include "login.h"

namespace Ui {
class FirstWindow;
}

class FirstWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FirstWindow(QWidget *parent = 0);
    ~FirstWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::FirstWindow *ui;
    Login *newLogin;
};

#endif // FIRSTWINDOW_H
