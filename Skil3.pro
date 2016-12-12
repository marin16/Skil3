#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T12:37:01
#
#-------------------------------------------------

QT       += core gui
QT       += core sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Skil3GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    computer.cpp \
    consoleui.cpp \
    dataaccess.cpp \
    inputcheck.cpp \
    linked.cpp \
    scientist.cpp \
    service.cpp \
    utilities.cpp

HEADERS  += mainwindow.h \
    computer.h \
    consoleui.h \
    dataaccess.h \
    inputcheck.h \
    linked.h \
    scientist.h \
    service.h \
    utilities.h

FORMS    += mainwindow.ui

DISTFILES += \
    csdb \
    readme.md \
    insert.sql
