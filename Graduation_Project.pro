QT       += core gui virtualkeyboard sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

SOURCES += src/add_account.cpp \
           src/custom_line_edit.cpp \
           src/door.cpp \
           src/door_panel.cpp \
           src/fire_alarm.cpp \
           src/fire_alarm_init.cpp \
           src/floor1.cpp \
           src/floor1_panel.cpp \
           src/main.cpp \
           src/mainwindow.cpp \
           src/module_sim_handle.cpp \
           src/MQTT_Init.cpp \
           src/password_panel.cpp \

HEADERS += include/add_account.h \
           include/common.h \
           include/custom_line_edit.h \
           include/door.h \
           include/fire_alarm.h \
           include/floor1.h \
           include/mainwindow.h \
           include/password_panel.h \
           include/ui_add_account.h \
           include/ui_password_panel.h

FORMS += ui/Door_Control.ui \
         ui/fire_alarm.ui \
         ui/floor1.ui \
         ui/mainwindow.ui

LIBS += -lmosquitto

RESOURCES += /home/minhnt29/code/Graduation_GUI/QDarkStyleSheet/qdarkstyle/dark/darkstyle.qrc
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
