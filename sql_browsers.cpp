#include "mainwindow.h"

void MainWindow::sqlInit(void)
{
    QSqlDatabase Database;

    Database = QSqlDatabase::addDatabase("QSQLITE");
    Database.setDatabaseName("/home/minhnt/code/Graduation_GUI/user_database.sqlite3");

    if (!Database.open())
    {
        qDebug() << "Opened file error";
    }

    QSqlQuery query("SELECT name id FROM User", Database);
    //Insert ID
//    query.prepare("INSERT INTO User (name, id) "
//                      "VALUES (:name, :id)");
//    query.bindValue(":id", 1000);
//    query.bindValue(":name", "Minh");
//    if (query.exec() != true) {
//        qDebug() << "write failed";
//    }

    //Delete ID
//    query.exec("DELETE FROM User WHERE id = 1001");
    //Search ID

        while (query.next()) {
            QString name = query.value(0).toString();
            qDebug() << name;

            quint32 id = query.value(1).toInt();
            qDebug() << id;

        }
}
