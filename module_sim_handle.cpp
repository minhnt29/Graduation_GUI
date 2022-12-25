#include "mainwindow.h"

QString HOME_OWNER_PHONE = "0913578636",
        SIM_CHECK_OK = "AT",
        SIM_CALL_HOME_OWNER = "ATD" + HOME_OWNER_PHONE + ";<CR><LF>",
        SIM_CALL_NO_DIAGTONE = "NO DIAGTONE",
        SIM_CALL_BUSY = "BUSY",
        SIM_CALL_NO_CARRIER = "NO CARRIER",
        SIM_CALL_NO_ANSWER = "NO ANSWER";
//        SIM_MESSAGE_ALERT = "AT+CMGS="0913578636"";

void MainWindow::moduleSimInit(void)
{
    m_SerialPort = new (QSerialPort);
    //Config for COM port
    m_SerialPort->setPortName("ttyUSB0");
    m_SerialPort->setBaudRate(QSerialPort::Baud115200);
    m_SerialPort->setDataBits(QSerialPort::Data8);
    m_SerialPort->setParity(QSerialPort::NoParity);
    m_SerialPort->setStopBits(QSerialPort::OneStop);
    m_SerialPort->setFlowControl(QSerialPort::NoFlowControl);

    if(m_SerialPort->open(QIODevice::ReadWrite) != true){
        qDebug("Error open");
        return ;
    }
}

void MainWindow::sendAlertToUser(const QString &phonenumber, const quint32 &floornumber)
{
    m_SerialPort->write(SIM_CALL_HOME_OWNER.toStdString().c_str());
}
