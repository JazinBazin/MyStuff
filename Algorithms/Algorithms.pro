TEMPLATE = app
CONFIG += console c++1z
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \

HEADERS += \
    Geometry/BezierCurve.h \
    Sorting/BubbleSort.h \
    Sorting/InsertionSort.h \
    Sorting/MergeSort.h \
    Sorting/QuickSort.h \
    Sorting/SelectionSort.h \
    Strings/SplitString.h

SUBDIRS += \
    Algorithms.pro