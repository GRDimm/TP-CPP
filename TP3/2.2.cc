
#include <iostream>
using namespace std;
      
struct Mat
{
  size_t n;
  size_t m;
        
  double *content;
        
  Mat(size_t _n, size_t _m, double *_content) : n(_n), m(_m) {
    content = _content;
  }
};
        
std::ostream& operator<<(std::ostream& os, const Mat& m)
{
  for (int i = 0; i < m.n; ++i)
  {
    os << "( ";
    for (int j = 0; j < m.m; ++j)
    {
      os << m.content[i * m.m + j] << " ";
    }
    os << ")" << std::endl;
  }
  return os;
}


int R2_to_R(int i, int j, int col){
    return i * col + j;
}

double* matrix_prod(int n, int m, int p, double* a, double* b) {
    // nm * mp returns np
    double* matrix_res = new double[n * p];

    for (int l = 0; l < n * p; l++) {
        double s = 0;

        int i = l / p;  // Calculate row index
        int j = l % p;  // Calculate column index

        for (int k = 0; k < m; k++) {
            s += a[R2_to_R(i, k, m)] * b[R2_to_R(k, j, p)];
        }

        matrix_res[l] = s;
    }

    return matrix_res;
}