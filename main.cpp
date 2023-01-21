#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QThread>
#include "common.h"

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));
    QApplication a(argc, argv);
    QFile file(":/qdarkstyle/dark/darkstyle.qss");
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream stream(&file);
    //a.setStyleSheet(stream.readAll());
    QFont f = QApplication::font();
    f.setPointSize(60);
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
