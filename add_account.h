#ifndef ADD_ACCOUNT_H
#define ADD_ACCOUNT_H

#include <QDialog>

namespace Ui {
class Add_Account;
}

class Add_Account : public QDialog
{
    Q_OBJECT

public:
    explicit Add_Account(QWidget *parent = nullptr);
    ~Add_Account();
    Ui::Add_Account *ui;
private:

};

#endif // ADD_ACCOUNT_H
