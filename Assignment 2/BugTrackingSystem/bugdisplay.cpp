#include "bugdisplay.h"
#include "ui_bugdisplay.h"

BugDisplay::BugDisplay(QWidget *parent, int bugIDNum, int currentUserType) :
    QMainWindow(parent),
    ui(new Ui::BugDisplay)
{
    qDebug() << "Current type is: " << currentUserType;
    bugId = bugIDNum;
    ui->setupUi(this);
    ui->bugIDLabel->setText("Bug ID#: " + QString::number(bugId));

}

BugDisplay::~BugDisplay()
{
    delete ui;
}

void BugDisplay::setCurrentUser(QString uname, int t){
    currentUser = uname;
    currentType = t;
    if(currentType!=-1){
        ui->currentUserLabel->setStyleSheet("QPushButton {color: blue}");
        ui->currentUserLabel->setText("You are logged in as: " + currentUser);
        ui->loginButton->setText(QString("Logout"));
    }
    if(currentType == 0){
        QPushButton* deleteButton = new QPushButton("Delete Bug", this);
        ui->optionsHBox->addWidget(deleteButton);
        connect(deleteButton, SIGNAL(clicked()), this, SLOT(on_deleteButton_clicked()));
    }
}

// Slot for pressing the login/logout button.
void BugDisplay::on_loginButton_clicked()
{
    if(currentType == -1){
        Login* newLogin = new Login();
        newLogin->show();
        this->hide();
    }else{
        BugList* bugList = new BugList();
        bugList->show();
        this->hide();
    }
}

// Slot for clicking on the username, goes to profile page.
void BugDisplay::on_currentUserLabel_clicked()
{
    // Ensure that someone is logged in
    if(currentType != -1){
        ProfilePage* profilePage = new ProfilePage();
        profilePage->setCurrentUser(currentUser, currentType);
        profilePage->show();
        this->hide();
    }
}

// Slot to return to the bug list
void BugDisplay::on_backButton_clicked()
{
    BugList* bugList = new BugList();
    bugList->setCurrentUser(currentUser, currentType);
    bugList->show();
    this->hide();
}

void BugDisplay::on_deleteButton_clicked(){
    Connect connection;
    connection.connOpen();

    QSqlQuery query(connection.mydb);
    if(!query.exec("DELETE FROM bug WHERE bug_id="+QString::number(bugId)))
        qDebug() << "Failed to delete bug report.";

    connection.connClose();

    BugList* bugList = new BugList();
    bugList->setCurrentUser(currentUser, currentType);
    bugList->show();
    this->hide();
}
