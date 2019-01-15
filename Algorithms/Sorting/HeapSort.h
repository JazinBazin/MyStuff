#pragma once
#include <cstddef>
#include "PriorityQueue.h"

template <typename T>
void heapSort(T *data, size_t size) {
    PriorityQueue<T> priorityQueue(data, size);
    for(size_t i = 0; i < size; ++i) {
        data[i] = priorityQueue.getMax();
        priorityQueue.popMax();
    }
}

