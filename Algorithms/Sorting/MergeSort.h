#pragma once
#include <cstddef>
#include <iterator>

template <typename T>
void merge(T *A, size_t l, size_t mid, size_t r) {
    T *merged = new T[r - l];
    size_t i = l, j = mid, t = 0;
    while(i < mid && j < r) {
        if(A[i] < A[j])
            merged[t++] = A[i++];
        else
            merged[t++] = A[j++];
    }
    while(i < mid)
        merged[t++] = A[i++];
    while(j < r)
        merged[t++] = A[j++];
    for(size_t k = l; k < r; ++k)
        A[k] = merged[k - l];
    delete [] merged;
}

template <typename T>
void mergeSortR(T *A, size_t l, size_t r) {
    if(r > l + 1) {
        size_t mid = l + (r - l) / 2;
        mergeSortR(A, l, mid);
        mergeSortR(A, mid, r);
        merge(A, l, mid, r);
    }
}

template <typename T>
void mergeSort(T *A, size_t size) {
    mergeSortR(A, 0, size);
}
