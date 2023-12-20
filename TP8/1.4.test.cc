#include "main_utils.h"
#include "1.4.h"

int main() {
  Matrix a(4, 3);
  a.Element(2, 1) = 42.0;
  a.Element(3, 2) = -3.5;
  const Matrix b = a;
  cout << "b[2][1] = " << b.Element(2, 1) << endl;
  cout << "b[3][2] = " << b.Element(3, 2) << endl;
  cout << "PASSED" << endl;
}
