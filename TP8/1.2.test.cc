#include "main_utils.h"
#include "1.2.h"

int main() {
  cout << "Testing the identity matrix..." << endl;
  const int n = 10000;
  Matrix i5 = Matrix::Identity(n);
  CHECK_EQ(i5.NumRows(), n);
  CHECK_EQ(i5.NumColumns(), n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      CHECK_EQ(i5.Element(i, j), i == j ? 1 : 0);
    }
  }
  cout << "PASSED" << endl;
}
