class Matrix {
 public:
  Matrix(int num_rows, int num_columns);
  ~Matrix();

  int NumRows() const;
  int NumColumns() const;

  double& Element(int row, int col);

 private:
  int num_rows_;
  int num_columns_;
  // We'll use the "flat" representation.
  double* elements_;
};
