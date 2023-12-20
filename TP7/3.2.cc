

#include "3.2.h"
#include <iostream>

using namespace std;

#include <stdexcept>

Array::Array(int capacity)
    : size_(0), data_(new double[capacity]) {}

Array::~Array() {
    delete[] data_;
}

int Array::size() const {
    return size_;
}

double& Array::operator[](int i) {
    if (i < 0 || i >= size_) {
        throw std::out_of_range("Array index out of range.");
    }
    return data_[i];
}

void Array::push_back(double x) {
    data_[size_] = x;
    ++size_;
}

void Array::pop_back() {
    if (size_ > 0) {
        --size_;
    } else {
        throw std::out_of_range("Trying to pop from an empty array.");
    }
}
