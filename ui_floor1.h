/********************************************************************************
** Form generated from reading UI file 'floor1.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLOOR1_H
#define UI_FLOOR1_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Floor1
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QPushButton *pushButton_Light_Status;
    QPushButton *pushButton_Curtain_Status;
    QLabel *label_Home;
    QPushButton *pushButton_Curtain;
    QLabel *label_Light;
    QLabel *label_Temp;
    QPushButton *pushButton_Home;
    QLabel *label_Humidity;
    QLabel *label_Temp_Value;
    QLabel *label_Floor_Name;
    QLabel *label_Humidity_Value;
    QPushButton *pushButton_Light;
    QLabel *label_Curtain;
    QLabel *label;

    void setupUi(QWidget *Floor1)
    {
        if (Floor1->objectName().isEmpty())
            Floor1->setObjectName(QString::fromUtf8("Floor1"));
        Floor1->resize(1024, 545);
        Floor1->setMaximumSize(QSize(1024, 600));
        Floor1->setBaseSize(QSize(1024, 600));
        gridLayout_2 = new QGridLayout(Floor1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(Floor1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(70, 70));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/resources/humidity.png")));
        label_2->setScaledContents(true);

        gridLayout->addWidget(label_2, 3, 2, 1, 1);

        pushButton_Light_Status = new QPushButton(Floor1);
        pushButton_Light_Status->setObjectName(QString::fromUtf8("pushButton_Light_Status"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/light_on.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/resources/light_off.png"), QSize(), QIcon::Disabled, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/resources/light_on.png"), QSize(), QIcon::Disabled, QIcon::On);
        icon.addFile(QString::fromUtf8(":/resources/light_off.png"), QSize(), QIcon::Active, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/resources/light_on.png"), QSize(), QIcon::Active, QIcon::On);
        icon.addFile(QString::fromUtf8(":/resources/light_off.png"), QSize(), QIcon::Selected, QIcon::Off);
        pushButton_Light_Status->setIcon(icon);
        pushButton_Light_Status->setIconSize(QSize(100, 100));
        pushButton_Light_Status->setFlat(true);

        gridLayout->addWidget(pushButton_Light_Status, 8, 1, 1, 1);

        pushButton_Curtain_Status = new QPushButton(Floor1);
        pushButton_Curtain_Status->setObjectName(QString::fromUtf8("pushButton_Curtain_Status"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/light_on.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Curtain_Status->setIcon(icon1);
        pushButton_Curtain_Status->setIconSize(QSize(100, 100));
        pushButton_Curtain_Status->setFlat(true);

        gridLayout->addWidget(pushButton_Curtain_Status, 8, 3, 1, 1);

        label_Home = new QLabel(Floor1);
        label_Home->setObjectName(QString::fromUtf8("label_Home"));
        label_Home->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));
        label_Home->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout->addWidget(label_Home, 3, 3, 1, 1);

        pushButton_Curtain = new QPushButton(Floor1);
        pushButton_Curtain->setObjectName(QString::fromUtf8("pushButton_Curtain"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_Curtain->sizePolicy().hasHeightForWidth());
        pushButton_Curtain->setSizePolicy(sizePolicy);
        pushButton_Curtain->setStyleSheet(QString::fromUtf8("background-color: transparent; border: 0px"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/off-button.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/resources/on-button.png"), QSize(), QIcon::Normal, QIcon::On);
        icon2.addFile(QString::fromUtf8(":/resources/on-button.png"), QSize(), QIcon::Disabled, QIcon::On);
        pushButton_Curtain->setIcon(icon2);
        pushButton_Curtain->setIconSize(QSize(150, 150));
        pushButton_Curtain->setFlat(true);

        gridLayout->addWidget(pushButton_Curtain, 8, 2, 1, 1);

        label_Light = new QLabel(Floor1);
        label_Light->setObjectName(QString::fromUtf8("label_Light"));
        label_Light->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));
        label_Light->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_Light, 6, 0, 1, 1);

        label_Temp = new QLabel(Floor1);
        label_Temp->setObjectName(QString::fromUtf8("label_Temp"));
        label_Temp->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));
        label_Temp->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_Temp, 1, 0, 1, 1);

        pushButton_Home = new QPushButton(Floor1);
        pushButton_Home->setObjectName(QString::fromUtf8("pushButton_Home"));
        pushButton_Home->setStyleSheet(QString::fromUtf8("background-color: transparent; border: 0px"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/homepage.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Home->setIcon(icon3);
        pushButton_Home->setIconSize(QSize(100, 100));
        pushButton_Home->setFlat(true);

        gridLayout->addWidget(pushButton_Home, 1, 3, 1, 1);

        label_Humidity = new QLabel(Floor1);
        label_Humidity->setObjectName(QString::fromUtf8("label_Humidity"));
        label_Humidity->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));
        label_Humidity->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_Humidity, 3, 0, 1, 1);

        label_Temp_Value = new QLabel(Floor1);
        label_Temp_Value->setObjectName(QString::fromUtf8("label_Temp_Value"));
        label_Temp_Value->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));
        label_Temp_Value->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_Temp_Value, 1, 1, 1, 1);

        label_Floor_Name = new QLabel(Floor1);
        label_Floor_Name->setObjectName(QString::fromUtf8("label_Floor_Name"));
        label_Floor_Name->setStyleSheet(QString::fromUtf8("font: 75 28pt \"PibotoLt\"; color : blue;"));
        label_Floor_Name->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_Floor_Name, 0, 0, 1, 4);

        label_Humidity_Value = new QLabel(Floor1);
        label_Humidity_Value->setObjectName(QString::fromUtf8("label_Humidity_Value"));
        label_Humidity_Value->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));
        label_Humidity_Value->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_Humidity_Value, 3, 1, 1, 1);

        pushButton_Light = new QPushButton(Floor1);
        pushButton_Light->setObjectName(QString::fromUtf8("pushButton_Light"));
        sizePolicy.setHeightForWidth(pushButton_Light->sizePolicy().hasHeightForWidth());
        pushButton_Light->setSizePolicy(sizePolicy);
        pushButton_Light->setStyleSheet(QString::fromUtf8("background-color: transparent; border: 0px"));
        pushButton_Light->setIcon(icon2);
        pushButton_Light->setIconSize(QSize(150, 150));
        pushButton_Light->setFlat(true);

        gridLayout->addWidget(pushButton_Light, 8, 0, 1, 1);

        label_Curtain = new QLabel(Floor1);
        label_Curtain->setObjectName(QString::fromUtf8("label_Curtain"));
        label_Curtain->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));
        label_Curtain->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_Curtain, 6, 2, 1, 1);

        label = new QLabel(Floor1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(70, 70));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/temperature.png")));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(Floor1);

        QMetaObject::connectSlotsByName(Floor1);
    } // setupUi

    void retranslateUi(QWidget *Floor1)
    {
        Floor1->setWindowTitle(QCoreApplication::translate("Floor1", "Ph\303\262ng 1", nullptr));
        label_2->setText(QString());
        pushButton_Light_Status->setText(QString());
        pushButton_Curtain_Status->setText(QString());
        label_Home->setText(QCoreApplication::translate("Floor1", "M\303\240n h\303\254nh ch\303\255nh", nullptr));
        pushButton_Curtain->setText(QString());
        label_Light->setText(QCoreApplication::translate("Floor1", "\304\220\303\250n 1", nullptr));
        label_Temp->setText(QCoreApplication::translate("Floor1", "Nhi\341\273\207t \304\221\341\273\231 ", nullptr));
        pushButton_Home->setText(QString());
        label_Humidity->setText(QCoreApplication::translate("Floor1", "\304\220\341\273\231 \341\272\251m", nullptr));
        label_Temp_Value->setText(QString());
        label_Floor_Name->setText(QCoreApplication::translate("Floor1", "PH\303\222NG 1", nullptr));
        label_Humidity_Value->setText(QString());
        pushButton_Light->setText(QString());
        label_Curtain->setText(QCoreApplication::translate("Floor1", "\304\220\303\250n 2", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Floor1: public Ui_Floor1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLOOR1_H
