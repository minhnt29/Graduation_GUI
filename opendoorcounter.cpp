#include "opendoorcounter.h"
#include "ui_opendoorcounter.h"

OpenDoorCounter::OpenDoorCounter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenDoorCounter)
{
    ui->setupUi(this);
}

OpenDoorCounter::~OpenDoorCounter()
{
    delete ui;
}
