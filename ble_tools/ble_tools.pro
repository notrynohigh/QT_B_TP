#-------------------------------------------------
#
# Project created by QtCreator 2018-05-04T18:18:03
#
#-------------------------------------------------
QT += serialport
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ble_tools
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        ble_tools.cpp \
    b_tp/src/b_tp.c \
    b_tp/check/crc16/crc16.c \
    b_tp/b_tp_port/b_tp_port.c \
    uartclass.cpp \
    tcmd/tool_cmd.c \
    bledev.cpp \
    utc2000/calendar.c

HEADERS  += ble_tools.h \
    b_tp/inc/b_tp.h \
    b_tp/check/crc16/crc16.h \
    b_tp/b_tp_port/b_tp_config.h \
    b_tp/b_tp_port/b_tp_port.h \
    uartclass.h \
    tcmd/tool_cmd.h \
    bledev.h \
    utc2000/calendar.h

FORMS    += ble_tools.ui

RESOURCES += \
    icon.qrc
