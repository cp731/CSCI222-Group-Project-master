#include "login.h"
#include "buglist.h"
#include "connect.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    ui->label->setText("Hello");
}

Login::~Login()
{
    delete ui;
}

void Login::setCurrentUser(QString uname, int t){
    currentUser = uname;
    currentType = t;
}

void Login::on_pushButton_clicked()
{

    QString username, password;
    username =ui->lineEdit_username->text();
    password=ui->lineEdit_password->text();

    Connect conn;
    if(!conn.connOpen()){
        ui->label->setText("Not connected");
        qDebug()<<"Failed to open the database";
        return;
    }
    //conn.connOpen();

    QSqlQuery qry;
    qry.prepare("select * from user where username='"+username+"' and password='"+password+"'");

    if(qry.exec( )){
        int count=0;
        while(qry.next()){
            count++;
            currentType= qry.value(5).toInt();
            ui->label->setText("working");

        }
        if(count ==1){
            ui->label->setText("username and password is correct");
            setCurrentUser(username, currentType);
            conn.connClose();
            this->hide();//hide login page

            BugList* bugList = new BugList();
            bugList->setCurrentUser(username, currentType);
            bugList->show();

        }
        if(count >1)
            ui->label->setText("Duplicate username and password");
        if(count <1)
            ui->label->setText("Incorrect username or password, please re-enter");
    }
    //conn.connClose();
    qDebug()<<qry.lastError();

}
