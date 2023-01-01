#include "opendoorcounter.h"
#include "ui_opendoorcounter.h"
#include "mainwindow.h"

OpenDoorCounter::OpenDoorCounter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenDoorCounter)
{
    ui->setupUi(this);
    connect(ui->pushButton_Ok, &QPushButton::clicked, this, &OpenDoorCounter::closeOpenDoorCounter);
    connect(ui->pushButton_Reload, &QPushButton::clicked, this, &OpenDoorCounter::clickReload);
}

OpenDoorCounter::~OpenDoorCounter()
{
    delete ui;
}

void OpenDoorCounter::showOpenDoorCounter()
{
    this->show();
}

void OpenDoorCounter::closeOpenDoorCounter(void)
{
    this->hide();
}

void OpenDoorCounter::clickReload()
{
    QSqlDatabase Database = QSqlDatabase::addDatabase("QSQLITE");
    Database.setDatabaseName("/home/minhnt29/Graduation_GUI/user_database.sqlite3");

    if (!Database.open())
    {
        qDebug() << "Opened file error";
    }

    OpenDoorView new_row = {};
    QSqlQuery query("SELECT * FROM DoorOpenCounter", Database);
    while (query.next()) {
        QString name = query.value(0).toString();
        QString id = query.value(1).toString();
        QString time = query.value(2).toString();
        QString date = query.value(3).toString();

        ui->tableWidget_Door_Open->insertRow(ui->tableWidget_Door_Open->rowCount());
        new_row.id = new QTableWidgetItem;
        new_row.id->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_Door_Open->setItem(ui->tableWidget_Door_Open->rowCount() - 1, kId, new_row.id);
    }

    Database.close();
}

