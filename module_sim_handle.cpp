#include "mainwindow.h"

QString HOME_OWNER_PHONE = "0868881527",
        SIM_CHECK_OK = "AT\r\n",
        SIM_CALL_HOME_OWNER = "ATD0868881527;\r\n" ,
        SIM_CALL_NO_DIAGTONE = "NO DIAGTONE",
        SIM_CALL_BUSY = "BUSY",
        SIM_CALL_NO_CARRIER = "NO CARRIER",
        SIM_CALL_NO_ANSWER = "NO ANSWER",
        SIM_SET_TEXT = "AT+CMGF=1\r\n",
        SIM_SEND_MSG = "AT+CMGS=0913578636\r\n",
        SIM_CALL_CANCEL = "ATH\r\n",
        SIM_DIS_RESPONSE_CANCEL = "ATE0\r\n";
//        SIM_MESSAGE_ALERT = "AT+CMGS="0913578636"";

void MainWindow::moduleSimInit(void)
{
    m_SerialPort = new (QSerialPort);
    //Config for COM port
    m_SerialPort->setPortName("/dev/ttyUSB0");
    m_SerialPort->setBaudRate(QSerialPort::Baud19200);
    m_SerialPort->setDataBits(QSerialPort::Data8);
    m_SerialPort->setParity(QSerialPort::NoParity);
    m_SerialPort->setStopBits(QSerialPort::OneStop);
    m_SerialPort->setFlowControl(QSerialPort::NoFlowControl);

    if(m_SerialPort->open(QIODevice::ReadWrite) != true){
        qDebug("Error open");
        return ;
    }
    connect(m_SerialPort, &QSerialPort::readyRead, this, &MainWindow::serialPort_Read);
    m_SerialPort->write(SIM_DIS_RESPONSE_CANCEL.toStdString().c_str(), SIM_DIS_RESPONSE_CANCEL.length());
    delay(300);
    qDebug() << QString(payload_sim);
    payload_sim.clear();
}

void MainWindow::sendAlertToUser(const QString &phonenumber, const QString &floornumber)
{
    m_SerialPort->write(SIM_CALL_HOME_OWNER.toStdString().c_str(), SIM_CALL_HOME_OWNER.length());
    delay(10000);
    qDebug() << QString(payload_sim);
    payload_sim.clear();
    m_SerialPort->write(SIM_CALL_CANCEL.toStdString().c_str(), SIM_CALL_CANCEL.length());
    delay(300);
    qDebug() << QString(payload_sim);
    payload_sim.clear();
}

void MainWindow::serialPort_Read()
{
    auto available_bytes = m_SerialPort->bytesAvailable();
    if (!available_bytes) {
        return;
    }
    std::vector<char> temp(available_bytes);
    m_SerialPort->read(temp.data(), available_bytes);
    std::copy(temp.begin(), temp.end(), std::back_inserter(buffer));
    payload_sim = QByteArray(reinterpret_cast<const char*>(buffer.data()), buffer.size());

}
