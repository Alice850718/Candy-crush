#-------------------------------------------------
#
# Project created by QtCreator 2015-06-27T15:37:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    blank.cpp \
    kill.cpp \
    star.cpp

HEADERS  += mainwindow.h \
    blank.h \
    kill.h \
    star.h

FORMS    += mainwindow.ui

RESOURCES += \
    pic.qrc
