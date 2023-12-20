#include "1.2.h"

int main() {
  ShiftSequence s(new FibonacciSequence, 0);
  ShiftSequence s2(new FibonacciSequence, 1);
  s2 = s;
}
