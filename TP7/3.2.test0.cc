#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "3.2.h"

using namespace std;

#define CHECK(x) do {\
  if (!(x)) {\
    cout << "ERROR in " __FILE__ ":" << __LINE__\
         << ": CHECK condition violated: " #x << std::endl;\
    cout.flush();\
    exit (1);\
  }\
} while(0)

int main() {
  cout << "Basic tests...\n";
  Array a(5);
  CHECK(a.size() == 0);
  a.push_back(3);
  a.push_back(2);
  a.push_back(1);
  a.push_back(0);
  a.push_back(-1);
  CHECK(a.size() == 5);
  CHECK(a[0] == 3);
  CHECK(a[1] == 2);
  CHECK(a[2] == 1);
  CHECK(a[3] == 0);
  CHECK(a[4] == -1);
  a[4] = 3;
  a.pop_back();
  a.pop_back();
  CHECK(a.size() == 3);
  a[1] = -2;
  CHECK(a[0] == 3);
  CHECK(a[1] == -2);
  CHECK(a[2] == 1);

  cout << "PASSED!\nRunning the memory leak check (if this doesn't stop very quickly, you probably have a memory leak...)\n";
  clock_t c = clock();
  int s = 0;
  for (int i = 0; i < 100000; ++i) {
    Array a(1000000);
    s += a.size();
  }
  cout << "This took " << double(clock() - c) / CLOCKS_PER_SEC << " seconds [debug: " << s << "]\n";
  cout << "PASSED!\nRunning the randomized correctness test...\n";
  {
    c = clock();
    const int max_size = 100 << 5;
    const int num_ops = 20 << 10;
    Array a(max_size);
    vector<double> v;
    srand(0);
    for (int i = 0; i < num_ops; ++i) {
      if (v.empty() || (v.size() < max_size && rand() % 2 == 0)) {
        const double d = double(rand()) / RAND_MAX;
        a.push_back(d);
        v.push_back(d);
      } else {
        a.pop_back();
        v.pop_back();
      }
    }
    CHECK(a.size() == v.size());
    CHECK(v.size() > sqrt(num_ops) / 4);
    for (int i = 0; i < v.size(); ++i) {
      CHECK(a[i] == v[i]);
    }
  }
  cout << "PASSED! In " << double(clock() - c) / CLOCKS_PER_SEC << " seconds.\n";
}
