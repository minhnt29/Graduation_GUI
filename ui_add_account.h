/********************************************************************************
** Form generated from reading UI file 'add_account.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_ACCOUNT_H
#define UI_ADD_ACCOUNT_H

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

class Ui_Add_Account
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_Ok;
    QPushButton *pushButton_Cancel;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *aloLabel;
    QLabel *iDLabel;
    CustomLineEdit *lineEdit_UserName;
    CustomLineEdit *lineEdit_UserID;

    void setupUi(QDialog *Add_Account)
    {
        if (Add_Account->objectName().isEmpty())
            Add_Account->setObjectName(QString::fromUtf8("Add_Account"));
        Add_Account->resize(551, 193);
        gridLayoutWidget = new QWidget(Add_Account);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(350, 110, 198, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Ok = new QPushButton(gridLayoutWidget);
        pushButton_Ok->setObjectName(QString::fromUtf8("pushButton_Ok"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("resources/check-mark.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Ok->setIcon(icon);

        gridLayout->addWidget(pushButton_Ok, 0, 0, 1, 1);

        pushButton_Cancel = new QPushButton(gridLayoutWidget);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("resources/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Cancel->setIcon(icon1);

        gridLayout->addWidget(pushButton_Cancel, 0, 1, 1, 1);

        gridLayoutWidget_2 = new QWidget(Add_Account);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(30, 10, 361, 80));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        aloLabel = new QLabel(gridLayoutWidget_2);
        aloLabel->setObjectName(QString::fromUtf8("aloLabel"));
        aloLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(aloLabel, 0, 1, 1, 1);

        iDLabel = new QLabel(gridLayoutWidget_2);
        iDLabel->setObjectName(QString::fromUtf8("iDLabel"));
        iDLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(iDLabel, 1, 1, 1, 1);

        lineEdit_UserName = new CustomLineEdit(gridLayoutWidget_2);
        lineEdit_UserName->setObjectName(QString::fromUtf8("lineEdit_UserName"));

        gridLayout_2->addWidget(lineEdit_UserName, 0, 2, 1, 1);

        lineEdit_UserID = new CustomLineEdit(gridLayoutWidget_2);
        lineEdit_UserID->setObjectName(QString::fromUtf8("lineEdit_UserID"));

        gridLayout_2->addWidget(lineEdit_UserID, 1, 2, 1, 1);


        retranslateUi(Add_Account);

        QMetaObject::connectSlotsByName(Add_Account);
    } // setupUi

    void retranslateUi(QDialog *Add_Account)
    {
        Add_Account->setWindowTitle(QCoreApplication::translate("Add_Account", "Th\303\252m t\303\240i kho\341\272\243n", nullptr));
        pushButton_Ok->setText(QCoreApplication::translate("Add_Account", "OK", nullptr));
        pushButton_Cancel->setText(QCoreApplication::translate("Add_Account", "Cancel", nullptr));
        aloLabel->setText(QCoreApplication::translate("Add_Account", "T\303\252n ng\306\260\341\273\235i d\303\271ng", nullptr));
        iDLabel->setText(QCoreApplication::translate("Add_Account", "ID", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Add_Account: public Ui_Add_Account {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_ACCOUNT_H
