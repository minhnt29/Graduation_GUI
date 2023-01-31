#include "mainwindow.h"
#include "ui_fire_alarm.h"
#include "ui_mainwindow.h"

void MainWindow::fireAlarmInit(void)
{
    m_alarm = new (Fire_Alarm);
    m_alarm->hide();
}

void MainWindow::topicFireAlarmHandler(const QString &msg)
{
    if(msg.at(0) == '1') {
        if(msg.at(1) == '1')
            is_floor1_fire = true;
        else
            is_floor1_fire = false;
    }else if(msg.at(0) == '2') {
        if(msg.at(1) == '1')
            is_floor2_fire = true;
        else
            is_floor2_fire = false;
    }else if(msg.at(0) == '3') {
        if(msg.at(1) == '1')
            is_floor3_fire = true;
        else
            is_floor3_fire = false;
    }
    else {
        qDebug() << "Trash data is sent";
        return;
    }
    if(is_floor1_fire == true) {
        m_alarm->show();
        m_alarm->ui->textLable_Fire_Status->setStyleSheet("QLabel {font: 75 18pt PibotoLt; color : red; }");
        m_alarm->ui->textLable_Fire_Status->setText("Hiện đang có cháy ở tầng 1");
        sendAlertToUser(ui->lineEdit_Home_Owner->text(), "1");
    }
    if(is_floor2_fire == true) {
        m_alarm->show();
        m_alarm->ui->textLable_Fire_Status->setStyleSheet("QLabel {font: 75 18pt PibotoLt; color : red; }");
        m_alarm->ui->textLable_Fire_Status->setText("Hiện đang có cháy ở tầng 2");
        sendAlertToUser(ui->lineEdit_Home_Owner->text(), "2");
    }
    if(is_floor3_fire == true) {
        m_alarm->show();
        m_alarm->ui->textLable_Fire_Status->setStyleSheet("QLabel {font: 75 28pt PibotoLt; color : red; }");
        m_alarm->ui->textLable_Fire_Status->setText("Hiện đang có cháy ở tầng 3");
        sendAlertToUser(ui->lineEdit_Home_Owner->text(), "3");
    }
    if(is_floor1_fire == false && is_floor2_fire == false && is_floor3_fire == false)
    {
        payload = "00";
        m_client->publish(QMqttTopicName(TOPIC_DOOR), payload.toUtf8());
        m_alarm->hide();
        m_alarm->ui->textLable_Fire_Status->setText("");
    }
}
