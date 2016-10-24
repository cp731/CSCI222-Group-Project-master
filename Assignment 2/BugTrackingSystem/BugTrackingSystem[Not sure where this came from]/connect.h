#ifndef CONNECT_H
#define CONNECT_H

#include <QtSql>
#include <QDebug>
#include <QString>

namespace Ui {
class Connect;
}

class Connect
{

public:
    QSqlDatabase mydb;
    void connClose(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen(){

        mydb=QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("/Users/clarephelps/BugTrackingSystem/sqlite-amalgamation-3150000/test.db");

        if(!mydb.open()){
            qDebug()<<("Failed to open the database");
            return false;
        }
        else{
            qDebug()<<("Connected....");
            return true;
        }

    }


public:
    //explicit Connect(QWidget *parent = 0);
    //~Connect();


};



#endif // CONNECT_H
