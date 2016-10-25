#include "adduser.h"
#include "ui_adduser.h"
#include "login.h"
#include "connect.h"

addUser::addUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addUser)
{
    ui->setupUi(this);
}

addUser::~addUser()
{
    delete ui;
}

void addUser::on_pushButton_adduser_clicked()
{
    QString username, fname, lname, password, type;
    username =ui->text_username->text();
    fname =ui->text_fname->text();
    lname =ui->text_lname->text();
    password=ui->text_password->text();
    type =ui->text_type->text();

    Connect conn;
    if(!conn.connOpen()){
        ui->label_status->setText("Failed");
        qDebug()<<("Failed to open the database");
        return;
    }
    else{
        ui->label_status->setText("Hello");
    }
    QSqlQuery qry;
    qry.prepare("insert into users (username, fname, lname, password, type) values('"+username+"', '"+fname+"', '"+lname+"', '"+password+"', '"+type+"')");
    if(qry.exec()){
        qDebug()<<("Success");
        ui->label_status->setText("Added");
        conn.connClose();
    }else{
        ui->label_status->setText("Error");
    }


}
