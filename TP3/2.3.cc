#include <iostream>

// Computes the transpose of a NxM matrix (see wikipedia), in-place. Stores
// the result in the source matrix.
void transpose(int n, int m, double* matrix) {
    double* temp_matrix = new double[n * m]; //Temp

    //Copy & transpose
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp_matrix[j * n + i] = matrix[i * m + j];
        }
    }

    //Copy res
    for (int i = 0; i < n * m; i++) {
        matrix[i] = temp_matrix[i];
    }

}