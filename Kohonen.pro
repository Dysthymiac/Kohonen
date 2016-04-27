#-------------------------------------------------
#
# Project created by QtCreator 2016-04-14T21:17:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kohonen
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    kohonennetwork.cpp \
    utils.cpp \
    picturebox.cpp \
    scalablegraphicsview.cpp

HEADERS  += mainwindow.h \
    kohonennetwork.h \
    utils.h \
    picturebox.h \
    scalablegraphicsview.h

FORMS    += mainwindow.ui
