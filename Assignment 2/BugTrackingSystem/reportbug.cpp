#include "reportbug.h"
#include "ui_reportbug.h"

Reportbug::Reportbug(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Reportbug)
{
    ui->setupUi(this);
}

Reportbug::~Reportbug()
{
    delete ui;
}

void Reportbug::setCurrentUser(QString uname, int t){
    currentUser = uname;
    currentType = t;
    ui->currentUserLabel->setText("You are logged in as: " + currentUser);
}

void Reportbug::on_loginButton_clicked()
{
    BugList* bugList = new BugList();
    bugList->show();
    this->hide();
}

void Reportbug::on_currentUserLabel_clicked()
{
    ProfilePage* profilePage = new ProfilePage();
    profilePage->setCurrentUser(currentUser, currentType);
    profilePage->show();
    this->hide();
}

void Reportbug::on_submitButton_clicked()
{
    int lastEntryId = getLatestEntry() + 1;
    Connect connection;
    connection.connOpen();

    QSqlQuery query(connection.mydb);
    QString description = ui->shortDescription->toPlainText();
    QDateTime now = QDateTime::currentDateTime();
    qDebug() << "New bug ID is: " << lastEntryId;
    if(!query.exec("INSERT INTO bug VALUES("+QString::number(lastEntryId)+", '"+now.toString()+"', '"+description+"')"))
        qDebug() << "Failed to insert new bug: " << query.lastError();

    connection.connClose();

    BugList* bugList = new BugList();
    bugList->setCurrentUser(currentUser, currentType);
    bugList->show();
    this->hide();

}

int Reportbug::getLatestEntry(){
    Connect connection;
    connection.connOpen();
    QSqlQuery query(connection.mydb);
    if(!query.exec("SELECT MAX(bug_id) FROM bug"))
        qDebug() << "Failed to determine the latest entry.";
    connection.connClose();
    query.first();
    qDebug() << "Determined the latest to be: " << query.value(0);
    return query.value(0).toInt();
}
