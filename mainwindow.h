#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QIcon>
#include <QDebug>

#include <QString>
#include <QSql>
#include <QSqlQuery>
#include <QtCore/QDateTime>
#include <QtMqtt/QMqttClient>
#include <QSerialPort>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSql>

#include "door.h"
#include "floor1.h"
#include "fire_alarm.h"
#include "password_panel.h"
#include "add_account.h"

//#include <QtVirtualKeyboard>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


/********************************************************************************************************
 ********                                 List Command                                             ******
 ********************************************************************************************************/



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    Ui::MainWindow *ui;
    QMqttClient *m_client;
    Door *m_door = nullptr;
    Floor1 *m_floor1 = nullptr;
    Fire_Alarm *m_alarm = nullptr;
    Add_Account *m_add_account = nullptr;
    Password_Panel *m_password_panel = nullptr;
    QSerialPort *m_SerialPort = nullptr;
    QSqlDatabase Database;

    bool is_door_led = 0,
         is_door_open = 0,
         is_floor1_led = 0,
         is_floor1_curtain = 0;

    QString payload = "";
    QString current_password = "",
            input_current_password = "",
            input_new_password = "",
            input_rewrite_new_password = "",
            user_name = "",
            user_Id = "",
            HOST_NAME = "test.mosquitto.org",
            TOPIC_DOOR = "Prj/Door",
            TOPIC_FLOOR1 = "Prj/Floor1",
            TOPIC_FLOOR2 = "Prj/Floor2",
            TOPIC_FLOOR3 = "Prj/Floor3",
            TOPIC_ACCOUNT = "Prj/Account",
            TOPIC_PASSWORD = "Prj/Password",
            TOPIC_FIREALARM = "Prj/Fire",
            TOPIC_DOOROPENCOUNTER = "Prj/DoorOpenCounter";
    /********************************************************************************************************
     ********                               Button handlers in panels                                  ******
     ********************************************************************************************************/

    //button handler in mainwindow
    void openDoorControl(void);

    void openFloor1Control(void);

    void openFloor2Control(void);

    void openFloor3Control(void);

    //button handler in door

    void lightControl(void);

    void openChangePasswordPanel(void);

    void doorControl(void);

    void openAddAccountPanel(void);

    void returnHome(void);

    void clickEnter(void);

    void clickCancel(void);

    void clickAddAccount(void);

    //button handler in floors
    void floor1CurtainControl(void);

    void floor1LightControl(void);

    /********************************************************************************************************
     *******                                MQTT handlers in panels                                      ****
     ********************************************************************************************************/
    void disconnected();

    void onMessage(const QByteArray &message, const QMqttTopicName &topic);

    void topicDoorHandler(const QString &msg);

    void topicFloor1Handler(const QString &msg);

    void topicFloor2Handler(const QString &msg);

    void topicFloor3Handler(const QString &msg);

    void topicFireAlarmHandler(const QString &msg);

    void topicAccountHandler(const QString &msg);


    /********************************************************************************************************
     *******                                   Helper functions                                          ****
     ********************************************************************************************************/
    void mqttClientInit(void);

    void floor1Init(void);

    void doorInit(void);

    void fireAlarmInit(void);

    void moduleSimInit(void);

    void sendAlertToUser(const QString &phonenumber, const quint32 &floornumber);

    void sqlInit(void);

    void delay(int millisecondsToWait) const;

    void updateLogStateChange();
    QIcon icon_on_button = QIcon(":/resources/on-button.png"),
          icon_off_button = QIcon(":/resources/off-button.png"),
          icon_password_show = QIcon(":/resources/show.png"),
          icon_password_hide = QIcon(":/resources/private.png"),
          icon_on_light = QIcon(":/resources/light_on.png"),
          icon_off_light = QIcon(":/resources/lght_off.png");
};
#endif // MAINWINDOW_H
