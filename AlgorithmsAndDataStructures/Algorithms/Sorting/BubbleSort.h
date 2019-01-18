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
