/********************************************************************************
** Form generated from reading UI file 'door.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOOR_H
#define UI_DOOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Door
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_Add_Account;
    QPushButton *pushButton_Door_Open_Counter;
    QPushButton *pushButton_Change_Password;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_Home;
    QLabel *label_Home;
    QPushButton *pushButton_Light;
    QPushButton *pushButton_Door;

    void setupUi(QWidget *Door)
    {
        if (Door->objectName().isEmpty())
            Door->setObjectName(QString::fromUtf8("Door"));
        Door->resize(1024, 545);
        Door->setMinimumSize(QSize(1024, 545));
        Door->setMaximumSize(QSize(1024, 545));
        Door->setBaseSize(QSize(1024, 600));
        gridLayoutWidget = new QWidget(Door);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 541, 271));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_Add_Account = new QPushButton(gridLayoutWidget);
        pushButton_Add_Account->setObjectName(QString::fromUtf8("pushButton_Add_Account"));
        pushButton_Add_Account->setMinimumSize(QSize(0, 70));
        pushButton_Add_Account->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));

        gridLayout_2->addWidget(pushButton_Add_Account, 2, 0, 1, 1);

        pushButton_Door_Open_Counter = new QPushButton(gridLayoutWidget);
        pushButton_Door_Open_Counter->setObjectName(QString::fromUtf8("pushButton_Door_Open_Counter"));
        pushButton_Door_Open_Counter->setMinimumSize(QSize(0, 70));
        pushButton_Door_Open_Counter->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));

        gridLayout_2->addWidget(pushButton_Door_Open_Counter, 1, 0, 1, 1);

        pushButton_Change_Password = new QPushButton(gridLayoutWidget);
        pushButton_Change_Password->setObjectName(QString::fromUtf8("pushButton_Change_Password"));
        pushButton_Change_Password->setMinimumSize(QSize(0, 70));
        pushButton_Change_Password->setLayoutDirection(Qt::LeftToRight);
        pushButton_Change_Password->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));

        gridLayout_2->addWidget(pushButton_Change_Password, 0, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(70, 70));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/lock.png")));
        label->setScaledContents(true);

        gridLayout_2->addWidget(label, 0, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(70, 70));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/resources/parchment.png")));
        label_2->setScaledContents(true);

        gridLayout_2->addWidget(label_2, 1, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(70, 70));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/resources/add-user.png")));
        label_3->setScaledContents(true);

        gridLayout_2->addWidget(label_3, 2, 1, 1, 1);

        pushButton_Home = new QPushButton(Door);
        pushButton_Home->setObjectName(QString::fromUtf8("pushButton_Home"));
        pushButton_Home->setGeometry(QRect(850, 20, 74, 70));
        pushButton_Home->setStyleSheet(QString::fromUtf8("background-color: transparent; border: 0px"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/homepage.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Home->setIcon(icon);
        pushButton_Home->setIconSize(QSize(70, 70));
        pushButton_Home->setFlat(true);
        label_Home = new QLabel(Door);
        label_Home->setObjectName(QString::fromUtf8("label_Home"));
        label_Home->setGeometry(QRect(800, 110, 181, 41));
        label_Home->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));
        label_Home->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        pushButton_Light = new QPushButton(Door);
        pushButton_Light->setObjectName(QString::fromUtf8("pushButton_Light"));
        pushButton_Light->setGeometry(QRect(110, 330, 281, 150));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_Light->sizePolicy().hasHeightForWidth());
        pushButton_Light->setSizePolicy(sizePolicy);
        pushButton_Light->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/off-button.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/resources/on-button.png"), QSize(), QIcon::Normal, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/resources/off-button.png"), QSize(), QIcon::Disabled, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/resources/on-button.png"), QSize(), QIcon::Disabled, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/resources/on-button.png"), QSize(), QIcon::Active, QIcon::Off);
        pushButton_Light->setIcon(icon1);
        pushButton_Light->setIconSize(QSize(150, 150));
        pushButton_Light->setFlat(true);
        pushButton_Door = new QPushButton(Door);
        pushButton_Door->setObjectName(QString::fromUtf8("pushButton_Door"));
        pushButton_Door->setGeometry(QRect(640, 330, 271, 150));
        sizePolicy.setHeightForWidth(pushButton_Door->sizePolicy().hasHeightForWidth());
        pushButton_Door->setSizePolicy(sizePolicy);
        pushButton_Door->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/off-button.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/resources/on-button.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_Door->setIcon(icon2);
        pushButton_Door->setIconSize(QSize(150, 150));
        pushButton_Door->setFlat(true);

        retranslateUi(Door);

        QMetaObject::connectSlotsByName(Door);
    } // setupUi

    void retranslateUi(QWidget *Door)
    {
        Door->setWindowTitle(QCoreApplication::translate("Door", "C\341\273\255a ra v\303\240o", nullptr));
        pushButton_Add_Account->setText(QCoreApplication::translate("Door", "Th\303\252m t\303\240i kho\341\272\243n", nullptr));
        pushButton_Door_Open_Counter->setText(QCoreApplication::translate("Door", "L\341\273\213ch s\341\273\255 ra v\303\240o", nullptr));
        pushButton_Change_Password->setText(QCoreApplication::translate("Door", "\304\220\341\273\225i m\341\272\255t kh\341\272\251u", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        pushButton_Home->setText(QString());
        label_Home->setText(QCoreApplication::translate("Door", "M\303\240n h\303\254nh ch\303\255nh", nullptr));
        pushButton_Light->setText(QCoreApplication::translate("Door", "\304\220\303\250n", nullptr));
        pushButton_Door->setText(QCoreApplication::translate("Door", "C\341\273\255a", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Door: public Ui_Door {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOOR_H
