#include "mainwindow.h"



void MainWindow::onConnect(struct mosquitto *mosq, void *obj, int reason_code)
{
    int rc = 0;
    qDebug() << QString("Connected successfully");

    //Subcribe topics
    rc = mosquitto_subscribe(mosq, NULL, TOPIC_DOOR, 1);
    if(rc != MOSQ_ERR_SUCCESS){
        qDebug() << QString("error subcribe");
        mosquitto_disconnect(mosq);
    }

    rc = mosquitto_subscribe(mosq, NULL, TOPIC_FLOOR1, 1);
    if(rc != MOSQ_ERR_SUCCESS){
        qDebug() << QString("error subcribe");
        mosquitto_disconnect(mosq);
    }

    rc = mosquitto_subscribe(mosq, NULL, TOPIC_FLOOR2, 1);
    if(rc != MOSQ_ERR_SUCCESS){
        qDebug() << QString("error subcribe");
        mosquitto_disconnect(mosq);
    }

    rc = mosquitto_subscribe(mosq, NULL, TOPIC_FLOOR3, 1);
    if(rc != MOSQ_ERR_SUCCESS){
        qDebug() << QString("error subcribe");
        mosquitto_disconnect(mosq);
    }

    rc = mosquitto_subscribe(mosq, NULL, TOPIC_FIREALARM, 1);
    if(rc != MOSQ_ERR_SUCCESS){
        qDebug() << QString("error subcribe");
        mosquitto_disconnect(mosq);
    }

    rc = mosquitto_subscribe(mosq, NULL, TOPIC_ACCOUNT, 1);
    if(rc != MOSQ_ERR_SUCCESS){
        qDebug() << QString("error subcribe");
        mosquitto_disconnect(mosq);
    }
}

void MainWindow::onPublish(struct mosquitto *mosq, void *obj, int mid)
{

}

//Handler data event
void MainWindow::onMessage(struct mosquitto *mosq, void *obj, const struct mosquitto_message *msg)
{
    QString data = QString((char*)msg->payload);
    if(QString(msg->topic) == TOPIC_DOOR){
        topicDoorHandler(data);
    }

    if(QString(msg->topic) == TOPIC_FLOOR1){
        topicFloor1Handler(data);
    }

    if(QString(msg->topic) == TOPIC_FLOOR2){
        //topicFloor2Handler(data);
    }

    if(QString(msg->topic) == TOPIC_FLOOR3){
        //topicFloor3Handler(data);
    }

    if(QString(msg->topic) == TOPIC_FIREALARM){
        topicFireAlarmHandler(data);
    }

    if(QString(msg->topic) == TOPIC_ACCOUNT){
        topicAccountHandler(data);
    }
}


void MainWindow::mqttClientInit(void)
{
    int rc;
    /* Required before calling other mosquitto functions */
    mosquitto_lib_init();

    /* Create a new client instance.
     * id = NULL -> ask the broker to generate a client id for us
     * clean session = true -> the broker should remove old sessions when we connect
     * obj = NULL -> we aren't passing any of our private data for callbacks
     */
    struct mosquitto *mosq;
    mosq = mosquitto_new(NULL, true, this);
    if(mosq == NULL){
        qDebug() << QString("Error in mosquitto_new");
        return;
    }
    /* Configure callbacks. This should be done before connecting ideally. */
    mosquitto_connect_callback_set(mosq, MainWindow::onConnectWrapper);
    mosquitto_publish_callback_set(mosq, MainWindow::onPublishWrapper);
    mosquitto_message_callback_set(mosq, MainWindow::onMessageWrapper);

    rc = mosquitto_connect(mosq, "test.mosquitto.org", 1883, 60);
    if(rc != MOSQ_ERR_SUCCESS){
        mosquitto_destroy(mosq);
        fprintf(stderr, "Error: %s\n", mosquitto_strerror(rc));
        return;
    }
    rc = mosquitto_loop_start(mosq);
    if(rc != MOSQ_ERR_SUCCESS){
        mosquitto_destroy(mosq);
        fprintf(stderr, "Error: %s\n", mosquitto_strerror(rc));
        return;
    }

}

