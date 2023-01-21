#include "mainwindow.h"

void MainWindow::sqlInit(void)
{
    Database = QSqlDatabase::addDatabase("QSQLITE");
    Database.setDatabaseName("/home/minhnt29/Graduation_GUI/user_database.sqlite3");

    if (!Database.open())
    {
        qDebug() << "Opened file error";
    }

    //Send First Init
    QString lastID;
    QSqlQuery query_password("SELECT * FROM Password", Database);
    while (query_password.next()) {
        current_password = query_password.value(0).toString();
    }
    m_client->publish(QMqttTopicName(TOPIC_FIRSTINIT), current_password.toUtf8());
    delay(2000);
    QSqlQuery query_lastID("SELECT * FROM User", Database);
    while (query_lastID.next()) {
        lastID = query_lastID.value(1).toString();
    }
    m_client->publish(QMqttTopicName(TOPIC_FIRSTINIT), lastID.toUtf8());
}
