#include "2.2.h"
#include <cstring>
#include <algorithm>

namespace {
const int kMinArrayCapacity = 8;
}  // namespace

Array::Array() : size_(0), capacity_(kMinArrayCapacity), data_(new double[capacity_]) {}

Array::~Array() {
  delete[] data_;
}

Array::Array(Array&& other)
    : size_(other.size_),
      capacity_(other.capacity_),
      data_(other.data_) {
  other.size_ = 0;
  other.capacity_ = 0;
  other.data_ = nullptr;
}

Array::Array(const Array& other)
  : size_(other.size_),
    capacity_(other.capacity_),
    data_(new double[capacity_]) {
  for (int i = 0; i < size_; ++i) data_[i] = other.data_[i];
}

int Array::size() const {
  return size_;
}

double& Array::operator[](int i) {
  return data_[i];
}

void Array::push_back(double x) {
  if (size_ == capacity_) {
    // We need to grow! Double the size.
    capacity_ *= 2;
    double* new_data = new double[capacity_];
    std::memcpy(new_data, data_, sizeof(double) * size_);
    delete[] data_;
    data_ = new_data;
  }
  data_[size_++] = x;
}

void Array::pop_back() {
  --size_;
  if (size_ < capacity_ / 4 && capacity_ > kMinArrayCapacity) {
    // We need to shrink! Halve the size.
    capacity_ /= 2;
    double* new_data = new double[capacity_];
    std::memcpy(new_data, data_, sizeof(double) * size_);
    delete[] data_;
    data_ = new_data;
  }
}

const double& Array::operator[](int i) const {
    return data_[i];
}

bool Array::operator<(Array& other) const {
    for (int i = 0; i < std::min(size_, other.size_); ++i) {
        if (data_[i] < other.data_[i]) {
            return true;
        } else if (data_[i] > other.data_[i]) {
            return false;
        }
    }
    return size_ < other.size_;
}

Array& Array::operator=(Array&& other) noexcept {
    if (this != &other) {
        delete[] data_; // Libérer les anciennes ressources

        data_ = other.data_; // Transférer les ressources
        size_ = other.size_;
        capacity_ = other.capacity_;

        other.data_ = nullptr; // Mettre à jour l'objet source
        other.size_ = 0;
        other.capacity_ = 0;
    }
    return *this;
}
