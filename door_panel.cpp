#include "mainwindow.h"
#include "ui_door.h"
#include "ui_add_account.h"
#include "ui_password_panel.h"
#include "ui_opendoorcounter.h"

void MainWindow::doorInit(void)
{
    m_door = new (Door);
    m_add_account = new(Add_Account);
    m_password_panel = new(Password_Panel);
    m_open_door_counter = new(OpenDoorCounter);

    connect(m_door->ui->pushButton_Home, &QPushButton::clicked, this, &MainWindow::returnHome);
    connect(m_door->ui->pushButton_Add_Account, &QPushButton::clicked, this, &MainWindow::openAddAccountPanel);
    connect(m_door->ui->pushButton_Change_Password, &QPushButton::clicked, this, &MainWindow::openChangePasswordPanel);
    connect(m_door->ui->pushButton_Door, &QPushButton::clicked, this, &MainWindow::doorControl);
    connect(m_door->ui->pushButton_Light, &QPushButton::clicked, this, &MainWindow::lightControl);
    connect(m_password_panel->ui->pushButton_Ok, &QPushButton::clicked, this, &MainWindow::clickEnter);
    connect(m_password_panel->ui->pushButton_Cancel, &QPushButton::clicked, this, &MainWindow::clickCancel);
    connect(m_add_account->ui->pushButton_Ok, &QPushButton::clicked, this, &MainWindow::clickAddAccount);
    connect(m_add_account->ui->pushButton_Cancel, &QPushButton::clicked, this, &MainWindow::clickCancel);
    connect(m_door->ui->pushButton_Door_Open_Counter, &QPushButton::clicked, this, &MainWindow::showOpenDoorCounter);
    connect(m_open_door_counter->ui->pushButton_Ok, &QPushButton::clicked, this, &MainWindow::closeOpenDoorCounter);
    connect(m_open_door_counter->ui->pushButton_Reload, &QPushButton::clicked, this, &MainWindow::clickReload);
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
    //Esp32 return a ID code of fingerprint
    if(msg.at(0) < '0' || msg.at(0) > '9')
    {
        return;
    }
    if(msg.at(0) == '0')
    {
        user_Id = msg;
        user_Id.remove(0,1);
    }
    else {
        user_Id = msg;
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
        m_client->publish(QMqttTopicName(TOPIC_DOOR), payload.toUtf8());
    }else
    {
        m_door->ui->pushButton_Door->setIcon(icon_off_button);
        payload = payload + QString(DOOR_CMD_DOOR_CLOSE);
        m_client->publish(QMqttTopicName(TOPIC_DOOR), payload.toUtf8());
    }
}

void MainWindow::lightControl(void)
{
    payload = QString(DOOR_CMD_LIGHT);
    is_door_led = !is_door_led;
    if(is_door_led)
    {
        m_door->ui->pushButton_Light->setIcon(icon_on_button);
        payload = payload + QString(DOOR_CMD_LIGHT_ON);
        m_client->publish(QMqttTopicName(TOPIC_DOOR), payload.toUtf8());
    }else
    {
        m_door->ui->pushButton_Light->setIcon(icon_off_button);
        payload = payload + QString(DOOR_CMD_LIGHT_OFF);
        m_client->publish(QMqttTopicName(TOPIC_DOOR), payload.toUtf8());
    }
}

void MainWindow::openChangePasswordPanel(void)
{
    m_password_panel->show();
    //Clear Input Password
    input_current_password = "";
    input_new_password = "";
    input_rewrite_new_password = "";
    m_password_panel->ui->lable_PasswordStatus->setText("");
}

void MainWindow::openAddAccountPanel(void)
{
    m_add_account->ui->label_Status->setText("");
    m_add_account->ui->iDLabel->setText("");
    m_add_account->show();
}

