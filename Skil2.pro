QT += core sql
QT -= gui

CONFIG += c++11

TARGET = Skil1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    dataaccess.cpp \
    inputcheck.cpp \
    computer.cpp \
    service.cpp \
    utilities.cpp \
    linked.cpp \
    scientist.cpp

HEADERS += \
    consoleui.h \
    dataaccess.h \
    inputcheck.h \
    computer.h \
    service.h \
    utilities.h \
    linked.h \
    scientist.h
