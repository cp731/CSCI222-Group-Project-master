#ifndef ENABLE_DISABLE_H
#define ENABLE_DISABLE_H

#include <QDialog>

namespace Ui {
class enable_disable;
}

class enable_disable : public QDialog
{
    Q_OBJECT

public:
    explicit enable_disable(QWidget *parent = 0);
    ~enable_disable();

private slots:
    void on_pushButton_enabled_clicked();
    void on_pushButton_disabled_clicked();

private:
    Ui::enable_disable *ui;
};

#endif // ENABLE_DISABLE_H
