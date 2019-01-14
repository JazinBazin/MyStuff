#pragma once
#include <cstddef>
#include <utility>

template <typename T>
void selectionSort(T *A, size_t size) {
    size_t indexOfMinElement;
    for(size_t i = 0; i + 1 < size; ++i) {
        indexOfMinElement = i;
        for(size_t j = i + 1; j < size; ++j)
            if(A[j] < A[indexOfMinElement])
                indexOfMinElement = j;
        using std::swap;
        swap(A[i], A[indexOfMinElement]);
    }
}

template <typename RAIterator>
void selectionSort(RAIterator first, RAIterator last) {
    RAIterator min, current;
    while(first != last) {
        min = first;
        current = first + 1;
        while(current != last) {
            if(*current < *min)
                min = current;
            ++current;
        }
        using std::swap;
        swap(*first, *min);
        ++first;
    }
}
