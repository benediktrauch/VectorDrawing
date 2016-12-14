#-------------------------------------------------
#
# Project created by QtCreator 2016-10-27T09:40:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VektorzeichenprogrammVII
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    graphicsobject.cpp \
    circle.cpp \
    rectangle.cpp \
    draw.cpp \
    graphicsobjectmap.cpp \
    graphicsscene.cpp \
    colorbutton.cpp

HEADERS  += mainwindow.h \
    graphicsobject.h \
    circle.h \
    rectangle.h \
    draw.h \
    graphicsobjectmap.h \
    graphicsscene.h \
    colorbutton.h

FORMS    += mainwindow.ui

RESOURCES += \
    Images/selecttool.qrc
