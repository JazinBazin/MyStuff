TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    DataStructures/ForwardList.cpp \
    DataStructures/Graph.cpp \
    DataStructures/Matrix3d.cpp \
    DataStructures/Vector3d.cpp

HEADERS += \
    Algorithms/Geometry/BezierCurve.h \
    Algorithms/Graphs/DijkstraAlgorithm.h \
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
    DataStructures/Vector3d.h
