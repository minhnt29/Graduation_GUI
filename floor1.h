#ifndef FLOOR1_H
#define FLOOR1_H

#include <QWidget>

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
