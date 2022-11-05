#include "mainwindow.h"
#include "ui_fire_alarm.h"

void MainWindow::fireAlarmInit(void)
{
    m_alarm = new(Fire_Alarm);
    m_alarm->hide();
}
