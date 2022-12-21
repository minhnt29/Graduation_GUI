#ifndef DOOR_H
#define DOOR_H

#include <QWidget>

constexpr auto DOOR_CMD_LIGHT = '1';
constexpr auto DOOR_CMD_LIGHT_ON = '1';
constexpr auto DOOR_CMD_LIGHT_OFF = '0';
constexpr auto DOOR_CMD_DOOR = '2';
constexpr auto DOOR_CMD_DOOR_OPEN = '1';
constexpr auto DOOR_CMD_DOOR_CLOSE = '0';

namespace Ui {
class Door;
}

class User
{
    QString name;
    QString ID;
};

class Door : public QWidget
{
    Q_OBJECT

public:
    explicit Door(QWidget *parent = nullptr);
    ~Door();
    Ui::Door *ui;
private:
};

#endif // DOOR_H
