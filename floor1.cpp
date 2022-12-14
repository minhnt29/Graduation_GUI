#include "floor1.h"
#include "ui_floor1.h"

Floor1::Floor1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Floor1)
{
    ui->setupUi(this);
}

Floor1::~Floor1()
{
    delete ui;
}

