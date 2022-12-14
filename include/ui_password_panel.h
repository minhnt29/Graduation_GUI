/********************************************************************************
** Form generated from reading UI file 'password_panel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORD_PANEL_H
#define UI_PASSWORD_PANEL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "custom_line_edit.h"

QT_BEGIN_NAMESPACE

class Ui_Password_Panel
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    CustomLineEdit *lineEdit_RewriteNewPassword;
    CustomLineEdit *lineEdit_NewPassword;
    CustomLineEdit *lineEdit_OldPassword;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_ShowRewriteNewPassword;
    QPushButton *pushButton_ShowOldPassword;
    QPushButton *pushButton_ShowNewPassword;
    QLabel *lable_PasswordStatus;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_Ok;
    QPushButton *pushButton_Cancel;

    void setupUi(QDialog *Password_Panel)
    {
        if (Password_Panel->objectName().isEmpty())
            Password_Panel->setObjectName(QString::fromUtf8("Password_Panel"));
        Password_Panel->resize(581, 326);
        gridLayoutWidget = new QWidget(Password_Panel);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 40, 141, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(Password_Panel);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(150, 40, 201, 82));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_RewriteNewPassword = new QLineEdit(gridLayoutWidget_2);
        lineEdit_RewriteNewPassword->setObjectName(QString::fromUtf8("lineEdit_RewriteNewPassword"));

        gridLayout_2->addWidget(lineEdit_RewriteNewPassword, 3, 0, 1, 1);

        lineEdit_NewPassword = new QLineEdit(gridLayoutWidget_2);
        lineEdit_NewPassword->setObjectName(QString::fromUtf8("lineEdit_NewPassword"));

        gridLayout_2->addWidget(lineEdit_NewPassword, 2, 0, 1, 1);

        lineEdit_OldPassword = new QLineEdit(gridLayoutWidget_2);
        lineEdit_OldPassword->setObjectName(QString::fromUtf8("lineEdit_OldPassword"));

        gridLayout_2->addWidget(lineEdit_OldPassword, 1, 0, 1, 1);

        gridLayoutWidget_3 = new QWidget(Password_Panel);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(350, 40, 43, 81));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_ShowRewriteNewPassword = new QPushButton(gridLayoutWidget_3);
        pushButton_ShowRewriteNewPassword->setObjectName(QString::fromUtf8("pushButton_ShowRewriteNewPassword"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("resources/show.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_ShowRewriteNewPassword->setIcon(icon);

        gridLayout_3->addWidget(pushButton_ShowRewriteNewPassword, 2, 0, 1, 1);

        pushButton_ShowOldPassword = new QPushButton(gridLayoutWidget_3);
        pushButton_ShowOldPassword->setObjectName(QString::fromUtf8("pushButton_ShowOldPassword"));
        pushButton_ShowOldPassword->setIcon(icon);

        gridLayout_3->addWidget(pushButton_ShowOldPassword, 0, 0, 1, 1);

        pushButton_ShowNewPassword = new QPushButton(gridLayoutWidget_3);
        pushButton_ShowNewPassword->setObjectName(QString::fromUtf8("pushButton_ShowNewPassword"));
        pushButton_ShowNewPassword->setIcon(icon);

        gridLayout_3->addWidget(pushButton_ShowNewPassword, 1, 0, 1, 1);

        lable_PasswordStatus = new QLabel(Password_Panel);
        lable_PasswordStatus->setObjectName(QString::fromUtf8("lable_PasswordStatus"));
        lable_PasswordStatus->setGeometry(QRect(90, 150, 431, 61));
        gridLayoutWidget_4 = new QWidget(Password_Panel);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(370, 230, 195, 80));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_Ok = new QPushButton(gridLayoutWidget_4);
        pushButton_Ok->setObjectName(QString::fromUtf8("pushButton_Ok"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("resources/check-mark.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Ok->setIcon(icon1);

        gridLayout_4->addWidget(pushButton_Ok, 0, 0, 1, 1);

        pushButton_Cancel = new QPushButton(gridLayoutWidget_4);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("resources/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Cancel->setIcon(icon2);

        gridLayout_4->addWidget(pushButton_Cancel, 0, 1, 1, 1);


        retranslateUi(Password_Panel);

        QMetaObject::connectSlotsByName(Password_Panel);
    } // setupUi

    void retranslateUi(QDialog *Password_Panel)
    {
        Password_Panel->setWindowTitle(QApplication::translate("Password_Panel", "Dialog", nullptr));
        label_2->setText(QApplication::translate("Password_Panel", "M\341\272\255t kh\341\272\251u m\341\273\233i", nullptr));
        label->setText(QApplication::translate("Password_Panel", "M\341\272\255t kh\341\272\251u c\305\251", nullptr));
        label_3->setText(QApplication::translate("Password_Panel", "Nh\341\272\255p l\341\272\241i m\341\272\255t kh\341\272\251u m\341\273\233i", nullptr));
        pushButton_ShowRewriteNewPassword->setText(QString());
        pushButton_ShowOldPassword->setText(QString());
        pushButton_ShowNewPassword->setText(QString());
        lable_PasswordStatus->setText(QString());
        pushButton_Ok->setText(QApplication::translate("Password_Panel", "OK", nullptr));
        pushButton_Cancel->setText(QApplication::translate("Password_Panel", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Password_Panel: public Ui_Password_Panel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORD_PANEL_H
