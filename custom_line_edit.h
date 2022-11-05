#ifndef CUSTOM_LINE_EDIT_H
#define CUSTOM_LINE_EDIT_H

#include <QLineEdit>

class CustomLineEdit : public QLineEdit {
    Q_OBJECT
public:
    explicit CustomLineEdit(QWidget *parent = nullptr);

protected:
    bool event(QEvent *) override;

private:
    bool moved_ = false;
    qreal last_diff_ = 0;
};

#endif// CUSTOM_LINE_EDIT_H
