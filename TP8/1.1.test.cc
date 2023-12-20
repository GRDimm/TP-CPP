#include "main_utils.h"
#include "1.1.h"

int main() {
  cout << "Testing construction..." << endl;
  Matrix m(5, 2);
  CHECK_EQ(m.NumRows(), 5);
  CHECK_EQ(m.NumColumns(), 2);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 2; j++) {
      CHECK_EQ(m.Element(i, j), 0.0);
    }
  }

  cout << "PASSED!\nTesting assignment..." << endl;
  m.Element(3, 2) = 4.5;
  CHECK_EQ(m.Element(3, 2), 4.5);
  m.Element(4, 1) = 1.3;
  m.Element(4, 1) = -3e8;
  CHECK_EQ(m.Element(4, 1), -3e8);
  CHECK_EQ(m.Element(0, 0), 0);
  CHECK_EQ(m.Element(4, 1), -3e8);

  // For the memory leak detection, we assume that this programs runs
  // with a memory limit < 8GB (via ulimit -S -v 1000000 for example, for 1GB).
  cout << "PASSED!\nTesting performance + memory initialization + memory leaks." << endl;
  clock_t c0 = clock();
  double s = 0;
  const int size = 1000000;
  const int times = 1000;
  const int fill = 100;
  Random random(0xDEADBEEF);
  for (int i = 0; i < times; ++i) {
    const int rows = exp(random.RandDouble() * log(size));
    const int cols = size / rows;
    CHECK(cols > 0);
    Matrix m(rows, cols);
    CHECK_EQ(m.NumRows(), rows);
    CHECK_EQ(m.NumColumns(), cols);
    // Fill some elements of the matrix. We need to do this because the linux
    // kernel might "give" you a lot of free memory that's fake and it won't
    // actually allocate the physical memory until you really write in it.
    for (int j = 0; j < fill; j++) {
      m.Element(random.Uniform(rows), random.Uniform(cols)) = 1.0;
    }
    // Read back some elements of the matrix. Thanks to the birthday paradox,
   // we do expect some collisions with elements that were set above. See the
   // formulae used below.
    for (int j = 0; j < fill; j++) {
      s += m.Element(random.Uniform(rows), random.Uniform(cols));
    }
  }
  const double expected = double(fill * fill) * times / size;
  CHECK_GT(s, expected / 2);
  CHECK_LT(s, expected * 2);
  cout << "PASSED in " << double(clock() - c0) / CLOCKS_PER_SEC << "s!" << endl;
}
