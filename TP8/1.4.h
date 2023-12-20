#ifndef _1_4_H
#define _1_4_H

class Matrix {
 public:
  Matrix(int num_rows, int num_columns);
  Matrix(const Matrix& M);
  ~Matrix();

  int NumRows() const;
  int NumColumns() const;

  double& Element(int row, int col) const;
  static Matrix Identity(int n);

  Matrix& operator=(Matrix& M);

 private:
  int num_rows_;
  int num_columns_;
  // We'll use the "flat" representation.
  double* elements_;
};

#endif
