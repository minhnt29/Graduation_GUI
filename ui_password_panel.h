/********************************************************************************
** Form generated from reading UI file 'password_panel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
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
#include <QtWidgets/CustomLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Password_Panel
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    CustomLineEdit *lineEdit_OldPassword;
    CustomLineEdit *lineEdit_NewPassword;
    CustomLineEdit *lineEdit_RewriteNewPassword;
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
        gridLayoutWidget->setGeometry(QRect(20, 10, 531, 141));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_OldPassword = new CustomLineEdit(gridLayoutWidget);
        lineEdit_OldPassword->setObjectName(QString::fromUtf8("lineEdit_OldPassword"));
        lineEdit_OldPassword->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));

        gridLayout->addWidget(lineEdit_OldPassword, 0, 1, 1, 1);

        lineEdit_NewPassword = new CustomLineEdit(gridLayoutWidget);
        lineEdit_NewPassword->setObjectName(QString::fromUtf8("lineEdit_NewPassword"));
        lineEdit_NewPassword->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));

        gridLayout->addWidget(lineEdit_NewPassword, 1, 1, 1, 1);

        lineEdit_RewriteNewPassword = new CustomLineEdit(gridLayoutWidget);
        lineEdit_RewriteNewPassword->setObjectName(QString::fromUtf8("lineEdit_RewriteNewPassword"));
        lineEdit_RewriteNewPassword->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));

        gridLayout->addWidget(lineEdit_RewriteNewPassword, 2, 1, 1, 1);

        lable_PasswordStatus = new QLabel(Password_Panel);
        lable_PasswordStatus->setObjectName(QString::fromUtf8("lable_PasswordStatus"));
        lable_PasswordStatus->setGeometry(QRect(20, 160, 531, 61));
        lable_PasswordStatus->setAlignment(Qt::AlignCenter);
        gridLayoutWidget_4 = new QWidget(Password_Panel);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(370, 230, 195, 80));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_Ok = new QPushButton(gridLayoutWidget_4);
        pushButton_Ok->setObjectName(QString::fromUtf8("pushButton_Ok"));
        pushButton_Ok->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/check-mark.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Ok->setIcon(icon);
        pushButton_Ok->setIconSize(QSize(20, 20));

        gridLayout_4->addWidget(pushButton_Ok, 0, 0, 1, 1);

        pushButton_Cancel = new QPushButton(gridLayoutWidget_4);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Cancel->setIcon(icon1);
        pushButton_Cancel->setIconSize(QSize(20, 20));

        gridLayout_4->addWidget(pushButton_Cancel, 0, 1, 1, 1);


        retranslateUi(Password_Panel);

        QMetaObject::connectSlotsByName(Password_Panel);
    } // setupUi

    void retranslateUi(QDialog *Password_Panel)
    {
        Password_Panel->setWindowTitle(QCoreApplication::translate("Password_Panel", "M\341\272\255t kh\341\272\251u", nullptr));
        label_2->setText(QCoreApplication::translate("Password_Panel", "M\341\272\255t kh\341\272\251u m\341\273\233i", nullptr));
        label_3->setText(QCoreApplication::translate("Password_Panel", "Nh\341\272\255p l\341\272\241i m\341\272\255t kh\341\272\251u m\341\273\233i", nullptr));
        label->setText(QCoreApplication::translate("Password_Panel", "M\341\272\255t kh\341\272\251u c\305\251", nullptr));
        lable_PasswordStatus->setText(QString());
        pushButton_Ok->setText(QCoreApplication::translate("Password_Panel", "OK", nullptr));
        pushButton_Cancel->setText(QCoreApplication::translate("Password_Panel", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Password_Panel: public Ui_Password_Panel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORD_PANEL_H
