#include "add_account.h"
#include "ui_add_account.h"

Add_Account::Add_Account(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_Account)
{
    ui->setupUi(this);
}

Add_Account::~Add_Account()
{
    delete ui;
}
