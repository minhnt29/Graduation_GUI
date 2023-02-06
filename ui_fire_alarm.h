/********************************************************************************
** Form generated from reading UI file 'fire_alarm.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRE_ALARM_H
#define UI_FIRE_ALARM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Fire_Alarm
{
public:
    QPushButton *pushButton_Fire_Icon;
    QPushButton *pushButton_Fire_Icon_2;
    QPushButton *pushButton_Fire_Icon_3;
    QPushButton *pushButton_Fire_Icon_4;
    QPushButton *pushButton_Fire_Icon_5;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *textLable_Fire_Status;

    void setupUi(QWidget *Fire_Alarm)
    {
        if (Fire_Alarm->objectName().isEmpty())
            Fire_Alarm->setObjectName(QString::fromUtf8("Fire_Alarm"));
        Fire_Alarm->resize(1024, 545);
        Fire_Alarm->setMinimumSize(QSize(1024, 545));
        Fire_Alarm->setMaximumSize(QSize(1024, 545));
        Fire_Alarm->setBaseSize(QSize(1024, 545));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        Fire_Alarm->setWindowIcon(icon);
        pushButton_Fire_Icon = new QPushButton(Fire_Alarm);
        pushButton_Fire_Icon->setObjectName(QString::fromUtf8("pushButton_Fire_Icon"));
        pushButton_Fire_Icon->setGeometry(QRect(260, 130, 461, 421));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/\342\200\224Pngtree\342\200\224burning fire_5637806.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Fire_Icon->setIcon(icon1);
        pushButton_Fire_Icon->setIconSize(QSize(400, 400));
        pushButton_Fire_Icon->setFlat(true);
        pushButton_Fire_Icon_2 = new QPushButton(Fire_Alarm);
        pushButton_Fire_Icon_2->setObjectName(QString::fromUtf8("pushButton_Fire_Icon_2"));
        pushButton_Fire_Icon_2->setGeometry(QRect(-50, 130, 461, 421));
        pushButton_Fire_Icon_2->setIcon(icon1);
        pushButton_Fire_Icon_2->setIconSize(QSize(400, 400));
        pushButton_Fire_Icon_2->setFlat(true);
        pushButton_Fire_Icon_3 = new QPushButton(Fire_Alarm);
        pushButton_Fire_Icon_3->setObjectName(QString::fromUtf8("pushButton_Fire_Icon_3"));
        pushButton_Fire_Icon_3->setGeometry(QRect(640, 110, 461, 421));
        pushButton_Fire_Icon_3->setIcon(icon1);
        pushButton_Fire_Icon_3->setIconSize(QSize(400, 400));
        pushButton_Fire_Icon_3->setFlat(true);
        pushButton_Fire_Icon_4 = new QPushButton(Fire_Alarm);
        pushButton_Fire_Icon_4->setObjectName(QString::fromUtf8("pushButton_Fire_Icon_4"));
        pushButton_Fire_Icon_4->setGeometry(QRect(450, 120, 461, 421));
        pushButton_Fire_Icon_4->setIcon(icon1);
        pushButton_Fire_Icon_4->setIconSize(QSize(400, 400));
        pushButton_Fire_Icon_4->setFlat(true);
        pushButton_Fire_Icon_5 = new QPushButton(Fire_Alarm);
        pushButton_Fire_Icon_5->setObjectName(QString::fromUtf8("pushButton_Fire_Icon_5"));
        pushButton_Fire_Icon_5->setGeometry(QRect(90, 130, 461, 421));
        pushButton_Fire_Icon_5->setIcon(icon1);
        pushButton_Fire_Icon_5->setIconSize(QSize(400, 400));
        pushButton_Fire_Icon_5->setFlat(true);
        horizontalLayoutWidget = new QWidget(Fire_Alarm);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 50, 1031, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        textLable_Fire_Status = new QLabel(horizontalLayoutWidget);
        textLable_Fire_Status->setObjectName(QString::fromUtf8("textLable_Fire_Status"));
        textLable_Fire_Status->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));
        textLable_Fire_Status->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(textLable_Fire_Status);


        retranslateUi(Fire_Alarm);

        QMetaObject::connectSlotsByName(Fire_Alarm);
    } // setupUi

    void retranslateUi(QWidget *Fire_Alarm)
    {
        Fire_Alarm->setWindowTitle(QCoreApplication::translate("Fire_Alarm", "Warning", nullptr));
        pushButton_Fire_Icon->setText(QString());
        pushButton_Fire_Icon_2->setText(QString());
        pushButton_Fire_Icon_3->setText(QString());
        pushButton_Fire_Icon_4->setText(QString());
        pushButton_Fire_Icon_5->setText(QString());
        textLable_Fire_Status->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Fire_Alarm: public Ui_Fire_Alarm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRE_ALARM_H
