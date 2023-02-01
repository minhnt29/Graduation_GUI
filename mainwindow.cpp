#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_door.h"
#include "ui_floor1.h"
#include "ui_fire_alarm.h"
#include "ui_add_account.h"
#include "ui_password_panel.h"
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mqttClientInit();
    sqlInit();
    floor1Init();
    floor2Init();
    doorInit();
    fireAlarmInit();
    moduleSimInit();
    ui = new (Ui::MainWindow);
    ui->setupUi(this);
    ui->lineEdit_Home_Owner->setText("0913578636");

    connect(ui->pushButton_Door, &QPushButton::clicked, this, &MainWindow::openDoorControl);
    connect(ui->pushButton_Floor1, &QPushButton::clicked, this, &MainWindow::openFloor1Control);
    connect(ui->pushButton_Floor2, &QPushButton::clicked, this, &MainWindow::openFloor2Control);
    connect(ui->pushButton_Floor3, &QPushButton::clicked, this, &MainWindow::openFloor3Control);
}

MainWindow::~MainWindow()
{
    delete m_door;
    delete m_floor1;
    delete m_add_account;
    delete m_password_panel;
    delete m_SerialPort;
    delete m_client;
    delete m_open_door_counter;
    delete m_alarm;
    delete m_SerialPort;
    delete ui;
}

void MainWindow::openDoorControl()
{
    this->hide();
    m_floor1->hide();
    m_floor2->hide();
    m_door->show();
}

void MainWindow::openFloor1Control()
{
    this->hide();
    m_door->hide();
    m_floor1->show();
    m_floor2->hide();
}

void MainWindow::openFloor2Control()
{
    this->hide();
    m_door->hide();
    m_floor2->show();
    m_floor1->hide();
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
