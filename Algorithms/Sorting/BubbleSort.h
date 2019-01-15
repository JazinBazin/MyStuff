#pragma once
#include <cstddef>
#include <utility>

template <typename T>
void bubbleSort(T *A, size_t size) {
    bool sorted = false;
    for(size_t i = 0; i + 1 < size && !sorted; ++i) {
        sorted = true;
        for(size_t j = size - 1; j > 0; --j) {
            if(A[j] < A[j - 1]) {
                sorted = false;
                using std::swap;
                swap(A[j], A[j - 1]);
            }
        }
    }
}

template <typename RAIterator>
void bubbleSort(RAIterator first, RAIterator last) {
    if(first == last)
        return;
    bool sorted = false;
    RAIterator beforeLast = last - 1, current, previus;
    while(first != beforeLast && !sorted) {
        sorted = true;
        current = beforeLast;
        while (current != first) {
           previus = current - 1;
           if(*current < *previus) {
               sorted = false;
               using std::swap;
               swap(*current, *previus);
           }
           current = previus;
        }
        ++first;
    }
}
