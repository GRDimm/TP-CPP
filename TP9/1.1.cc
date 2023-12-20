#include "1.1.h"
#include <cstdio>

Pixel::Pixel(int x, int y) : x_(x), y_(y){};

int Pixel::X() const {
    return x_;
}

int Pixel::Y() const {
    return y_;
}

void Pixel::DebugPrint() const {
    if(this->IsValid()){
        printf("(%d, %d)\n", x_, y_);
    }else{
        printf("INVALID\n");
    }
}

bool Pixel::IsValid() const {
    return x_ >= 0 && y_ >= 0;
}