//
// Created by MinhNT on 11/4/2022.
//

#include "custom_line_edit.h"
#include <QGuiApplication>

CustomLineEdit::CustomLineEdit(QWidget *parent) : QLineEdit(parent) {
    setAttribute(Qt::WA_InputMethodEnabled, true);
}

bool CustomLineEdit::event(QEvent *e) {
    auto keyboard_rect = QGuiApplication::inputMethod()->keyboardRectangle();
    auto keyboard_visible = QGuiApplication::inputMethod()->isVisible();
    auto global_y = QWidget::mapToGlobal(rect().topLeft()).y() + height();
    auto k_global_y = keyboard_rect.topLeft().y();
    auto diff = k_global_y - global_y;
    auto need_to_move = diff < 0;
    if (keyboard_visible && !moved_ && need_to_move) {
        moved_ = true;
        last_diff_ = diff;
        const auto g = parentWidget()->frameGeometry();
        parentWidget()->move(g.x(), g.y() - qAbs(last_diff_));
    }
    if (!keyboard_visible && moved_) {
        moved_ = false;
        const auto g = parentWidget()->frameGeometry();
        parentWidget()->move(g.x(), g.y() + qAbs(last_diff_));
    }
    return QLineEdit::event(e);
}
