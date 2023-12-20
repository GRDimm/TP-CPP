
#include "2.1.h"

Pixel::Pixel(): x_(0), y_(0), color_(0) {}
Pixel::Pixel(int x, int y, int color) : x_(x), y_(y), color_(color) {}

int Pixel::GetX() {
    return x_;
}

int Pixel::GetY() {
    return y_;
}

int Pixel::GetColor() {
    return color_;
}

// Setter methods
void Pixel::SetX(int x) {
    x_ = x;
}

void Pixel::SetY(int y) {
    y_ = y;
}