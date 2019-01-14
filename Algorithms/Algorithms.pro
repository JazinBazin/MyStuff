TEMPLATE = app
CONFIG += console c++1z
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    ForwardList.cpp \
    Vector3d.cpp

HEADERS += \
    BubbleSort.h \
    InsertionSort.h \
    SelectionSort.h \
    MergeSort.h \
    BezierCurve.h \
    ForwardList.h \
    Matrix3d.h \
    SplitString.h \
    Vector3d.h

SUBDIRS += \
    Algorithms.pro
