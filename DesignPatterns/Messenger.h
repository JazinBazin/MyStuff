#pragma once
#include <cstddef>
#include <stdexcept>
#include <iostream>

template <typename T>
class Messenger {
public:
    Messenger(size_t Size) :
        data(new T[Size]), size(Size) {}

    ~Messenger() {
        delete [] data;
    }

    Messenger(const Messenger &other) = delete;
    Messenger& operator=(const Messenger &other) = delete;
    Messenger(Messenger &&other) = delete;

    T& operator[](size_t index) {
        if(index >= size)
            std::range_error("Vector::operator[]. index out of range");
        return data[index];
    }

    const T& operator[](size_t index) const {
        if(index >= size)
            std::range_error("Vector::operator[]. index out of range");
        return data[index];
    }

    size_t getSize() const {
        return size;
    }

    T* begin() {
        return data;
    }

    T* end() {
        return data + size;
    }

    const T* begin() const {
        return data;
    }

    const T* end() const {
        return data + size;
    }

private:
    T *data;
    size_t size;
};

// one parameter instead of two
template <typename T>
void printData(const Messenger<T> &data) {
    for(const T &item : data)
        std::cout << item << " ";
}
