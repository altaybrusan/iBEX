#-------------------------------------------------
#
# Project created by QtCreator 2018-02-12T14:42:08
#
#-------------------------------------------------

QT       += core testlib serialport concurrent

QT       -= gui

TARGET = rs232connectortester
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += ../../common/include \
               ../../launch/

HEADERS += ../../launch/rs232connector.h \
           ../../common/include/iconnector.h\
           ../../launch/rs232connector.h

SOURCES += \
        rs232connectortester.cpp \
        ../../launch/rs232connector.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"