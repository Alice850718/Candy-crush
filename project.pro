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
    star.cpp \
    column.cpp \
    row.cpp \
    nineblock.cpp \
    rule.cpp \
    result.cpp

HEADERS  += mainwindow.h \
    blank.h \
    kill.h \
    star.h \
    column.h \
    row.h \
    nineblock.h \
    rule.h \
    result.h

FORMS    += mainwindow.ui \
    rule.ui \
    result.ui

RESOURCES += \
    pic.qrc
