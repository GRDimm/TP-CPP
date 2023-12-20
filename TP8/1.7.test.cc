#include "1.4.h"
#include "matrix_ops.h"
#include "main_utils.h"

int main() {
  Matrix a = Matrix::Identity(3);
  Matrix b = Matrix::Identity(3);
  Matrix c = MatrixProd(a, b);
  CHECK_EQ(3, c.NumRows());
  CHECK_EQ(3, c.NumColumns());
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      CHECK_EQ(c.Element(i, j), i == j ? 1.0 : 0.0);
    }
  }

  cout << "Test de performance simple, avec l'identité\n";
  {
    const int size = 100;
    Matrix m = Matrix::Identity(size);
    Matrix p = MatrixPower(m, 1020928141);
    CHECK_EQ(p.NumRows(), size);
    CHECK_EQ(p.NumColumns(), size);
    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
        CHECK_EQ(p.Element(i, j), i == j ? 1.0 : 0.0);
      }
    }
    cout << "SUCCESS" << endl;
  }

  cout << "Test de calcul avec une matrice pré-calculée\n";
  {
    Matrix m(3, 3);
    m.Element(0, 0) = 0.1;
    m.Element(0, 1) = 1.2;
    m.Element(0, 2) = -1.3;
    m.Element(1, 0) = 0.5;
    m.Element(1, 1) = -0.314159;
    m.Element(1, 2) = 1.542497;
    m.Element(2, 0) = -0.1;
    m.Element(2, 1) = 0.0;
    m.Element(2, 2) = 0.776;
    PrintMatrix(m);
    Matrix p = MatrixPower(m, 918273912);
    cout << ".. mise à la puissance 918273912, donne:" << endl;
    PrintMatrix(p);
    CHECK_NEAR(p.Element(0, 0),   0.0429273, 1e-5);
    CHECK_NEAR(p.Element(0, 1),  -0.0751089, 1e-5);
    CHECK_NEAR(p.Element(0, 2),   0.0966559, 1e-5);
    CHECK_NEAR(p.Element(1, 0),  -0.0367315, 1e-5);
    CHECK_NEAR(p.Element(1, 1),   0.0642683, 1e-5);
    CHECK_NEAR(p.Element(1, 2),  -0.0827054, 1e-5);
    CHECK_NEAR(p.Element(2, 0),  0.00241708, 1e-5);
    CHECK_NEAR(p.Element(2, 1), -0.00422911, 1e-5);
    CHECK_NEAR(p.Element(2, 2),  0.00544234, 1e-5);
    cout << "SUCCESS" << endl;
  }

  cout << "Corner case: puissance zero (sur une grosse matrice)\n";
  {
    Matrix m(128, 128);
    for (int i = 0; i < 128; ++i) {
      for (int j = 0; j < 128; ++j) {
        m.Element(i, j) = i * j;
      }
    }
    Matrix p = MatrixPower(m, 0);
    for (int i = 0; i < 128; ++i) {
      for (int j = 0; j < 128; ++j) {
        CHECK_EQ(p.Element(i, j), i == j ? 1 : 0);
      }
    }
    cout << "SUCCESS" << endl;
  }
}
