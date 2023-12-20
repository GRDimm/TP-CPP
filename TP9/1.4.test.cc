#include "1.4.h"
#include "main_utils.h"
#include <iostream>
using namespace std;

int main() {
  ColoredPixel p(4, 3, 0xff3580);
  CHECK_EQ(p.X(), 4);
  CHECK_EQ(p.Y(), 3);
  CHECK_EQ(p.ColorRgb(), 0xff3580);
  p.DebugPrint();
  ColoredPixel(-1, 3, 12345).DebugPrint();
  ColoredPixel(0, 0, 0).DebugPrint();
  ColoredPixel(4, -1, 0xff3580).DebugPrint();
}
