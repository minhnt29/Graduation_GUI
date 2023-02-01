#include "floor2.h"
#include "ui_floor2.h"

Floor2::Floor2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Floor2)
{
    ui->setupUi(this);
}

Floor2::~Floor2()
{
    delete ui;
}

