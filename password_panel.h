#ifndef PASSWORD_PANEL_H
#define PASSWORD_PANEL_H

#include <QDialog>

namespace Ui {
class Password_Panel;
}

class Password_Panel : public QDialog
{
    Q_OBJECT

public:
    explicit Password_Panel(QWidget *parent = nullptr);
    ~Password_Panel();
    Ui::Password_Panel *ui;
private:

};

#endif // PASSWORD_PANEL_H
