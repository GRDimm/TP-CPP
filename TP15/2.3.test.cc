#include "main_utils.h"
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

#include "2.3.h"

template <typename V>
std::string Print(const V& v) {
  std::ostringstream os;
  char sep = '[';
  for (const auto& x : v) {
    os << sep << x;
    sep = ' ';
  }
  os << ']';
  return os.str();
}

int main() {
  vector<string> yop = {"Cov", "Fe", "Fe", "A", "", "B", "X", "Y", ""};
  function<bool(const string&)> f = [](const string& s) { return s > "CovFeFe"; };
  Select(&yop, f);
  CHECK_EQ(Print(yop), "[Fe Fe X Y]");
  Select(&yop, f);
  CHECK_EQ(Print(yop), "[Fe Fe X Y]");
  cout << "PASSED test #0" << endl;

  vector<char> a1 = {'a', 'b', 'c', 'd'};
  Select(&a1, [](char) { return true; });
  CHECK_EQ(a1.size(), 4);
  Select(&a1, [](char) { return false; });
  CHECK_EQ(a1.size(), 0);
  Select(&a1, [](char) { return true; });
  CHECK_EQ(a1.size(), 0);
  Select(&a1, [](char) { return false; });
  CHECK_EQ(a1.size(), 0);
  cout << "PASSED some corner cases" << endl;

  cout << "Starting performance test" << endl;
  vector<int> t2;
  const int num = 1000000;
  t2.reserve(num);
  clock_t c0 = clock();
  for (int i = 0; i < num; ++i) t2.push_back(i * 3);
  Select(&t2, [](int x) { return (x & 0xFF) == 0x2B; });
  for (int i = 0; i < 100; ++i) {
    Select(&t2, [](int) { return true; });
  }
  const double t = double(clock() - c0) / CLOCKS_PER_SEC;
  cout << "Finished in " << t << " s." << endl;
  CHECK_EQ(t2.size(), num / 256);
  cout << "Correct" << endl;
  if (t < 0.005) {
    cout << "PASSED!" << endl;
  } else {
    cout << "FAILED: Too slow!" << endl;
    return 1;
  }
}

