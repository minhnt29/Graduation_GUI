#include "mainwindow.h"
#include "ui_door.h"

void MainWindow::doorInit(void)
{
    m_door = new (Door);
    connect(m_door->ui->pushButton_Home, &QPushButton::clicked, this, &MainWindow::returnHome);
    connect(m_door->ui->pushButton_Add_Account, &QPushButton::clicked, this, &MainWindow::addAccount);
    connect(m_door->ui->pushButton_Change_Password, &QPushButton::clicked, this, &MainWindow::changePassword);
    connect(m_door->ui->pushButton_Door, &QPushButton::clicked, this, &MainWindow::doorControl);
    connect(m_door->ui->pushButton_Light, &QPushButton::clicked, this, &MainWindow::lightControl);
    connect(m_door->ui->pushButton_num0, &QPushButton::clicked, this, &MainWindow::click0);
    connect(m_door->ui->pushButton_num1, &QPushButton::clicked, this, &MainWindow::click1);
    connect(m_door->ui->pushButton_num2, &QPushButton::clicked, this, &MainWindow::click2);
    connect(m_door->ui->pushButton_num3, &QPushButton::clicked, this, &MainWindow::click3);
    connect(m_door->ui->pushButton_num4, &QPushButton::clicked, this, &MainWindow::click4);
    connect(m_door->ui->pushButton_num5, &QPushButton::clicked, this, &MainWindow::click5);
    connect(m_door->ui->pushButton_num6, &QPushButton::clicked, this, &MainWindow::click6);
    connect(m_door->ui->pushButton_num7, &QPushButton::clicked, this, &MainWindow::click7);
    connect(m_door->ui->pushButton_num8, &QPushButton::clicked, this, &MainWindow::click8);
    connect(m_door->ui->pushButton_num9, &QPushButton::clicked, this, &MainWindow::click9);
    connect(m_door->ui->pushButton_CharA, &QPushButton::clicked, this, &MainWindow::clickA);
    connect(m_door->ui->pushButton_CharB, &QPushButton::clicked, this, &MainWindow::clickB);
    connect(m_door->ui->pushButton_Delete, &QPushButton::clicked, this, &MainWindow::clickDelete);
    connect(m_door->ui->pushButton_Enter, &QPushButton::clicked, this, &MainWindow::clickEnter);
    connect(m_door->ui->pushButton, &QPushButton::clicked, this, &MainWindow::showOrHidePassword);

    setKeyboardDisable();
}

void MainWindow::topicDoorHandler(const QString &msg)
{
    if(msg[0] == DOOR_CMD_LIGHT)
    {
        if(msg[1] == DOOR_CMD_LIGHT_ON)
        {
            is_door_led = 1;
            m_door->ui->pushButton_Light->setIcon(icon_on_button);
        }else if(msg[1] == DOOR_CMD_LIGHT_OFF)
        {
            is_door_led = 0;
            m_door->ui->pushButton_Light->setIcon(icon_off_button);
        }
    }else if(msg[0] == DOOR_CMD_DOOR)
    {
        if(msg[1] == DOOR_CMD_DOOR_OPEN)
        {
            is_door_open = 1;
            m_door->ui->pushButton_Door->setIcon(icon_on_button);
        }else if(msg[1] == DOOR_CMD_DOOR_CLOSE)
        {
            is_door_open = 0;
            m_door->ui->pushButton_Door->setIcon(icon_off_button);
        }
    }
}

void MainWindow::doorControl(void)
{
    payload = QString(DOOR_CMD_DOOR);
    is_door_open = !is_door_open;
    if(is_door_open)
    {
        m_door->ui->pushButton_Door->setIcon(icon_on_button);
        payload = payload + QString(DOOR_CMD_DOOR_OPEN);
        int rc = mosquitto_publish(mosq, NULL, TOPIC_DOOR, payload.length(), payload.toStdString().c_str(), 2, false);
        if(rc != MOSQ_ERR_SUCCESS)
        {
            qDebug() << "publish error";
        }
    }else
    {
        m_door->ui->pushButton_Door->setIcon(icon_off_button);
        payload = payload + QString(DOOR_CMD_DOOR_CLOSE);
        int rc = mosquitto_publish(mosq, NULL, TOPIC_DOOR, payload.length(), payload.toStdString().c_str(), 2, false);
        if(rc != MOSQ_ERR_SUCCESS)
        {
            qDebug() << "publish error";
        }
    }
    m_door->ui->pushButton_Door->setDisabled(1);
    delay(1000);
    m_door->ui->pushButton_Door->setDisabled(0);

}

void MainWindow::lightControl(void)
{
    payload = QString(DOOR_CMD_LIGHT);
    is_door_led = !is_door_led;
    if(is_door_led)
    {
        m_door->ui->pushButton_Light->setIcon(icon_on_button);
        payload = payload + QString(DOOR_CMD_LIGHT_ON);
        int rc = mosquitto_publish(mosq, NULL, TOPIC_DOOR, payload.length(), payload.toStdString().c_str(), 2, false);
        if(rc != MOSQ_ERR_SUCCESS)
        {
            qDebug() << "publish error";
        }
    }else
    {
        m_door->ui->pushButton_Light->setIcon(icon_off_button);
        payload = payload + QString(DOOR_CMD_LIGHT_OFF);
        int rc = mosquitto_publish(mosq, NULL, TOPIC_DOOR, payload.length(), payload.toStdString().c_str(), 2, false);
        if(rc != MOSQ_ERR_SUCCESS)
        {
            qDebug() << "publish error";
        }
    }
    m_door->ui->pushButton_Light->setDisabled(1);
    delay(1000);
    m_door->ui->pushButton_Light->setDisabled(0);
}

