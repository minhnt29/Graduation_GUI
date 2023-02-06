/********************************************************************************
** Form generated from reading UI file 'opendoorcounter.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENDOORCOUNTER_H
#define UI_OPENDOORCOUNTER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenDoorCounter
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton_Ok;
    QPushButton *pushButton_Reload;
    QTableWidget *tableWidget_Door_Open;

    void setupUi(QDialog *OpenDoorCounter)
    {
        if (OpenDoorCounter->objectName().isEmpty())
            OpenDoorCounter->setObjectName(QString::fromUtf8("OpenDoorCounter"));
        OpenDoorCounter->resize(1024, 545);
        OpenDoorCounter->setMinimumSize(QSize(1024, 545));
        OpenDoorCounter->setMaximumSize(QSize(1024, 545));
        OpenDoorCounter->setBaseSize(QSize(1024, 550));
        gridLayout_2 = new QGridLayout(OpenDoorCounter);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_Ok = new QPushButton(OpenDoorCounter);
        pushButton_Ok->setObjectName(QString::fromUtf8("pushButton_Ok"));
        pushButton_Ok->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/check-mark.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Ok->setIcon(icon);

        gridLayout->addWidget(pushButton_Ok, 2, 1, 1, 1);

        pushButton_Reload = new QPushButton(OpenDoorCounter);
        pushButton_Reload->setObjectName(QString::fromUtf8("pushButton_Reload"));
        pushButton_Reload->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/reload.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Reload->setIcon(icon1);

        gridLayout->addWidget(pushButton_Reload, 2, 0, 1, 1);

        tableWidget_Door_Open = new QTableWidget(OpenDoorCounter);
        if (tableWidget_Door_Open->columnCount() < 4)
            tableWidget_Door_Open->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_Door_Open->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_Door_Open->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_Door_Open->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_Door_Open->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget_Door_Open->setObjectName(QString::fromUtf8("tableWidget_Door_Open"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget_Door_Open->sizePolicy().hasHeightForWidth());
        tableWidget_Door_Open->setSizePolicy(sizePolicy);
        tableWidget_Door_Open->setStyleSheet(QString::fromUtf8("font: 75 18pt \"PibotoLt\";"));
        tableWidget_Door_Open->horizontalHeader()->setDefaultSectionSize(245);
        tableWidget_Door_Open->verticalHeader()->setDefaultSectionSize(70);

        gridLayout->addWidget(tableWidget_Door_Open, 0, 0, 1, 2);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);


        retranslateUi(OpenDoorCounter);

        QMetaObject::connectSlotsByName(OpenDoorCounter);
    } // setupUi

    void retranslateUi(QDialog *OpenDoorCounter)
    {
        OpenDoorCounter->setWindowTitle(QCoreApplication::translate("OpenDoorCounter", "Dialog", nullptr));
        pushButton_Ok->setText(QCoreApplication::translate("OpenDoorCounter", "Ok", nullptr));
        pushButton_Reload->setText(QCoreApplication::translate("OpenDoorCounter", "Load d\341\273\257 li\341\273\207u", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Door_Open->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("OpenDoorCounter", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Door_Open->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("OpenDoorCounter", "T\303\252n", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Door_Open->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("OpenDoorCounter", "Gi\341\273\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Door_Open->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("OpenDoorCounter", "Ng\303\240y", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OpenDoorCounter: public Ui_OpenDoorCounter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENDOORCOUNTER_H
