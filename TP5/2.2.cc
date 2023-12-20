
#include "2.2.h"

Pixel::Pixel(): x_(0), y_(0), color_(0) {}
Pixel::Pixel(const int x, const int y, const int color) : x_(x), y_(y), color_(color) {}

const int Pixel::GetX() const {
    return x_;
}

const int Pixel::GetY() const {
    return y_;
}

const int Pixel::GetColor() const {
    return color_;
}

const void Pixel::SetX(const int x) {
    x_ = x;
}

const void Pixel::SetY(const int y) {
    y_ = y;
}