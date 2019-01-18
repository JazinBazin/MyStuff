#pragma once
#include <cstddef>
#include <utility>

template <typename T>
size_t partition(T *A, size_t l, size_t r) {
    T &pivot = A[r - 1];
    size_t i = l;
    for(size_t j = l; j < r - 1; ++j) {
        if(A[j] < pivot) {
            std::swap(A[i], A[j]);
            ++i;
        }
    }
    std::swap(A[i], A[r - 1]);
    return i;
}

template <typename T>
void quickSortR(T *A, size_t l , size_t r) {
    if(l < r) {
        size_t pi = partition(A, l, r);
        quickSortR(A, l, pi);
        quickSortR(A, pi + 1, r);
    }
}

template <typename T>
void quickSort(T *A, size_t size) {
    quickSortR(A, 0, size);
}
