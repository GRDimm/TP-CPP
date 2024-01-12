#include "main_utils.h"

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "2.1.h"

using namespace std;

string Print(const vector<int>& v) {
  ostringstream os;
  os << '[';
  if (!v.empty()) os << v[0];
  for (int i = 1; i < v.size(); ++i) os << ' ' << v[i];
  os << ']';
  return os.str();
}

int main() {
  {
    Array a1;
    Array a2;
    a1.push_back(1);
    a1.push_back(2);
    a1.push_back(3);
    a1.push_back(4);
    a2.push_back(1);
    a2.push_back(2);
    a2.push_back(4);
    CHECK(a1 < a2);
    CHECK(!(a2 < a1));
    cout << "PASSED: [1,2,3,4] < [1,2,4]" << endl;
  }
  {
    Array a1;
    Array a2;
    a2.push_back(0);
    a2.push_back(0);
    CHECK(a1 < a2);
    CHECK(!(a2 < a1));
    cout << "PASSED: [] < [0, 0]" << endl;
  }
  {
    Array a1;
    a1.push_back(9);
    a1.push_back(9);
    a1.push_back(9);
    CHECK(!(a1 < a1));
    cout << "PASSED: [9, 9, 9] == [9, 9, 9]" << endl;
  }

  cout << "Starting randomized correctness test..." << endl;
  {
    const int num = 1000000;
    const int avg_size = 5;
    for (int i = 0; i < num; ++i) {
      const int s1 = rand() % (avg_size * 2);
      const int s2 = rand() % (avg_size * 2);
      vector<int> v1, v2;
      Array a1, a2;
      for (int i = 0; i < s1; ++i) {
        const int x = rand() % 3;
        v1.push_back(x);
        a1.push_back(x);
      }
      for (int i = 0; i < s2; ++i) {
        const int x = rand() % 3;
        v2.push_back(x);
        a2.push_back(x);
      }
      if ((a1 < a2) != (v1 < v2)) {
        cout << "FAILED on: " << Print(v1) << " < " << Print(v2) << endl;
        return 1;
      }
      if ((a2 < a1) != (v2 < v1)) {
        cout << "FAILED on: " << Print(v2) << " < " << Print(v1) << endl;
        return 1;
      }
    }
    cout << "PASSED!" << endl;
  }

  cout << "Starting performance test..." << endl;
  {
    const int num = 1000;
    const int avg_size = 10000;
    Array* all = new Array[num];
    for (int i = 0; i < num; ++i) {
      const int s = rand() % (avg_size * 2);
      for (int j = 0; j < s; ++j) {
        all[i].push_back(rand() % 3);
      }
    }
    int num_inf = 0;
    clock_t c0 = clock();
    for (int i = 0; i < num; ++i) {
      for (int j = 0; j < num; ++j) {
        if (all[i] < all[j]) ++num_inf;
      }
    }
    const double t = double(clock() - c0) / CLOCKS_PER_SEC;
    cout << "Time: " << t << " s" << endl;
    CHECK_EQ(num_inf, num * (num - 1) / 2);
    cout << "Correct!" << endl;
    if (t < 0.1) {
      cout << "PASSED!" << endl;
    } else {
      cout << "FAILED: Too slow!" << endl;
      return 1;
    }
  }
}
