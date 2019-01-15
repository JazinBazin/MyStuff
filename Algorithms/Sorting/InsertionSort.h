#pragma once
#include <cstddef>

template <typename T>
void insertionSort(T *A, size_t size) {
    size_t i, j;
    for(i = 1; i < size; ++i) {
        j = i;
        T key = A[i];
        while(j != 0 && key < A[j - 1]) {
            A[j] = A[j - 1];
            --j;
        }
        A[j] = key;
    }
}

template <typename RAIterator>
void insertionSort(RAIterator first, RAIterator last) {
    if(first == last)
        return;
    RAIterator beg = first, current;
    while(++first != last) {
        current = first;
        auto key = *current;
        while(current != beg && key < *(current - 1)) {
            *current = *(current - 1);
            --current;
        }
        *current = key;
    }
}
