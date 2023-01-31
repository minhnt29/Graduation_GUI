#include "mainwindow.h"

QString
        SIM_CHECK_OK = "AT\r\n",
        SIM_CALL_NO_DIAGTONE = "NO DIAGTONE",
        SIM_CALL_BUSY = "BUSY",
        SIM_CALL_NO_CARRIER = "NO CARRIER",
        SIM_CALL_NO_ANSWER = "NO ANSWER",
        SIM_SET_TEXT = "AT+CMGF=1\r\n",
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
//    m_SerialPort->write(SIM_DIS_RESPONSE_CANCEL.toStdString().c_str(), SIM_DIS_RESPONSE_CANCEL.length());
//    delay(300);
//    qDebug() << QString(payload_sim);
//    payload_sim = "";
}

void MainWindow::sendAlertToUser(const QString &phonenumber, const QString &floornumber)
{
    simWriteCommand(SIM_SET_TEXT);
    QString SIM_SEND_MSG = "AT+CMGS=\"" + phonenumber + "\"\r\n";
    QString SIM_MSG = "DANG CO CHAY O TANG " + floornumber + ", KIEM TRA NGAY LAP TUC";
    simWriteCommand(SIM_SEND_MSG, SIM_MSG);
    delay(4000);
    QString SIM_CALL_HOME_OWNER = "ATD" + phonenumber + ";\r\n";
    simWriteCommand(SIM_CALL_HOME_OWNER);
}

void MainWindow::simWriteCommand(const QString &Command) {
    m_SerialPort->write(Command.toStdString().c_str(), Command.length());
    delay(100);
    qDebug() << QString(payload_sim);
    buffer.clear();
    payload_sim = "";
}

void MainWindow::simWriteCommand(const QString &Command, QString &message) {
    m_SerialPort->write(Command.toStdString().c_str(), Command.length());
    delay(100);
    message.append(0x1A);
    m_SerialPort->write(message.toStdString().c_str(), message.length());
    delay(100);
    qDebug() << QString(payload_sim);
    buffer.clear();
    payload_sim = "";
}

void MainWindow::simReadResponse() {

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
