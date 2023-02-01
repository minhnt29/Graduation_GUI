#ifndef FLOOR2_H
#define FLOOR2_H

#include <QWidget>

constexpr auto FLOOR2_CMD_LIGHT = '1';
constexpr auto FLOOR2_CMD_LIGHT_ON = '1';
constexpr auto FLOOR2_CMD_LIGHT_OFF = '0';
constexpr auto FLOOR2_CMD_CURTAIN = '2';
constexpr auto FLOOR2_CMD_CURTAIN_ON = '1';
constexpr auto FLOOR2_CMD_CURTAIN_OFF = '0';
constexpr auto FLOOR2_HUMIDITY = '3';
constexpr auto FLOOR2_TEMPERATURE = '4';
namespace Ui {
class Floor2;
}

class Floor2 : public QWidget
{
    Q_OBJECT

public:
    explicit Floor2(QWidget *parent = nullptr);
    ~Floor2();
    Ui::Floor2 *ui;

private:

};

#endif // FLOOR2_H