void MainWindow::changePassword(void)
{
    setKeyboardAvailable();
    //Clear Input Password
    input_password = "";

    //Notifycation for user
    m_door->ui->label_PasswordNotification->setText("Xin mời bạn hãy nhập mật khẩu cũ");
}

void MainWindow::addAccount(void)
{
    //@TODO
    setKeyboardAvailable();
}

void MainWindow::click0()
{
    input_password = input_password + "0";
    showInputPassword();
}

void MainWindow::click1()
{
    input_password = input_password + "1";
    showInputPassword();
}

void MainWindow::click2()
{
    input_password = input_password + "2";
    showInputPassword();
}

void MainWindow::click3()
{
    input_password = input_password + "3";
    showInputPassword();
}

void MainWindow::click4()
{
    input_password = input_password + "4";
    showInputPassword();
}

void MainWindow::click5()
{
    input_password = input_password + "5";
    showInputPassword();
}

void MainWindow::click6()
{
    input_password = input_password + "6";
    showInputPassword();
}

void MainWindow::click7()
{
    input_password = input_password + "7";
    showInputPassword();
}

void MainWindow::click8()
{
    input_password = input_password + "8";
    showInputPassword();
}

void MainWindow::click9()
{
    input_password = input_password + "9";
    showInputPassword();
}

void MainWindow::clickA()
{
    input_password = input_password + "A";
    showInputPassword();
}

void MainWindow::clickB()
{
    input_password = input_password + "B";
    showInputPassword();
}

void MainWindow::clickDelete()
{
    input_password = input_password.remove(input_password.size() - 1, 1);
    qDebug() << input_password;
    showInputPassword();
}

void MainWindow::clickEnter()
{

    //Check password or new password
    if(is_check_or_new_password == 1)
    {
        if(input_password == "")
        {
            m_door->ui->label_PasswordNotification->setText("Chưa nhập mật khẩu, xin mời nhập lại");
        }else
        {
            current_password = input_password;
            input_password = "";

            //Send MQTT Message to Topic Password
            payload =  current_password;
            //@TODO
            int rc = mosquitto_publish(mosq, NULL, TOPIC_PASSWORD, payload.length(), payload.toStdString().c_str(), 2, false);
            if(rc != MOSQ_ERR_SUCCESS)
            {
                m_door->ui->label_PasswordNotification->setText("Kiểm tra lại kết nối");
            }
            m_door->ui->label_PasswordNotification->setText("Thay đổi mật khẩu thành công");
            setKeyboardDisable();
        }
    }
    if(is_check_or_new_password == 0)
    {
        if(input_password == current_password)
        {
            is_check_or_new_password = !is_check_or_new_password;
            m_door->ui->label_PasswordNotification->setText("Chính xác, mời nhập mật khẩu mới ");
            input_password = "";
        }else
        {
            input_password = "";
            m_door->ui->label_PasswordNotification->setText("Không chính xác, mời nhập lại mật khẩu");
        }
    }
}

void MainWindow::showInputPassword()
{
    QString hiden_password = "";
    for(int i = 0; i< input_password.size(); i++)
    {
        hiden_password = hiden_password + "*";
    }
    m_door->ui->label_PasswordNotification->setText("Đang nhập : " + ((is_password_hide == true) ? hiden_password : input_password));
}

void MainWindow::showOrHidePassword()
{
    is_password_hide = !is_password_hide;
    showInputPassword();
}

void MainWindow::setKeyboardDisable()
{
    m_door->ui->pushButton_num0->setDisabled(1);
    m_door->ui->pushButton_num1->setDisabled(1);
    m_door->ui->pushButton_num2->setDisabled(1);
    m_door->ui->pushButton_num3->setDisabled(1);
    m_door->ui->pushButton_num4->setDisabled(1);
    m_door->ui->pushButton_num5->setDisabled(1);
    m_door->ui->pushButton_num6->setDisabled(1);
    m_door->ui->pushButton_num7->setDisabled(1);
    m_door->ui->pushButton_num8->setDisabled(1);
    m_door->ui->pushButton_num9->setDisabled(1);
    m_door->ui->pushButton_CharA->setDisabled(1);
    m_door->ui->pushButton_CharB->setDisabled(1);
    m_door->ui->pushButton_Delete->setDisabled(1);
    m_door->ui->pushButton_Enter->setDisabled(1);
    m_door->ui->pushButton_CharStar->setDisabled(1);
    m_door->ui->pushButton_Char_Hash->setDisabled(1);
}

void MainWindow::setKeyboardAvailable()
{
    m_door->ui->pushButton_num0->setEnabled(1);
    m_door->ui->pushButton_num1->setEnabled(1);
    m_door->ui->pushButton_num2->setEnabled(1);
    m_door->ui->pushButton_num3->setEnabled(1);
    m_door->ui->pushButton_num4->setEnabled(1);
    m_door->ui->pushButton_num5->setEnabled(1);
    m_door->ui->pushButton_num6->setEnabled(1);
    m_door->ui->pushButton_num7->setEnabled(1);
    m_door->ui->pushButton_num8->setEnabled(1);
    m_door->ui->pushButton_num9->setEnabled(1);
    m_door->ui->pushButton_CharA->setEnabled(1);
    m_door->ui->pushButton_CharB->setEnabled(1);
    m_door->ui->pushButton_Delete->setEnabled(1);
    m_door->ui->pushButton_Enter->setEnabled(1);
    m_door->ui->pushButton_CharStar->setEnabled(1);
    m_door->ui->pushButton_Char_Hash->setEnabled(1);
}
