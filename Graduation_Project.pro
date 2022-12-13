QT       += core gui virtualkeyboard sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

SOURCES += *.cpp

HEADERS += *.h

FORMS += *.ui

LIBS += -lmosquitto

RESOURCES += /home/minhnt29/code/Graduation_GUI/QDarkStyleSheet/qdarkstyle/dark/darkstyle.qrc
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
