#include "2.2.h"

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  const int size = 1000;
  const int avg_size = 20000;
  cout << "Creating a vector<Array> with " << size
       << " random arrays of average size " << avg_size << endl;
  vector<Array> v(size);
  for (int i = 0; i < size; ++i) {
    const int s = rand() % (2 * avg_size);
    for (int j = 0; j < s; ++j) v[i].push_back(rand());
  }
  cout << "Sorting it" << endl;
  clock_t c0 = clock();
  std::sort(v.begin(), v.end());
  clock_t c1 = clock();
  const double t = double(c1 - c0) / CLOCKS_PER_SEC;
  cout << "Sorted in " << t << " s" << endl;
  if (t < 0.001) {
    cout << "SUCCESS" << endl;
    return 0;
  } else {
    cout << "FAILED: too slow" << endl;
    return 1;
  }
}
