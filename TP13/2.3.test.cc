#include "2.3.h"
#include "main_utils.h"
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

template<typename T>
string StrJoin(const T& v, const string& sep) {
  stringstream ss;
  int size = 0;
  for (const auto& x : v) {
    if (size++) ss << sep;
    ss << x;
  }
  return ss.str();
}

string VectorToSetStr(const vector<int>& v) {
  vector<int> sorted = v;
  sort(sorted.begin(), sorted.end());
  return "[" + StrJoin(sorted, ", ") + "]"; 
}

int main() {
  CHECK_EQ(StrJoin(GetBfsDistances({0}), ", "), "0");
  CHECK_EQ(StrJoin(GetBfsDistances({}), ", "), "");
  CHECK_EQ(StrJoin(GetBfsDistances({0, 0}), ", "), "0, 1");
  CHECK_EQ(StrJoin(GetBfsDistances({1, 1, 1, 1}), ", "), "1, 0, 1, 1");
  CHECK_EQ(StrJoin(GetBfsDistances({-1, 3, 2, 2}), ", "), "-1, 2, 0, 1");
  CHECK_EQ(StrJoin(GetBfsDistances({-1, 3, 2, 4, 5, 2, 3, 4, 6}), ", "),
           "-1, 4, 0, 3, 2, 1, 4, 3, 5");

  cout << "SUCCESS!\n";
}
