/********************************************************************************
** Form generated from reading UI file 'add_account.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_ACCOUNT_H
#define UI_ADD_ACCOUNT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "custom_line_edit.h"

QT_BEGIN_NAMESPACE

class Ui_Add_Account
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *aloLabel;
    CustomLineEdit *lineEdit_UserName;
    QLabel *iDLabel;
    CustomLineEdit *lineEdit_UserID;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Add_Account)
    {
        if (Add_Account->objectName().isEmpty())
            Add_Account->setObjectName(QString::fromUtf8("Add_Account"));
        Add_Account->resize(551, 193);
        formLayoutWidget = new QWidget(Add_Account);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(40, 10, 341, 61));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        aloLabel = new QLabel(formLayoutWidget);
        aloLabel->setObjectName(QString::fromUtf8("aloLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, aloLabel);

        lineEdit_UserName = new QLineEdit(formLayoutWidget);
        lineEdit_UserName->setObjectName(QString::fromUtf8("lineEdit_UserName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_UserName);

        iDLabel = new QLabel(formLayoutWidget);
        iDLabel->setObjectName(QString::fromUtf8("iDLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, iDLabel);

        lineEdit_UserID = new QLineEdit(formLayoutWidget);
        lineEdit_UserID->setObjectName(QString::fromUtf8("lineEdit_UserID"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_UserID);

        gridLayoutWidget = new QWidget(Add_Account);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(350, 110, 198, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("resources/check-mark.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("resources/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);


        retranslateUi(Add_Account);

        QMetaObject::connectSlotsByName(Add_Account);
    } // setupUi

    void retranslateUi(QDialog *Add_Account)
    {
        Add_Account->setWindowTitle(QApplication::translate("Add_Account", "Dialog", nullptr));
        aloLabel->setText(QApplication::translate("Add_Account", "T\303\252n ng\306\260\341\273\235i d\303\271ng", nullptr));
        iDLabel->setText(QApplication::translate("Add_Account", "ID", nullptr));
        pushButton->setText(QApplication::translate("Add_Account", "OK", nullptr));
        pushButton_2->setText(QApplication::translate("Add_Account", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Add_Account: public Ui_Add_Account {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_ACCOUNT_H
