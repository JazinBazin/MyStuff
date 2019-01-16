#pragma once
#include <cstddef>
#include <utility>

template <typename T>
void siftDown(T *data, size_t index, size_t size) {
    size_t indexToSwapWith = index;
    size_t leftChildIndex = 2 * index + 1;
    if(leftChildIndex < size && data[leftChildIndex] < data[indexToSwapWith])
        indexToSwapWith = leftChildIndex;
    size_t rightChildIndex = 2 * (index + 1);
    if(rightChildIndex < size && data[rightChildIndex] < data[indexToSwapWith])
        indexToSwapWith = rightChildIndex;
    if(indexToSwapWith != index) {
        std::swap(data[index], data[indexToSwapWith]);
        siftDown(data, indexToSwapWith, size);
    }
}

template <typename T>
void heapSort(T *data, size_t size) {
    T *priorityQueue = new T[size];
    for(size_t i = 0; i < size; ++i)
        priorityQueue[i] = data[i];
    for(size_t i = size / 2; i > 0; --i)
        siftDown(priorityQueue, i - 1, size);
    for(size_t i = 0, j = size - 1; i < size; ++i, --j) {
        data[i] = priorityQueue[0];
        std::swap(priorityQueue[0], priorityQueue[j]);
        siftDown(priorityQueue, 0, j);
    }
    delete [] priorityQueue;
}

