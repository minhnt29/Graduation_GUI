#ifndef DOOR_H
#define DOOR_H

#include <QWidget>

namespace Ui {
class Door;
}

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
