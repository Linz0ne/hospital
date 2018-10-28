#-------------------------------------------------
#
# Project created by QtCreator 2018-06-01T14:28:57
#
#-------------------------------------------------

QT       += core gui
QT       +=sql
QT       +=printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
RC_FILE = res.rc
TARGET = shiyan3
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


SOURCES += \
        main.cpp \
        logging.cpp \
    manger.cpp \
    program.cpp \
    pay.cpp

HEADERS += \
        logging.h \
    manger.h \
    program.h \
    pay.h

FORMS += \
        logging.ui \
    manger.ui \
    program.ui \
    pay.ui

RESOURCES += \
    img.qrc
