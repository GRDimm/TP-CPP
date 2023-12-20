

#include "3.3.h"
#include <iostream>

using namespace std;

#include <stdexcept>  

Array::Array(int capacity)
    : capacity_(capacity), size_(0), data_(new double[capacity_]) {}

Array::~Array() {
    delete[] data_;
}

Array::Array(const Array& other)
    : capacity_(other.capacity_), size_(other.size_), data_(new double[capacity_]) {
    for (int i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        delete[] data_;

        capacity_ = other.capacity_;
        size_ = other.size_;
        data_ = new double[capacity_];
        for (int i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

int Array::size() const {
    return size_;
}

double& Array::operator[](int i) {
    if (i < 0 || i >= size_) {
        throw std::out_of_range("Index du tableau hors limites.");
    }
    return data_[i];
}

void Array::push_back(double x) {
    if (size_ < capacity_) {
        data_[size_] = x;
        ++size_;
    } else {
        throw std::out_of_range("Capacité du tableau dépassée.");
    }
}

void Array::pop_back() {
    if (size_ > 0) {
        --size_;
    } else {
        throw std::out_of_range("Tentative de supprimer un élément d'un tableau vide.");
    }
}
