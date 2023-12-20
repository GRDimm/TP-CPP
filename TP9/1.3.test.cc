#include "1.2.h"

void ApplyDebugPrintTo(const Pixel* p) {
  p->DebugPrint();
}

int main() {
  ColoredPixel colored_pix(1, 2, 0x334455);

  ApplyDebugPrintTo(&colored_pix);

  colored_pix.DebugPrint();

  ((const Pixel*)(&colored_pix))->DebugPrint();

  Pixel p = colored_pix;
  p.DebugPrint();
}
