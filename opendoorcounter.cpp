#include "opendoorcounter.h"
#include "ui_opendoorcounter.h"
#include "mainwindow.h"

OpenDoorCounter::OpenDoorCounter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenDoorCounter)
{
    ui->setupUi(this);
}

OpenDoorCounter::~OpenDoorCounter()
{
    delete ui;
}

void MainWindow::showOpenDoorCounter()
{
    this->show();
}

void MainWindow::closeOpenDoorCounter(void)
{
    this->hide();
}

void MainWindow::clickReload()
{
    OpenDoorView new_row = {};
    QSqlQuery query("SELECT * FROM DoorOpenCounter", Database);
    while (query.next()) {
        QString name = query.value(0).toString();
        QString id = query.value(1).toString();
        QString time = query.value(2).toString();
        QString date = query.value(3).toString();

        ui->tableWidget_Door_Open->insertRow(ui->tableWidget_Door_Open->rowCount());
        new_row.id = new QTableWidgetItem;
        new_row.id->setText(id);
        new_row.id->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_Door_Open->setItem(ui->tableWidget_Door_Open->rowCount() - 1, kId, new_row.id);

        new_row.name = new QTableWidgetItem;
        new_row.name->setText(name);
        new_row.name->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_Door_Open->setItem(ui->tableWidget_Door_Open->rowCount() - 1, kName, new_row.name);

        new_row.Time = new QTableWidgetItem;
        new_row.Time->setText(time);
        new_row.Time->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_Door_Open->setItem(ui->tableWidget_Door_Open->rowCount() - 1, kTime, new_row.time);

        new_row.Date = new QTableWidgetItem;
        new_row.Date->setText(date);
        new_row.Date->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_Door_Open->setItem(ui->tableWidget_Door_Open->rowCount() - 1, kDate, new_row.date);
    }
}

