#ifndef DEVELOPERPAGE_H
#define DEVELOPERPAGE_H

#include <QMainWindow>

namespace Ui {
class DeveloperPage;
}

class DeveloperPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeveloperPage(QWidget *parent = 0);
    ~DeveloperPage();
    void setCurrentUser(QString uname, int t);
    QString bugid;

private slots:
    void on_tableView_activated(const QModelIndex &index);

    
    void on_pushButton_submit_clicked();

private:
    Ui::DeveloperPage *ui;
    QString currentUser;
    int currentType;
};

#endif // DEVELOPERPAGE_H
