#include "mainwindow.h"
#include "ui_door.h"

void MainWindow::doorInit(void)
{
    m_door = new (Door);
    m_add_account = new(Add_Account);
    m_password_panel = new(Password_Panel);
    connect(m_door->ui->pushButton_Home, &QPushButton::clicked, this, &MainWindow::returnHome);
    connect(m_door->ui->pushButton_Add_Account, &QPushButton::clicked, this, &MainWindow::openAddAccountPanel);
    connect(m_door->ui->pushButton_Change_Password, &QPushButton::clicked, this, &MainWindow::openChangePasswordPanel);
    connect(m_door->ui->pushButton_Door, &QPushButton::clicked, this, &MainWindow::doorControl);
    connect(m_door->ui->pushButton_Light, &QPushButton::clicked, this, &MainWindow::lightControl);
    connect(m_password_panel->ui->pushButton_Ok, &QPushButton::clicked, this, &MainWindow::clickEnter);
    connect(m_password_panel->ui->pushButton_Cancel, &QPushButton::clicked, this, &MainWindow::clickCancel);
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

void MainWindow::openChangePasswordPanel(void)
{
    m_password_panel->show();
    //Clear Input Password
    input_current_password = "";
    input_new_password = "";
    input_rewrite_new_password = "";
}

void MainWindow::openAddAccountPanel(void)
{
    m_add_account->show();
}

void MainWindow::clickCancel(void)
{
    //TODO
    input_current_password = "";
    input_new_password = "";
    input_rewrite_new_password = ""; 
    m_password_panel->hide();
}

void MainWindow::clickEnter()
{

    //Check password or new password
    if(m_password_panel->ui->   )
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

    if(input_current_password == current_password)
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

void MainWindow::showInputPassword()
{
    QString hiden_password = "";
    for(int i = 0; i< input_current_password.size(); i++)
    {
        hiden_password = hiden_password + "*";
    }
}

void MainWindow::showOrHidePassword()
{
    is_password_hide = !is_password_hide;
    showInputPassword();
}

