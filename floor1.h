#ifndef FLOOR1_H
#define FLOOR1_H

#include <QWidget>

constexpr auto FLOOR1_CMD_LIGHT = '1';
constexpr auto FLOOR1_CMD_LIGHT_ON = '1';
constexpr auto FLOOR1_CMD_LIGHT_OFF = '0';
constexpr auto FLOOR1_CMD_CURTAIN = '2';
constexpr auto FLOOR1_CMD_CURTAIN_ON = '1';
constexpr auto FLOOR1_CMD_CURTAIN_OFF = '0';
constexpr auto FLOOR1_HUMIDITY = 'h';
constexpr auto FLOOR1_TEMPERATURE = 't';
namespace Ui {
class Floor1;
}

class Floor1 : public QWidget
{
    Q_OBJECT

public:
    explicit Floor1(QWidget *parent = nullptr);
    ~Floor1();
    Ui::Floor1 *ui;

private:

};

#endif // FLOOR1_H
