#include "1.1.h"

Matrix::Matrix(int num_rows, int num_columns) : num_rows_(num_rows), num_columns_(num_columns){
    elements_ = new double [num_rows*num_columns]();
};

Matrix::~Matrix(){
    delete[] elements_;
}

int Matrix::NumRows() const {return num_rows_;};
int Matrix::NumColumns() const {return num_columns_;};

double& Matrix::Element(int row, int col){
    return elements_[row * num_columns_ + col];
}

