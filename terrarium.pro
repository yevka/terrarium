#-------------------------------------------------
#
# Project created by QtCreator 2014-10-25T00:48:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Terrarium
TEMPLATE = app
CONFIG += c++14

HEADERS  += terrarium.h             \
            board.h                 \
            graphicsview.h          \
            menubar.h               \
            scene.h                 \
            cell.h

SOURCES +=  main.cpp                 \
            terrarium.cpp            \
            board.cpp                \
            graphicsview.cpp         \
            menubar.cpp              \
            scene.cpp                \
            cell.cpp

RESOURCES += \
    resource.qrc
