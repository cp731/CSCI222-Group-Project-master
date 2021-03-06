#include "profilepage.h"
#include "ui_profilepage.h"
#include "connect.h"

ProfilePage::ProfilePage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProfilePage)
{
    ui->setupUi(this);

    Connect conn;
    QSqlQueryModel * modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery * qry = new QSqlQuery(conn.mydb);
    qry->prepare("select bug_id, creation_ts, short_desc, delta_ts, classification, product, component, version, bug_status, resolution from bug where need_triager=1");
    //qry->prepare("select * from bug");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    qDebug ()<<(modal->rowCount());

    QSqlQueryModel * modal2 = new QSqlQueryModel();
    QSqlQuery qry2;
            //= new QSqlQuery(conn.mydb);
    qry2.prepare("select username from user where type=2");

    qry2.exec();
    modal2->setQuery(qry2);
    ui->comboBox->setModel(modal2);

    qDebug ()<<(modal2->rowCount());



    ui->comboBox_priority->addItem("P1");
    ui->comboBox_priority->addItem("P2");
    ui->comboBox_priority->addItem("P3");
    ui->comboBox_priority->addItem("P4");
    ui->comboBox_priority->addItem("P5");

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



}


void ProfilePage::on_tableView_activated(const QModelIndex &index)
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

void ProfilePage::on_pushButton_submit_clicked()
{
    QString comment = ui->textEdit_comment->toPlainText();


    QSqlQuery qry, qry2;
    qry.prepare("insert into bug_users (bug_id, triager, triager_comment, developer) values('"+bugid+"', '"+currentUser+"', '"+comment+"', '"+ui->comboBox->currentText()+"')");
    qry2.prepare("update bug set need_triager=0, priority = '"+ui->comboBox_priority->currentText()+"'  where bug_id='"+bugid+"'");
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

void ProfilePage::on_pushButton_duplicate_clicked()
{
    QSqlQuery qry;
    qry.prepare("update bug set need_triager=0, set need_developer=0, set bug_status='DUPLICATE' where bug_id='"+bugid+"'");
    if(qry.exec()){
        qDebug()<<("Success");
    }else{
        qDebug()<<("Failed to execute");
    }

}
