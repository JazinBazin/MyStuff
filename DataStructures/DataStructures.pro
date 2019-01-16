TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    ForwardList.cpp \
    Matrix3d.cpp \
    Vector3d.cpp \
    Graph.cpp

SUBDIRS += \
    DataStructures.pro

HEADERS += \
    ForwardList.h \
    Matrix3d.h \
    Vector3d.h \
    PriorityQueue.h \
    Graph.h
