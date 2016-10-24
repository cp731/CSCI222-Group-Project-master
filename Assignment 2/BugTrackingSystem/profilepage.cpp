#include "profilepage.h"
#include "ui_profilepage.h"
#include "connect.h"

ProfilePage::ProfilePage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProfilePage)
{
    ui->setupUi(this);

}

ProfilePage::~ProfilePage()
{
    delete ui;
}


void ProfilePage::setCurrentUser(QString uname, int t){
    currentUser = uname;
    currentType = t;
}

void ProfilePage::on_pushButton_3_clicked()
{
    Connect conn;
    QSqlQueryModel * modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery * qry = new QSqlQuery(conn.mydb);
    qry->prepare("select * from bug where need_triager = 1");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    conn.connClose();
    qDebug ()<<(modal->rowCount());


}
