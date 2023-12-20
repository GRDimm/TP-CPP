#include "2.2.h"

const void PrintPixel(const Pixel* pixel);

const void ResetPixel(Pixel * pixel);

class PixelArray {
 public:
  PixelArray(const int num, const Pixel* pixels);

  const Pixel* GetPixel(const int i) const;

 private:
  const int num_;
  const Pixel* pixels_;
};