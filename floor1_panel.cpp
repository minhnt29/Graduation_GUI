#include "mainwindow.h"
#include "ui_floor1.h"


void MainWindow::floor1Init(void)
{
    m_floor1 = new (Floor1);
    connect(m_floor1->ui->pushButton_Home, &QPushButton::clicked, this, &MainWindow::returnHome);
}

void MainWindow::returnHome()
{
    this->show();
    m_door->hide();
    m_floor1->hide();
}

void MainWindow::topicFloor1Handler(const QString &msg)
{

}
