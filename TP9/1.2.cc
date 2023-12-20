#include "1.2.h"
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

ColoredPixel::ColoredPixel(int x, int y, int color_rgb) : Pixel(x, y), color_rgb_(color_rgb){};

int ColoredPixel::ColorRgb() const {
    return color_rgb_;
}

void ColoredPixel::DebugPrint() const {
    if(this->IsValid()){
        int color = this->ColorRgb();

        int r = (color >> 16) & 0xFF;
        int g = (color >> 8) & 0xFF;
        int b = color & 0xFF;

        printf("(%d, %d, R%d:G%d:B%d)\n", this->X(), this->Y(), r, g, b);
    }else{
        printf("INVALID\n");
    }
}