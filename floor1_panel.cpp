#include "mainwindow.h"
#include "ui_floor1.h"


void MainWindow::floor1Init(void)
{
    m_floor1 = new (Floor1);
    m_floor1->ui->pushButton_Light_Status->setIcon(icon_off_light);
    m_floor1->ui->pushButton_Curtain_Status->setIcon(icon_off_light);
    connect(m_floor1->ui->pushButton_Home, &QPushButton::clicked, this, &MainWindow::returnHome);
    connect(m_floor1->ui->pushButton_Light, &QPushButton::clicked, this, &MainWindow::floor1LightControl);
    connect(m_floor1->ui->pushButton_Curtain, &QPushButton::clicked, this, &MainWindow::floor1CurtainControl);
}

void MainWindow::returnHome()
{
    this->show();
    m_door->hide();
    m_floor1->hide();
    m_floor2->hide();
}

void MainWindow::topicFloor1Handler(const QString &msg)
{
    //Humidity and temperature handler
    if(msg[0] == FLOOR1_HUMIDITY)
    {
        QString subString = msg.mid(1, 4);
        m_floor1->ui->label_Humidity_Value->setText(subString);
    }else if(msg[0] == FLOOR1_TEMPERATURE)
    {
        QString subString = msg.mid(1, 4);
        m_floor1->ui->label_Temp_Value->setText(subString);
    }

    //Light handler
    if(msg[0] == FLOOR1_CMD_LIGHT)
    {
        if(msg[1] == FLOOR1_CMD_LIGHT_ON)
        {
            m_floor1->ui->pushButton_Light->setIcon(icon_on_button);
            m_floor1->ui->pushButton_Light_Status->setIcon(icon_on_light);
        }else if(msg[1] == FLOOR1_CMD_LIGHT_OFF)
        {
            m_floor1->ui->pushButton_Light->setIcon(icon_off_button);
            m_floor1->ui->pushButton_Light_Status->setIcon(icon_off_light);
        }
    }

    //Curtain handler
    if(msg[0] == FLOOR1_CMD_CURTAIN)
    {
        if(msg[1] == FLOOR1_CMD_CURTAIN_ON)
        {
            is_floor1_led = true;
            m_floor1->ui->pushButton_Curtain->setIcon(icon_on_button);
            m_floor1->ui->pushButton_Curtain_Status->setIcon(icon_on_light);
        }else if(msg[1] == FLOOR1_CMD_CURTAIN_OFF)
        {
            is_floor1_led = false;
            m_floor1->ui->pushButton_Curtain->setIcon(icon_off_button);
            m_floor1->ui->pushButton_Curtain_Status->setIcon(icon_off_light);
        }
    }
}

void MainWindow::floor1LightControl()
{
    payload = QString(FLOOR1_CMD_LIGHT);
    is_floor1_led = !is_floor1_led;
    if(is_floor1_led)
    {
        m_floor1->ui->pushButton_Light->setIcon(icon_on_button);
        payload = payload + QString(FLOOR1_CMD_LIGHT_ON);
        m_client->publish(QMqttTopicName(TOPIC_FLOOR1), payload.toUtf8());
    }else
    {
        m_floor1->ui->pushButton_Light->setIcon(icon_off_button);
        payload = payload + QString(DOOR_CMD_LIGHT_OFF);
        m_client->publish(QMqttTopicName(TOPIC_FLOOR1), payload.toUtf8());
    }
}

void MainWindow::floor1CurtainControl()
{
    payload = QString(FLOOR1_CMD_CURTAIN);
    is_floor1_curtain = !is_floor1_curtain;
    if(is_floor1_curtain)
    {
        m_floor1->ui->pushButton_Curtain->setIcon(icon_on_button);
        payload = payload + QString(FLOOR1_CMD_CURTAIN_ON);
        m_client->publish(QMqttTopicName(TOPIC_FLOOR1), payload.toUtf8());
    }else
    {
        m_floor1->ui->pushButton_Curtain->setIcon(icon_off_button);
        payload = payload + QString(FLOOR1_CMD_CURTAIN_OFF);
        m_client->publish(QMqttTopicName(TOPIC_FLOOR1), payload.toUtf8());
    }
}
