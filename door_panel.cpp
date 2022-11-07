#include "mainwindow.h"
#include "ui_door.h"
#include "ui_add_account.h"
#include "ui_password_panel.h"

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
    connect(m_add_account->ui->pushButton_Ok, &QPushButton::clicked, this, &MainWindow::clickAddAccount);
    connect(m_add_account->ui->pushButton_Cancel, &QPushButton::clicked, this, &MainWindow::clickCancel);
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

void MainWindow::topicAccountHandler(const QString &msg)
{
    //@TODO
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

void MainWindow::clickAddAccount()
{
    //Get user name and ID
    user_name = m_add_account->ui->lineEdit_UserName->text();
    user_Id = m_add_account->ui->lineEdit_UserID->text();
    //Send ID to TOPIC_ACCOUNT
    int rc = mosquitto_publish(mosq, NULL, TOPIC_DOOR, user_Id.length(), user_Id.toStdString().c_str(), 2, false);
    if(rc != MOSQ_ERR_SUCCESS)
    {
        qDebug() << "publish error";
    }
}

void MainWindow::clickCancel(void)
{
    input_current_password = "";
    input_new_password = "";
    input_rewrite_new_password = ""; 
    m_password_panel->hide();
    m_add_account->hide();
}

void MainWindow::clickEnter()
{

    //Check password or new password
    if(m_password_panel->ui->lineEdit_OldPassword->text() == "")
    {
        m_password_panel->ui->lable_PasswordStatus->setText("Xin mời nhập đầy đủ thông tin");
    }else if(m_password_panel->ui->lineEdit_NewPassword->text() == "")
    {
        m_password_panel->ui->lable_PasswordStatus->setText("Xin mời nhập đầy đủ thông tin");
    }else if(m_password_panel->ui->lineEdit_RewriteNewPassword->text() == "")
    {
        m_password_panel->ui->lable_PasswordStatus->setText("Xin mời nhập đầy đủ thông tin");
    }else
    {
        input_current_password = m_password_panel->ui->lineEdit_OldPassword->text();
        input_new_password = m_password_panel->ui->lineEdit_NewPassword->text();
        input_rewrite_new_password = m_password_panel->ui->lineEdit_RewriteNewPassword->text();
        //Compare current input and current password
        if(input_current_password != current_password)
        {
            m_password_panel->ui->lable_PasswordStatus->setText("Sai mật khẩu, mời nhập lại");
            input_current_password = "";
            input_new_password = "";
            input_rewrite_new_password = "";
            return;
        }
        //Comparing complete
        if(input_new_password != input_rewrite_new_password)
        {
            m_password_panel->ui->lable_PasswordStatus->setText("Mật khẩu mới không trùng khớp");
            input_current_password = "";
            input_new_password = "";
            input_rewrite_new_password = "";
            return;
        }

        current_password = input_new_password;

        //Send MQTT Message to Topic Password
        payload = current_password;
        int rc = mosquitto_publish(mosq, NULL, TOPIC_PASSWORD, payload.length(), payload.toStdString().c_str(), 2, false);
        if(rc != MOSQ_ERR_SUCCESS)
        {
            m_password_panel->ui->lable_PasswordStatus->setText("Kiểm tra lại kết nối");
        }
        m_password_panel->ui->lable_PasswordStatus->setText("Thay đổi mật khẩu thành công");
    }
}


