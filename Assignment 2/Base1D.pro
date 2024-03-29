#-------------------------------------------------
#
# Project created by QtCreator 2019-03-21T10:11:29
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Base1D
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
    coordinate.cpp \
    stickman.cpp \
    config.cpp \
    background.cpp \
    pausedialog.cpp \
    gamedialog.cpp \
    startdialog.cpp \
    gamefactory.cpp \
    stage1game.cpp \
    stage2game.cpp \
    stage2stickman.cpp \
    stickmandecorator.cpp \
    motiondecorator.cpp \
    obstacle.cpp \
    collisiondetector.cpp

HEADERS += \
    coordinate.h \
    stickman.h \
    config.h \
    background.h \
    pausedialog.h \
    gamedialog.h \
    startdialog.h \
    gamefactory.h \
    stage1gamefactory.h \
    stage1game.h \
    stage2game.h \
    stage2gamefactory.h \
    stage2stickman.h \
    stickmandecorator.h \
    motiondecorator.h \
    obstacle.h \
    collisiondetector.h

FORMS += \
    pausedialog.ui \
    startdialog.ui \
    gamedialog.ui

RESOURCES += \
    resources.qrc

DISTFILES += \
    config.txt
