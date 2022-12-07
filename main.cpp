#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QThread>
#include "common.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file(":/qdarkstyle/dark/darkstyle.qss");
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream stream(&file);
    a.setStyleSheet(stream.readAll());
    QFont f = QApplication::font();
    f.setPointSize(20);
    QApplication::setFont(f);
    QApplication::setWindowIcon(QIcon(":/resources/logo.png"));
    MainWindow w;
    w.setMaximumHeight(kMinimumHeight);
    w.setMaximumWidth(kMinimumWidth);
    w.setUnifiedTitleAndToolBarOnMac("123");
    w.show();
    QApplication::exec();
    return 0;
}
