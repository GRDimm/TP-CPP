#include "1.4.h"
#include "matrix_ops.h"

int main() {
  Matrix m(2, 3);
  m.Element(0, 0) = 1;
  m.Element(0, 1) = 2;
  m.Element(0, 2) = 3.4;
  m.Element(1, 0) = -2.1;
  m.Element(1, 1) = 3.14159;
  m.Element(1, 2) = -9;
  PrintMatrix(m);
}
