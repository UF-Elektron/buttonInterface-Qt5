#-------------------------------------------------
#
# Project created by QtCreator 2019-04-18T09:41:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    ../../lisa_design/UIrework/src/buttonHandler.cpp \
    ../../lisa_design/UIrework/src/ledHandler.cpp \
    ../../lisa_design/UIrework/src/magnetHandler.cpp \
    ../../lisa_design/UIrework/src/ui.cpp \
    ../../lisa_design/UIrework/src/app_kplus.c \
    ../../lisa_design/UIrework/src/flash.c \
    ../../lisa_design/UIrework/src/oku.c \
    ../../lisa_design/UIrework/src/registerFunctions.c

HEADERS += \
        mainwindow.h \
    ../../lisa_design/UIrework/src/app_kplus.h \
    ../../lisa_design/UIrework/src/binding.h \
    ../../lisa_design/UIrework/src/buttonHandler.h \
    ../../lisa_design/UIrework/src/flash.h \
    ../../lisa_design/UIrework/src/ledHandler.h \
    ../../lisa_design/UIrework/src/magnetHandler.h \
    ../../lisa_design/UIrework/src/main.h \
    ../../lisa_design/UIrework/src/oku.h \
    ../../lisa_design/UIrework/src/registerFunctions.h \
    ../../lisa_design/UIrework/src/ui.h

FORMS += \
        mainwindow.ui
