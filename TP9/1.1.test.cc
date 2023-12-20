#include "1.1.h"
#include "main_utils.h"
#include <iostream>
using namespace std;

int main() {
  Pixel p(4, 3);
  CHECK_EQ(p.X(), 4);
  CHECK_EQ(p.Y(), 3);
  p.DebugPrint();
  Pixel(-1, 3).DebugPrint();
  Pixel(0, 0).DebugPrint();
  Pixel(4, -1).DebugPrint();
}
