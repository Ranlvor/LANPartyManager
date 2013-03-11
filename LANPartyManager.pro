#-------------------------------------------------
#
# Project created by QtCreator 2013-03-11T15:19:53
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LANPartyManager
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    StatusWidget.cpp \
    Network.cpp

HEADERS  += MainWindow.hpp \
    StatusWidget.h \
    Network.h

FORMS    += MainWindow.ui \
    StatusWidget.ui
