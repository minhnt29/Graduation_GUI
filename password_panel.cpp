#include "password_panel.h"
#include "ui_password_panel.h"

Password_Panel::Password_Panel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Password_Panel)
{
    ui->setupUi(this);
}

Password_Panel::~Password_Panel()
{
    delete ui;
}
