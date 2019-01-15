#pragma once
#include <cstdint>

template <typename T>
int64_t binarySearch(T *A, int64_t size, const T& value) {
    int64_t l = 0, r = size;
    while(l < r) {
        int64_t m = l + (r - l) / 2;
        if(value < A[m])
            r = m;
        else if(value > A[m])
            l = m + 1;
        else
            return m;
    }
    return -1;
}
