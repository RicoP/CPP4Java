TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp


unix:!macx:!symbian: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lmecab

INCLUDEPATH += $$PWD/../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../usr/local/include

