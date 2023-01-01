#include "mainwindow.h"

void MainWindow::disconnected() {
    qDebug() << "Disconnected";
}

void MainWindow::onMessage(const QByteArray &message, const QMqttTopicName &topic)
{
    QString data = QString(message);
    if(topic == TOPIC_DOOR){
        topicDoorHandler(data);
    }

    if(topic == TOPIC_FLOOR1){
        topicFloor1Handler(data);
    }

    if(topic == TOPIC_FLOOR2){
        //topicFloor2Handler(data);
    }

    if(topic == TOPIC_FLOOR3){
        //topicFloor3Handler(data);
    }

    if(topic == TOPIC_FIREALARM){
        topicFireAlarmHandler(data);
    }

    if(topic == TOPIC_ACCOUNT){
        topicAccountHandler(data);
    }

    if(topic == TOPIC_DOOROPENCOUNTER)
    {
        topicDoorOpenCounterHandler(data);
    }
}

void MainWindow::updateLogStateChange()
{
    const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(": State Change")
                    + QString::number(m_client->state())
                    + QLatin1Char('\n');
    qDebug() << content;
}

void MainWindow::mqttClientInit(void)
{
    m_client = new QMqttClient(this);
    m_client->setHostname(HOST_NAME);
    m_client->setPort(1883);
    connect(m_client, &QMqttClient::stateChanged, this, &MainWindow::updateLogStateChange);
    if (m_client->state() == QMqttClient::Disconnected) {
        m_client->connectToHost();
    } else {
        m_client->disconnectFromHost();
    }

    delay(2000);
    if (m_client->state() == QMqttClient::Connected)
    {
        qDebug() <<"Ok";
    }

    //Subcribes to Topics
    auto subscription = m_client->subscribe(TOPIC_DOOR, 2);
    if (!subscription) {
        qDebug() << "Subcribes to topic door failed";
    }
    subscription = m_client->subscribe(TOPIC_FLOOR1, 2);
    if (!subscription) {
        qDebug() << "Subcribes to topic floor 1 failed";
    }
    subscription = m_client->subscribe(TOPIC_FLOOR2, 2);
    if (!subscription) {
        qDebug() << "Subcribes to topic floor 2 failed";
    }
    subscription = m_client->subscribe(TOPIC_FLOOR3, 2);
    if (!subscription) {
        qDebug() << "Subcribes to topic floor 1 failed";
    }
    subscription = m_client->subscribe(TOPIC_FIREALARM, 2);
    if (!subscription) {
        qDebug() << "Subcribes to topic fire alarm failed";
    }
    subscription = m_client->subscribe(TOPIC_DOOROPENCOUNTER, 2);
    if (!subscription) {
        qDebug() << "Subcribes to topic door open counter failed";
    }
    connect(m_client, &QMqttClient::disconnected, this, &MainWindow::disconnected);
    connect(m_client, &QMqttClient::messageReceived, this, &MainWindow::onMessage);
}
