#include "1.4.h"
#include <cstdio>

void PrintMatrix(const Matrix& m){
    printf("[");
    for(int i = 0; i < m.NumRows(); i++){

        if (i == 0){
            printf("[");
        }else{
            printf(" [");
        }

        for(int j = 0; j < m.NumColumns(); j++){
            printf("% 8g", m.Element(i, j));
        }

        if(i < m.NumRows() - 1){
            printf("]\n");
        }else{
            printf("]");
        }
    }
    printf("]\n");
}

Matrix MatrixProd(const Matrix& a, const Matrix& b){
    Matrix M = Matrix(a.NumRows(), b.NumColumns());

    for(int i = 0; i < a.NumRows(); i++){
        for(int j=0 ;j < b.NumColumns(); j++){
            double s = 0;
            for(int k=0; k < a.NumColumns(); k++){
                s+=a.Element(i, k) * b.Element(k, j);
            }
            M.Element(i, j) = s;
        }
    }

    return M;
}

Matrix MatrixPower(const Matrix& m, int p){
    if(p == 0){
        return Matrix::Identity(m.NumRows());
    }else if(p == 1){
        return m;
    }else{
        Matrix halfPower = MatrixPower(m, p / 2);
        if(p % 2 == 0){
            return MatrixProd(halfPower, halfPower);
        }else{
            return MatrixProd(m, MatrixProd(halfPower, halfPower));
        }
    }
}