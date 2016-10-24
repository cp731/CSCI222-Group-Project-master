
#include "connect.h"
DbManager::DbManager(const QString& path)
{
   mydb = QSqlDatabase::addDatabase("QSQLITE");
   mydb.setDatabaseName("/Users/clarephelps/BugTrackingSystem/sqlite-amalgamation-3150000/test.db");

   if (!mydb.open())
   {
      qDebug() << "Error: connection with database fail";
   }
   else
   {
      qDebug() << "Database: connection ok";
   }
}
