#ifndef OPENDOORCOUNTER_H
#define OPENDOORCOUNTER_H

#include <QDialog>

namespace Ui {
class OpenDoorCounter;
}

class OpenDoorCounter : public QDialog
{
    Q_OBJECT

public:
    explicit OpenDoorCounter(QWidget *parent = nullptr);
    ~OpenDoorCounter();

private:
    Ui::OpenDoorCounter *ui;
};

#endif // OPENDOORCOUNTER_H
