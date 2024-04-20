TEMPLATE = app
TARGET = APP
QT = core gui
greaterThan(QT_MAJOR_VERSION, 4):
QT += widgets
SOURCES += main.cpp \
   calc.cpp
HEADERS += \
    calc.h
