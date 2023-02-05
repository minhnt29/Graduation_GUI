#include "mainwindow.h"
#include "ui_floor2.h"


void MainWindow::floor2Init(void)
{
    m_floor2 = new (Floor2);
    m_floor2->ui->pushButton_Light_Status->setIcon(icon_off_light);
    m_floor2->ui->pushButton_Curtain_Status->setIcon(icon_off_light);
    connect(m_floor2->ui->pushButton_Home, &QPushButton::clicked, this, &MainWindow::returnHome);
    connect(m_floor2->ui->pushButton_Light, &QPushButton::clicked, this, &MainWindow::floor2LightControl);
    connect(m_floor2->ui->pushButton_Curtain, &QPushButton::clicked, this, &MainWindow::floor2CurtainControl);
}

void MainWindow::topicFloor2Handler(const QString &msg)
{
    //Humidity and temperature handler
    if(msg[0] == FLOOR2_HUMIDITY)
    {
        QString subString = msg.mid(1, 4) + "%";
        m_floor2->ui->label_Humidity_Value->setText(subString);
    }else if(msg[0] == FLOOR2_TEMPERATURE)
    {
        QString subString = msg.mid(1, 4) + "℃";
        m_floor2->ui->label_Temp_Value->setText(subString);
    }

    //Light handler
    if(msg[0] == FLOOR2_CMD_LIGHT)
    {
        if(msg[1] == FLOOR2_CMD_LIGHT_ON)
        {
            m_floor2->ui->pushButton_Light->setIcon(icon_on_button);
            m_floor2->ui->pushButton_Light_Status->setIcon(icon_on_light);
        }else if(msg[1] == FLOOR2_CMD_LIGHT_OFF)
        {
            m_floor2->ui->pushButton_Light->setIcon(icon_off_button);
            m_floor2->ui->pushButton_Light_Status->setIcon(icon_off_light);
        }
    }

    //Curtain handler
    if(msg[0] == FLOOR2_CMD_CURTAIN)
    {
        if(msg[1] == FLOOR2_CMD_CURTAIN_ON)
        {
            is_floor2_led = true;
            m_floor2->ui->pushButton_Curtain->setIcon(icon_on_button);
            m_floor2->ui->pushButton_Curtain_Status->setIcon(icon_on_light);
        }else if(msg[1] == FLOOR2_CMD_CURTAIN_OFF)
        {
            is_floor2_led = false;
            m_floor2->ui->pushButton_Curtain->setIcon(icon_off_button);
            m_floor2->ui->pushButton_Curtain_Status->setIcon(icon_off_light);
        }
    }
}

void MainWindow::floor2LightControl()
{
    payload = QString(FLOOR2_CMD_LIGHT);
    is_floor2_led = !is_floor2_led;
    if(is_floor2_led)
    {
        m_floor2->ui->pushButton_Light->setIcon(icon_on_button);
        payload = payload + QString(FLOOR2_CMD_LIGHT_ON);
        m_client->publish(QMqttTopicName(TOPIC_FLOOR2), payload.toUtf8());
    }else
    {
        m_floor2->ui->pushButton_Light->setIcon(icon_off_button);
        payload = payload + QString(DOOR_CMD_LIGHT_OFF);
        m_client->publish(QMqttTopicName(TOPIC_FLOOR2), payload.toUtf8());
    }
}

void MainWindow::floor2CurtainControl()
{
    payload = QString(FLOOR2_CMD_CURTAIN);
    is_floor2_curtain = !is_floor2_curtain;
    if(is_floor2_curtain)
    {
        m_floor2->ui->pushButton_Curtain->setIcon(icon_on_button);
        payload = payload + QString(FLOOR2_CMD_CURTAIN_ON);
        m_client->publish(QMqttTopicName(TOPIC_FLOOR2), payload.toUtf8());
    }else
    {
        m_floor2->ui->pushButton_Curtain->setIcon(icon_off_button);
        payload = payload + QString(FLOOR2_CMD_CURTAIN_OFF);
        m_client->publish(QMqttTopicName(TOPIC_FLOOR2), payload.toUtf8());
    }
}
