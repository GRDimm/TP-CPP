
#include <iostream>

#include "2.3.h"
        
using namespace std;
        
const void PrintPixel(const Pixel* pixel) {
  cout << "X=" << pixel->GetX() << "; Y=" << pixel->GetY() << endl;
}
        
const void ResetPixel(Pixel* pixel) {
  pixel->SetX(0);
  pixel->SetY(0);
}
        
// Compléter l'implémentation de PixelArray ci-dessous.

PixelArray::PixelArray(const int num, const Pixel* pixels) : num_(num), pixels_(pixels) {};

const Pixel* PixelArray::GetPixel(const int i) const {
    if (i >= 0 && i < num_) {
        return &pixels_[i];
    } else {
        return nullptr;
    }
}