void MainWindow::clickAddAccount()
{
    m_add_account->ui->label_Status->setText("");
    m_add_account->ui->iDLabel->setText("");
    //Get user name and ID
    user_name = m_add_account->ui->lineEdit_UserName->text();
    //Check if name is duplicated
    QSqlQuery query_search("SELECT * FROM User", Database);
    while (query_search.next()) {
        QString name = query_search.value(0).toString();
        if(name == user_name)
        {
            //TODO
            m_add_account->ui->label_Status->setText("Tên đăng ký đã trùng");
            m_add_account->ui->label_Status->setStyleSheet("QLabel {font: 75 18pt PibotoLt; color : red; }");
            return;
        }
    }
    //Send Request to esp32
    payload = "rq";
    m_client->publish(QMqttTopicName(TOPIC_ACCOUNT), payload.toUtf8());

    //Wait for fingerprint send id back
    while(user_Id == "")
    {
        delay(200);
    }
    m_add_account->ui->label_Status->setText("Đăng ký thành công");
    m_add_account->ui->label_Status->setStyleSheet("QLabel {font: 75 18pt PibotoLt; color : green; }");
    m_add_account->ui->iDLabel->setText("Id hiện tại là : " + user_Id);
    m_add_account->ui->iDLabel->setStyleSheet("QLabel { color : green; }");

    QSqlQuery query("SELECT * FROM User", Database);
    query.prepare("INSERT INTO User (name, id) "
                   "VALUES (:name, :id)");
    query.bindValue(":id", user_Id);
    query.bindValue(":name", user_name);
    if (query.exec() != true) {
        qDebug() << "write failed";
    }
    user_Id = "";
    payload = "nrq";
    m_client->publish(QMqttTopicName(TOPIC_ACCOUNT), payload.toUtf8());
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
        m_password_panel->ui->lable_PasswordStatus->setStyleSheet("QLabel {font: 75 18pt PibotoLt; color : red; }");
    }else if(m_password_panel->ui->lineEdit_NewPassword->text() == "")
    {
        m_password_panel->ui->lable_PasswordStatus->setText("Xin mời nhập đầy đủ thông tin");
        m_password_panel->ui->lable_PasswordStatus->setStyleSheet("QLabel {font: 75 18pt PibotoLt; color : red; }");
    }else if(m_password_panel->ui->lineEdit_RewriteNewPassword->text() == "")
    {
        m_password_panel->ui->lable_PasswordStatus->setText("Xin mời nhập đầy đủ thông tin");
        m_password_panel->ui->lable_PasswordStatus->setStyleSheet("QLabel {font: 75 18pt PibotoLt; color : red; }");
    }else
    {
        input_current_password = m_password_panel->ui->lineEdit_OldPassword->text();
        input_new_password = m_password_panel->ui->lineEdit_NewPassword->text();
        input_rewrite_new_password = m_password_panel->ui->lineEdit_RewriteNewPassword->text();
        //Compare current input and current password
        if(input_current_password != current_password)
        {
            m_password_panel->ui->lable_PasswordStatus->setText("Sai mật khẩu, mời nhập lại");
            m_password_panel->ui->lable_PasswordStatus->setStyleSheet("QLabel {font: 75 18pt PibotoLt; color : red; }");
            input_current_password = "";
            input_new_password = "";
            input_rewrite_new_password = "";
            return;
        }
        //Comparing complete
        if(input_new_password != input_rewrite_new_password)
        {
            m_password_panel->ui->lable_PasswordStatus->setText("Mật khẩu mới không trùng khớp");
            m_password_panel->ui->lable_PasswordStatus->setStyleSheet("QLabel {font: 75 18pt PibotoLt; color : red; }");
            input_current_password = "";
            input_new_password = "";
            input_rewrite_new_password = "";
            return;
        }

        current_password = input_new_password;

        //Save Password in SQl
        QSqlQuery query("SELECT * FROM Password", Database);
        query.prepare("INSERT INTO Password (password) "
                    "VALUES (:password)");
        query.bindValue(":password", current_password);
        if (query.exec() != true) {
            qDebug() << "write failed";
        }

        //Send MQTT Message to Topic Password
        payload = current_password;
        m_client->publish(QMqttTopicName(TOPIC_PASSWORD), payload.toUtf8());
        m_password_panel->ui->lable_PasswordStatus->setText("Thay đổi mật khẩu thành công");
        m_password_panel->ui->lable_PasswordStatus->setStyleSheet("QLabel {font: 75 18pt PibotoLt; color : green; }");
    }
}

void MainWindow::topicFirstInitHandler(const QString &msg)
{
    //response_first_init = msg;
}

