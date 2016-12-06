QT += core
QT -= gui

CONFIG += c++11

TARGET = Skil1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    personservice.cpp \
    person.cpp \
    dataaccess.cpp \
    inputcheck.cpp \
    computer.cpp \
    computerservice.cpp

HEADERS += \
    consoleui.h \
    personservice.h \
    person.h \
    dataaccess.h \
    inputcheck.h \
    computer.h \
    computerservice.h
