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
