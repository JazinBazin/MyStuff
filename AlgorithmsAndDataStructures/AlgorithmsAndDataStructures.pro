GOOGLETEST_DIR = ../GoogleTest
GTEST_SRCDIR = $$GOOGLETEST_DIR/googletest
GMOCK_SRCDIR = $$GOOGLETEST_DIR/googlemock

DEFINES += \
    GTEST_LANG_CXX11

INCLUDEPATH *= \
    $$GTEST_SRCDIR \
    $$GTEST_SRCDIR/include \
    $$GMOCK_SRCDIR \
    $$GMOCK_SRCDIR/include

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += thread

SOURCES += \
        main.cpp \
    $$GTEST_SRCDIR/src/gtest-all.cc \
    $$GMOCK_SRCDIR/src/gmock-all.cc \
    DataStructures/ForwardList.cpp \
    DataStructures/Graph.cpp \
    DataStructures/Matrix3d.cpp \
    DataStructures/Vector3d.cpp

HEADERS += \
    Algorithms/Geometry/BezierCurve.h \
    Algorithms/Search/BinarySearch.h \
    Algorithms/Sorting/BubbleSort.h \
    Algorithms/Sorting/HeapSort.h \
    Algorithms/Sorting/InsertionSort.h \
    Algorithms/Sorting/MergeSort.h \
    Algorithms/Sorting/QuickSort.h \
    Algorithms/Sorting/SelectionSort.h \
    Algorithms/Strings/ReverseString.h \
    Algorithms/Strings/Search.h \
    Algorithms/Strings/SplitString.h \
    DataStructures/ForwardList.h \
    DataStructures/Graph.h \
    DataStructures/Matrix3d.h \
    DataStructures/PriorityQueue.h \
    DataStructures/Vector3d.h \
    Algorithms/Geometry/BezierCurve.h \
    Algorithms/Search/BinarySearch.h \
    Algorithms/Sorting/BubbleSort.h \
    Algorithms/Sorting/HeapSort.h \
    Algorithms/Sorting/InsertionSort.h \
    Algorithms/Sorting/MergeSort.h \
    Algorithms/Sorting/QuickSort.h \
    Algorithms/Sorting/SelectionSort.h \
    Algorithms/Strings/ReverseString.h \
    Algorithms/Strings/Search.h \
    Algorithms/Strings/SplitString.h \
    DataStructures/ForwardList.h \
    DataStructures/Graph.h \
    DataStructures/Matrix3d.h \
    DataStructures/PriorityQueue.h \
    DataStructures/Vector3d.h \
    Tests/Tests.h
