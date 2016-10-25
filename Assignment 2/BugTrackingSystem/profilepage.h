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
    QString bugid;


private slots:
    void on_pushButton_3_clicked();

    //void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_submit_clicked();

    void on_pushButton_duplicate_clicked();

private:
    Ui::ProfilePage *ui;
    QString currentUser;
    int currentType;
    QString developer_name;
};

#endif // PROFILEPAGE_H
