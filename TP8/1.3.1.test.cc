#include "main_utils.h"
#include "1.3.h"

int main() {
  Matrix a = Matrix::Identity(5);
  Matrix b = a;
  Matrix c = b;
  c.Element(2, 1) = 4.5;
  CHECK_EQ(c.Element(2, 1), 4.5);
  CHECK_EQ(b.Element(2, 1), 0.0);
  CHECK_EQ(a.Element(2, 1), 0.0);
  cout << "PASSED" << endl;
}
