TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    figure.cpp \
    cell.cpp \
    field.cpp \
    game.cpp \
    ifigure.cpp

HEADERS += \
    figure.h \
    cell.h \
    field.h \
    game.h \
    ifigure.h
