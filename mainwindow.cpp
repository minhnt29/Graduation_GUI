#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mosquitto.h"
#include "ui_door.h"
#include "ui_floor1.h"
#include "ui_fire_alarm.h"
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mqttClientInit();
    floor1Init();
    doorInit();
    fireAlarmInit();
    ui = new (Ui::MainWindow);
    ui->setupUi(this);

    connect(ui->pushButton_Door, &QPushButton::clicked, this, &MainWindow::openDoorControl);
    connect(ui->pushButton_Floor1, &QPushButton::clicked, this, &MainWindow::openFloor1Control);
    connect(ui->pushButton_Floor2, &QPushButton::clicked, this, &MainWindow::openFloor2Control);
    connect(ui->pushButton_Floor3, &QPushButton::clicked, this, &MainWindow::openFloor3Control);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_door;
    delete m_floor1;
}

void MainWindow::openDoorControl()
{
    this->hide();
    m_floor1->hide();
    m_door->show();
}

void MainWindow::openFloor1Control()
{
    this->hide();
    m_door->hide();
    m_floor1->show();
}

void MainWindow::openFloor2Control()
{
    //@TODO
}

void MainWindow::openFloor3Control()
{
    //@TODO
}

void MainWindow::delay(int millisecondsToWait) const {
    QTime dieTime = QTime::currentTime().addMSecs(millisecondsToWait);
    while (QTime::currentTime() < dieTime) {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}
