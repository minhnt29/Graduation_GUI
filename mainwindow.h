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
#include <QtVirtualKeyboard>
#include <QDate>
#include <QTime>

#include "door.h"
#include "floor1.h"
#include "floor2.h"
#include "fire_alarm.h"
#include "password_panel.h"
#include "add_account.h"
#include "opendoorcounter.h"

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
    Floor2 *m_floor2 = nullptr;
    Fire_Alarm *m_alarm = nullptr;
    Add_Account *m_add_account = nullptr;
    Password_Panel *m_password_panel = nullptr;
    OpenDoorCounter *m_open_door_counter = nullptr;
    QSerialPort *m_SerialPort = nullptr;
    QSqlDatabase Database;
    std::vector<char> buffer;

    bool is_door_led = 0,
         is_door_open = 0,
         is_floor1_led = 0,
         is_floor1_curtain = 0,
         is_floor2_led = 0,
         is_floor2_curtain = 0,
         is_floor1_fire = 0,
         is_floor2_fire = 0,
         is_floor3_fire = 0;

    QString payload = "";
    QByteArray payload_sim;
    QString current_password = "",
            input_current_password = "",
            input_new_password = "",
            input_rewrite_new_password = "",
            user_name = "",
            user_Id = "",
            response_first_init = "",
            TOPIC_DOOR = "Prj/Door",
            TOPIC_FLOOR1 = "Prj/Floor1",
            TOPIC_FLOOR2 = "Prj/Floor2",
            TOPIC_FLOOR3 = "Prj/Floor3",
            TOPIC_ACCOUNT = "Prj/Account",
            TOPIC_PASSWORD = "Prj/Password",
            TOPIC_FIREALARM = "Prj/Fire",
            TOPIC_FIRSTINIT = "Prj/FirstInit",
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

    //button handler in floor1
    void floor1CurtainControl(void);

    void floor1LightControl(void);

    //button handler in floor2
    void floor2CurtainControl(void);

    void floor2LightControl(void);

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

    void topicFirstInitHandler(const QString &msg);

    void topicDoorOpenCounterHandler(const QString &msg);

    /********************************************************************************************************
     *******                                   Helper functions                                          ****
     ********************************************************************************************************/
    void mqttClientInit(void);

    void floor1Init(void);

    void floor2Init(void);

    void doorInit(void);

    void fireAlarmInit(void);

    void moduleSimInit(void);

    void simWriteCommand(const QString &Command);

    void simWriteCommand(const QString &Command, QString &message);

    void simReadResponse();

    void serialPort_Read(void);

    void sendAlertToUser(const QString &phonenumber, const QString &floornumber);

    void sqlInit(void);

    void delay(int millisecondsToWait) const;

    void showOpenDoorCounter(void);

    void closeOpenDoorCounter(void);
    
    void clickReload(void);
    
    void updateLogStateChange();
    QIcon icon_on_button = QIcon(":/resources/on-button.png"),
          icon_off_button = QIcon(":/resources/off-button.png"),
          icon_password_show = QIcon(":/resources/show.png"),
          icon_password_hide = QIcon(":/resources/private.png"),
          icon_on_light = QIcon(":/resources/light_on.png"),
          icon_off_light = QIcon(":/resources/light_off.png");
};
#endif // MAINWINDOW_H
