#include "adminprofile.h"
#include "ui_adminprofile.h"
#include "connect.h"

AdminProfile::AdminProfile(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminProfile)
{
    ui->setupUi(this);
    //ui->label_type->setText(currentType);

}

AdminProfile::~AdminProfile()
{
    delete ui;
}

void AdminProfile::setCurrentUser(QString uname, int t){
    currentUser = uname;
    currentType = t;
    ui->label_username->setText("You are logged in as: " + currentUser);
    ui->label_type->setText(QString::number(currentType));
}

void AdminProfile::on_pushButton_newUser_clicked()
{
    newAdduser = new addUser();
    newAdduser->setModal(true);
    newAdduser->exec();
}

void AdminProfile::on_pushButton_load_clicked()
{
    Connect conn;
    QSqlQueryModel * modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from users");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    conn.connClose();
    qDebug() << (modal->rowCount());



}

void AdminProfile::on_pushButton_able_clicked()
{
    newAble = new enable_disable();
    newAble->setModal(true);
    newAble->exec();


}
