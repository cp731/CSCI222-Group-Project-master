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

        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("csci222.chaomander.com");
        db.setUserName("csci222");
        db.setPassword("xFMxvsf77ARRwhXcfUvyrHYWtjBnjv");
        db.setDatabaseName("bug_tracker");

        if(!db.open())
        {
            qDebug()<<("Failed to open the database");
            return false;
        }else{
            qDebug()<<("Connected to mysql");
            return true;
        }

    }


public:
    //explicit Connect(QWidget *parent = 0);
    ~Connect(){}


};



#endif // CONNECT_H
