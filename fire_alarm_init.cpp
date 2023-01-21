#include "mainwindow.h"
#include "ui_fire_alarm.h"

void MainWindow::fireAlarmInit(void)
{
    m_alarm = new (Fire_Alarm);
    m_alarm->hide();
}

void MainWindow::topicFireAlarmHandler(const QString &msg)
{
    if(msg != "0")
    {
        qDebug() << "Fire Init handler";
        m_alarm->show();
        m_alarm->ui->textLable_Fire_Status->setStyleSheet("QLabel { color : red; }");
        m_alarm->ui->textLable_Fire_Status->setText("Hiện đang có cháy ở tầng " + msg);
        sendAlertToUser("0913578636", "1");
    }else
    {
        m_alarm->hide();
        m_alarm->ui->textLable_Fire_Status->setText("");
    }
}
