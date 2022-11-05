#include "door.h"
#include "ui_door.h"

Door::Door(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Door)
{
    ui->setupUi(this);
}

Door::~Door()
{
    delete ui;
}
