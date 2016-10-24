#include "login.h"
#include "profilepage.h"
#include "connect.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
/*
    if(!mydb.open()){
        qDebug()<<("Failed to open the database");
    }
    else{
        qDebug()<<("Connected....");
    }
*/
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{

    QString username, password;
    username =ui->lineEdit_username->text();
    password=ui->lineEdit_password->text();
    Connect conn;
    if(!conn.connOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }
    conn.connOpen();

    QSqlQuery qry;
    qry.prepare("select * from users where username='"+username+"' and password='"+password+"'");

    if(qry.exec( )){
        int count=0;
        while(qry.next()){
            count++;
        }
        if(count ==1){
            ui->label->setText("username and password is correct");
            conn.connClose();
            this->hide();//hide login page

            //mydb.close();
            newAdminProfile = new AdminProfile();
            newAdminProfile->show();




        }
        if(count >1)
            ui->label->setText("Duplicate username and password");
        if(count <1)
            ui->label->setText("Incorrect username or password, please re-enter");
    }

}
