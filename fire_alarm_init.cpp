#include "mainwindow.h"
#include "ui_fire_alarm.h"

void MainWindow::fireAlarmInit(void)
{
    m_alarm = new(Fire_Alarm);
    m_alarm->hide();
}

void MainWindow::topicFireAlarmHandler(const QString &msg)
{
    //TODO

    m_alarm->show();
    m_alarm->ui->textLable_Fire_Status->setText("Hiện đang có cháy");
}
