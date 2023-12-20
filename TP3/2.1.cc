#include <iostream>

double trace(double* matrix, int N){
    double s = 0;
    for(int i = 0; i < N; i++){
        s += matrix[N*i + i];
    }
    return s;
}