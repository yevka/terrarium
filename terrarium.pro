#-------------------------------------------------
#
# Project created by QtCreator 2014-10-25T00:48:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Terrarium
TEMPLATE = app

HEADERS  += terrarium.h             \
            board.h                 \
            graphicsview.h          \
            info.h                  \
            menubar.h               \
            newgameform.h           \
            scene.h                 \
            cell.h

SOURCES +=  main.cpp                 \
            terrarium.cpp            \
            board.cpp                \
            graphicsview.cpp         \
            info.cpp                 \
            menubar.cpp              \
            newgameform.cpp          \
            scene.cpp                \
            cell.cpp

CONFIG += mobility
MOBILITY =

OTHER_FILES +=

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

RESOURCES += \
    resource.qrc
