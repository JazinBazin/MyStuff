#include <iostream>
#include "HeapSort.h"

using namespace std;

int main() {
    int data[] = {4, 7, 8, 6, 4, 9, 3, 8};
    heapSort(data, end(data) - begin(data));
    for(auto value : data)
        std::cout << value << " ";
    return 0;
}
