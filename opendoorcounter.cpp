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
    m_open_door_counter->show();
}

void MainWindow::closeOpenDoorCounter()
{
    m_open_door_counter->hide();
}

void MainWindow::clickReload()
{
    m_open_door_counter->ui->tableWidget_Door_Open->setRowCount(0);
    OpenDoorView new_row = {};
    QSqlQuery query("SELECT * FROM DoorOpenCounter", Database);
    while (query.next()) {
        QString name = query.value(0).toString();
        QString id = query.value(1).toString();
        QString time = query.value(2).toString();
        QString date = query.value(3).toString();

        m_open_door_counter->ui->tableWidget_Door_Open->insertRow(m_open_door_counter->ui->tableWidget_Door_Open->rowCount());
        new_row.id = new QTableWidgetItem;
        new_row.id->setText(id);
        new_row.id->setTextAlignment(Qt::AlignCenter);
        m_open_door_counter->ui->tableWidget_Door_Open->setItem(m_open_door_counter->ui->tableWidget_Door_Open->rowCount() - 1, kId, new_row.id);

        new_row.name = new QTableWidgetItem;
        new_row.name->setText(name);
        new_row.name->setTextAlignment(Qt::AlignCenter);
        m_open_door_counter->ui->tableWidget_Door_Open->setItem(m_open_door_counter->ui->tableWidget_Door_Open->rowCount() - 1, kName, new_row.name);

        new_row.time = new QTableWidgetItem;
        new_row.time->setText(time);
        new_row.time->setTextAlignment(Qt::AlignCenter);
        m_open_door_counter->ui->tableWidget_Door_Open->setItem(m_open_door_counter->ui->tableWidget_Door_Open->rowCount() - 1, kTime, new_row.time);

        new_row.date = new QTableWidgetItem;
        new_row.date->setText(date);
        new_row.date->setTextAlignment(Qt::AlignCenter);
        m_open_door_counter->ui->tableWidget_Door_Open->setItem(m_open_door_counter->ui->tableWidget_Door_Open->rowCount() - 1, kDate, new_row.date);
    }
}

