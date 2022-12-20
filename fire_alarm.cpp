#include "fire_alarm.h"
#include "ui_fire_alarm.h"

Fire_Alarm::Fire_Alarm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Fire_Alarm)
{
    ui->setupUi(this);
}

Fire_Alarm::~Fire_Alarm()
{
    delete ui;
}
