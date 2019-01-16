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
