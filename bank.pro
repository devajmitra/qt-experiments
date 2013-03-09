#-------------------------------------------------
#
# Project created by QtCreator 2013-03-09T23:03:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bank
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bank.cpp \
    detailsdialog.cpp

HEADERS  += mainwindow.h \
    bank.h \
    detailsdialog.h

FORMS    += mainwindow.ui \
    detailsdialog.ui
