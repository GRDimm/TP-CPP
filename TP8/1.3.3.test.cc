#include "main_utils.h"
#include "1.3.h"

int main() {
  const int rows = 10000;
  const int cols = 1000;
  const int fill = 1000000;
  Matrix a(rows, cols);
  Random random(0xCAFE);
  for (int i = 0; i < fill; i++) {
    a.Element(random.Uniform(rows), random.Uniform(cols)) = random.Uniform(1000);
  }
  cout << "Testing that a copy has the same size" << endl;
  Matrix b = a;
  CHECK_EQ(b.NumRows(), a.NumRows());
  CHECK_EQ(b.NumColumns(), a.NumColumns());
  cout << "PASSED!\nTesting that a copy has the same values" << endl;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      CHECK_EQ(a.Element(i, j), b.Element(i, j));
    }
  }
  cout << "PASSED!\nTesting that a matrix and its copy are independent" << endl;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      a.Element(i, j) = b.Element(i, j) + 1;
    }
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      CHECK_EQ(a.Element(i, j),  b.Element(i, j) + 1);
    }
  }
  cout << "PASSED" << endl;
}
