#include "enable_disable.h"
#include "ui_enable_disable.h"
#include "connect.h"

enable_disable::enable_disable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enable_disable)
{
    ui->setupUi(this);
}

enable_disable::~enable_disable()
{
    delete ui;
}

void enable_disable::on_pushButton_enabled_clicked()
{
    QString username;
    username =ui->lineEdit_username->text();


    Connect conn;
    if(!conn.connOpen()){
        qDebug()<<("Failed to open the database");
        return;
    }

    QSqlQuery qry;
    qry.prepare("update users set active = 1 where username = '"+username+"'");
    if(qry.exec()){
        qDebug()<<("Enabled");
        conn.connClose();
        this->hide();
    }else{
        qDebug()<<("Error");
    }
}

void enable_disable::on_pushButton_disabled_clicked()
{
    QString username;
    username =ui->lineEdit_username->text();

    Connect conn;
    if(!conn.connOpen()){
        qDebug()<<("Failed to open the database");
        return;
    }
    QSqlQuery qry;
    qry.prepare("update users set active = 0 where username = '"+username+"'");
    if(qry.exec()){
        qDebug()<<("Disabled");
        conn.connClose();
        this->hide();
    }else{
        qDebug()<<("Error");
    }

}
