#include "developerpage.h"
#include "ui_developerpage.h"
#include "connect.h"

DeveloperPage::DeveloperPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeveloperPage)
{
    ui->setupUi(this);

    Connect conn;
    QSqlQueryModel * modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery * qry = new QSqlQuery(conn.mydb);
    qry->prepare("select * from bug left outer join bug_users on bug.bug_id=bug_users.bug_id where bug.need_triager=0 and bug.need_developer=1 and bug_users.developer = '"+currentUser+"'");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    qDebug ()<<(modal->rowCount());
    qDebug()<<qry->lastError();
}

DeveloperPage::~DeveloperPage()
{
    delete ui;
}

void DeveloperPage::setCurrentUser(QString uname, int t){
    currentUser = uname;
    currentType = t;
}


void DeveloperPage::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
    ui->label->setText(val);

    QSqlQuery qry;
    qry.prepare("select * from bug where bug_id='"+val+"'");

    if(qry.exec()){
        while(qry.next()){
            ui->label_bug_id->setText(qry.value(0).toString());
            bugid = qry.value(0).toString();
            ui->creation->setText(qry.value(1).toString());
            ui->label_description->setText(qry.value(2).toString());
            ui->label_product->setText(qry.value(8).toString());
            ui->label_component->setText(qry.value(9).toString());
            ui->label_version->setText(qry.value(10).toString());
        }
    }else{

        ui->label->setText("Not Working");
    }
    qDebug()<<qry.lastError();

}

void DeveloperPage::on_pushButton_submit_clicked()
{
    QString comment = ui->textEdit_comment->toPlainText();


    QSqlQuery qry, qry2;
    qry.prepare("update bug_users set developer_comment= '"+comment+"' where bug_id='"+bugid+"'");
    qry2.prepare("update bug set need_developer=0 where bug_id='"+bugid+"'");
    if(qry.exec()){
        qDebug()<<("Success");
    }else{
        qDebug()<<("Failed to execute");
    }

    if(qry2.exec()){
        qDebug()<<("Success");
    }else{
        qDebug()<<("Failed to execute");
    }
    qDebug()<<qry.lastError();

    ui->label_bug_id->setText(" ");
    ui->creation->setText(" ");
    ui->label_description->setText(" ");
    ui->label_product->setText(" ");
    ui->label_component->setText(" ");
    ui->label_version->setText(" ");
}
