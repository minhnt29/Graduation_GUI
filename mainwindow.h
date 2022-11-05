#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QIcon>
#include "door.h"
#include "floor1.h"
#include "fire_alarm.h"
#include "mosquitto.h"
#include <QDebug>
#include <QString>
//#include <QtVirtualKeyboard>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#define TOPIC_DOOR  "Prj/Door"
#define TOPIC_FLOOR1  "Prj/Floor1"
#define TOPIC_FLOOR2  "Prj/Floor2"
#define TOPIC_FLOOR3  "Prj/Floor3"
#define TOPIC_ACCOUNT  "Prj/Account"
#define TOPIC_PASSWORD  "Prj/Password"
#define TOPIC_FIREALARM "Prj/Fire"

/********************************************************************************************************
 ********                                 List Command                                             ******
 ********************************************************************************************************/

constexpr auto DOOR_CMD_LIGHT = '1';
constexpr auto DOOR_CMD_LIGHT_ON = '1';
constexpr auto DOOR_CMD_LIGHT_OFF = '0';
constexpr auto DOOR_CMD_DOOR = '2';
constexpr auto DOOR_CMD_DOOR_OPEN = '1';
constexpr auto DOOR_CMD_DOOR_CLOSE = '0';
constexpr auto DOOR_CMD_DOOR_KEYPAD = '3';
constexpr auto DOOR_CMD_DOOR_CHANGEPASSWORD = '0';
constexpr auto DOOR_CMD_DOOR_ADDACCOUNT = '1';

constexpr auto FLOOR1_CMD_LIGHT = '4';
constexpr auto FLOOR2_CMD_LIGHT_ON = '1';
constexpr auto FLOOR2_CMD_LIGHT_OFF = '0';



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    Ui::MainWindow *ui;
    Door *m_door = nullptr;
    Floor1 *m_floor1 = nullptr;
    Fire_Alarm *m_alarm = nullptr;

    bool is_door_led = 0,
         is_door_open = 0,
         is_password_hide = 1,
         is_check_or_new_password = 0; //check password = 0 and new password = 1;

    QString payload = "";
    QString current_password = "1234",
            input_password = "";
    struct mosquitto *mosq;
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

    void changePassword(void);

    void doorControl(void);

    void addAccount(void);

    void returnHome(void);

    void click0(void);

    void click1(void);

    void click2(void);

    void click3(void);

    void click4(void);

    void click5(void);

    void click6(void);

    void click7(void);

    void click8(void);

    void click9(void);

    void clickA(void);

    void clickB(void);

    void clickDelete(void);

    void clickEnter(void);

    void showOrHidePassword(void);

    void showInputPassword(void);

    void setKeyboardAvailable(void);

    void setKeyboardDisable(void);

    //button handler in floors
    void curtainControl(void);

    void lightFloorControl(void);

    /********************************************************************************************************
     *******                                MQTT handlers in panels                                      ****
     ********************************************************************************************************/
    void onMessage(struct mosquitto *mosq, void *obj, const struct mosquitto_message *msg);

    void onConnect(struct mosquitto *mosq, void *obj, int reason_code);

    void onPublish(struct mosquitto *mosq, void *obj, int mid);

    static void onConnectWrapper(struct mosquitto *mosq, void *obj, int reason_code) {
          MainWindow* instance = static_cast<MainWindow*>(obj);
          instance->onConnect(mosq, obj, reason_code);
    };

    static void onPublishWrapper(struct mosquitto *mosq, void *obj, int mid) {
        MainWindow* instance = static_cast<MainWindow*>(obj);
        instance->onPublish(mosq, obj, mid);
    };

    static void onMessageWrapper(struct mosquitto *mosq, void *obj, const struct mosquitto_message *msg) {
        MainWindow* instance = static_cast<MainWindow*>(obj);
        instance->onMessage(mosq, obj, msg);
    };

    void topicDoorHandler(const QString &msg);

    void topicFloor1Handler(const QString &msg);

    void topicFloor2Handler(const QString &msg);

    void topicFloor3Handler(const QString &msg);

    void topicFireAlarmHandler(const QString &msg);


    /********************************************************************************************************
     *******                                   Helper functions                                          ****
     ********************************************************************************************************/
    void mqttClientInit(void);

    void floor1Init(void);

    void doorInit(void);

    void fireAlarmInit(void);

    void delay(int millisecondsToWait) const;

    QIcon icon_on_button = QIcon(":/resources/on-button.png"),
          icon_off_button = QIcon(":/resources/off-button.png"),
          icon_password_show = QIcon(":/resources/show.png"),
          icon_password_hide = QIcon(":/resources/private.png");
};
#endif // MAINWINDOW_H
