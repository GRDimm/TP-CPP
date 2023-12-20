#include "2.4.h"
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
  CHECK_EQ(StrJoin(GetShortestPathFromRootedTree({0}, 0), ", "), "0");
  CHECK_EQ(StrJoin(GetShortestPathFromRootedTree({0, -1}, 1), ", "), "");
  CHECK_EQ(StrJoin(GetShortestPathFromRootedTree({0, 0}, 1), ", "), "0, 1");
  CHECK_EQ(StrJoin(GetShortestPathFromRootedTree({1, 2, 3, 3}, 0), ", "), "3, 2, 1, 0");
  CHECK_EQ(StrJoin(GetShortestPathFromRootedTree({-1, 3, 2, 4, 5, 2, 3, 4, 6}, 8), ", "),
           "2, 5, 4, 3, 6, 8");
  CHECK_EQ(StrJoin(GetShortestPathFromRootedTree({-1, 3, 2, 4, 5, 2, 3, 4, 6}, 2), ", "),
           "2");
  CHECK_EQ(StrJoin(GetShortestPathFromRootedTree({-1, 3, 2, 4, 5, 2, 3, 4, 6}, 0), ", "),
           "");
  CHECK_EQ(StrJoin(GetShortestPathFromRootedTree({-1, 3, 2, 4, 5, 2, 3, 4, 6}, 1), ", "),
           "2, 5, 4, 3, 1");

  cout << "SUCCESS!\n";
}
