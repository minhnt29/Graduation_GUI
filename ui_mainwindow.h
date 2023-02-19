/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include "custom_line_edit.h"
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    CustomLineEdit *lineEdit_Home_Owner;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_8;
    QLabel *label_3;
    QLabel *label_Project_Name;
    QLabel *label;
    QPushButton *pushButton_Floor2;
    QPushButton *pushButton_Floor1;
    QPushButton *pushButton_Door;
    QPushButton *pushButton_Floor3;
    QLabel *label_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1024, 545);
        MainWindow->setMinimumSize(QSize(1024, 545));
        MainWindow->setMaximumSize(QSize(1024, 545));
        MainWindow->setBaseSize(QSize(1024, 545));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(120, 20, 761, 271));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));

        gridLayout->addWidget(label_5, 2, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: 75 16pt \"PibotoLt\";"));

        gridLayout->addWidget(label_6, 3, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("font: 75 16pt \"PibotoLt\";"));

        gridLayout->addWidget(label_7, 4, 1, 1, 1);

        lineEdit_Home_Owner = new CustomLineEdit(gridLayoutWidget);
        lineEdit_Home_Owner->setObjectName(QString::fromUtf8("lineEdit_Home_Owner"));
        lineEdit_Home_Owner->setMaximumSize(QSize(380, 16777215));
        lineEdit_Home_Owner->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));

        gridLayout->addWidget(lineEdit_Home_Owner, 5, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setLayoutDirection(Qt::LeftToRight);
        label_8->setStyleSheet(QString::fromUtf8("font: 75 16pt \"PibotoLt\";"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_8, 5, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_Project_Name = new QLabel(gridLayoutWidget);
        label_Project_Name->setObjectName(QString::fromUtf8("label_Project_Name"));
        label_Project_Name->setStyleSheet(QString::fromUtf8("font: 28pt \"C059 [UKWN]\"; color : blue;"));
        label_Project_Name->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_Project_Name, 1, 0, 1, 2);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 5, 100, 150));
        label->setMinimumSize(QSize(100, 0));
        label->setMaximumSize(QSize(80, 150));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/logobk_bottom.png")));
        label->setScaledContents(true);
        pushButton_Floor2 = new QPushButton(centralwidget);
        pushButton_Floor2->setObjectName(QString::fromUtf8("pushButton_Floor2"));
        pushButton_Floor2->setGeometry(QRect(10, 410, 500, 100));
        pushButton_Floor2->setMinimumSize(QSize(0, 100));
        pushButton_Floor2->setMaximumSize(QSize(16777215, 16777215));
        pushButton_Floor2->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));
        pushButton_Floor1 = new QPushButton(centralwidget);
        pushButton_Floor1->setObjectName(QString::fromUtf8("pushButton_Floor1"));
        pushButton_Floor1->setGeometry(QRect(520, 300, 500, 100));
        pushButton_Floor1->setMinimumSize(QSize(0, 100));
        pushButton_Floor1->setLayoutDirection(Qt::RightToLeft);
        pushButton_Floor1->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));
        pushButton_Door = new QPushButton(centralwidget);
        pushButton_Door->setObjectName(QString::fromUtf8("pushButton_Door"));
        pushButton_Door->setGeometry(QRect(10, 300, 500, 100));
        pushButton_Door->setMinimumSize(QSize(0, 100));
        pushButton_Door->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));
        pushButton_Floor3 = new QPushButton(centralwidget);
        pushButton_Floor3->setObjectName(QString::fromUtf8("pushButton_Floor3"));
        pushButton_Floor3->setGeometry(QRect(520, 410, 500, 100));
        pushButton_Floor3->setMinimumSize(QSize(499, 100));
        pushButton_Floor3->setBaseSize(QSize(0, 0));
        pushButton_Floor3->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(870, 10, 150, 150));
        label_9->setMaximumSize(QSize(15000, 16777215));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/resources/mechatronics.png")));
        label_9->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1024, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Smart Home", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "TS.D\306\260\306\241ng V\304\203n L\341\272\241c", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Nguy\341\273\205n Tu\341\272\245n Minh - 20184551", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Nguy\341\273\205n V\304\203n B\341\272\243o - 20184351", nullptr));
        label_4->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Gi\341\272\243ng vi\303\252n h\306\260\341\273\233ng d\341\272\253n: ", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "S\341\273\221 \304\221i\341\273\207n tho\341\272\241i ch\341\273\247 nh\303\240", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Sinh vi\303\252n th\341\273\261c hi\341\273\207n: ", nullptr));
        label_Project_Name->setText(QCoreApplication::translate("MainWindow", "NH\303\200 TH\303\224NG MINH", nullptr));
        label->setText(QString());
        pushButton_Floor2->setText(QCoreApplication::translate("MainWindow", "Ph\303\262ng 2", nullptr));
        pushButton_Floor1->setText(QCoreApplication::translate("MainWindow", "Ph\303\262ng 1", nullptr));
        pushButton_Door->setText(QCoreApplication::translate("MainWindow", "C\341\273\255a ra v\303\240o", nullptr));
        pushButton_Floor3->setText(QCoreApplication::translate("MainWindow", "Ph\303\262ng 3", nullptr));
        label_9->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
