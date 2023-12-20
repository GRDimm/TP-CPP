#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "3.3.h"

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
  cout << "Basic tests..." << endl;
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

  cout << "PASSED!\nRunning the memory leak check (if this doesn't stop very quickly, you probably have a memory leak...)" << endl;
  clock_t c = clock();
  int s = 0;
  for (int i = 0; i < 100000; ++i) {
    Array a(1000000);
    s += a.size();
  }
  cout << "This took " << double(clock() - c) / CLOCKS_PER_SEC << " seconds [debug: " << s << "]" << endl;
  cout << "PASSED!\nRunning the randomized correctness test..." << endl;
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
  cout << "PASSED! In " << double(clock() - c) / CLOCKS_PER_SEC << " seconds." << endl;

  cout << "Testing the copy construction..." << endl;
  {
    Array a(4);
    a.push_back(3.2);
    a.push_back(4.1);
    a.push_back(5.3);
    a.push_back(6.6);
    a.pop_back();
    for (int iter = 0; iter < 1000; ++iter) {
      Array b = a;
      CHECK(b.size() == 3);
      for (int i = 0; i < b.size(); ++i) CHECK(a[i] == b[i]);
      b.push_back(99.99);
      {
        Array c = b;
        CHECK(c.size() == 4);
        for (int i = 0; i < a.size(); ++i) CHECK(a[i] == c[i]);
        for (int i = 0; i < c.size(); ++i) c[i] = i;
        {
          Array d = c;
          CHECK(d.size() == 4);
          for (int i = 0; i < d.size(); ++i) CHECK(d[i] == i);
          for (int i = 0; i < d.size(); ++i) d[i] = 2*i;
          d.pop_back();
          d.pop_back();
          d.pop_back();
          d.pop_back();
        }
        for (int i = 0; i < c.size(); ++i) CHECK(c[i] == i);
      }
      for (int i = 0; i < a.size(); ++i) CHECK(a[i] == b[i]);
      CHECK(b[3] == 99.99);
    }
    CHECK(a.size() == 3);
    CHECK(a[0] == 3.2);
    CHECK(a[1] == 4.1);
    CHECK(a[2] == 5.3);
  }
  cout << "PASSED!" << endl;

  cout << "Testing the assignment (this should take 3 to 10 seconds)..." << endl;
  {
    const int size = 500000;
    const int num_iters = 10000;
    Array a(size + num_iters);
    for (int i = 0; i < size; ++i) a.push_back(2 * i);
    Array b = a;
    Array c = a;
    CHECK(b.size() == size);
    for (int iter = 0; iter < num_iters; ++iter) {
      b.push_back(iter);
      c = b;
      CHECK(c.size() == iter + 1 + size);
      CHECK(c[c.size() - 1] == iter);
    }
    CHECK(a.size() == size);
    for (int i = 0; i < a.size(); ++i) CHECK(a[i] == 2 * i);
  }
  cout << "PASSED!" << endl;
}
