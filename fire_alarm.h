#ifndef FIRE_ALARM_H
#define FIRE_ALARM_H

#include <QWidget>

namespace Ui {
class Fire_Alarm;
}

class Fire_Alarm : public QWidget
{
    Q_OBJECT

public:
    explicit Fire_Alarm(QWidget *parent = nullptr);
    ~Fire_Alarm();

private:
    Ui::Fire_Alarm *ui;
};

#endif // FIRE_ALARM_H
