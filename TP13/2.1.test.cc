#include "2.1.h"
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
  DirectedGraph g;
  // Empty graph
  CHECK_EQ(0, g.NumNodes());

  // Build the example in 2.1.h
  g.AddArc(1, 0);
  g.AddArc(1, 3);
  g.AddArc(3, 1);
  g.AddArc(2, 0);
  g.AddArc(1, 2);
  g.AddArc(3, 4);
  g.AddArc(3, 4);
  CHECK_EQ(5, g.NumNodes());
  CHECK_EQ(0, g.OutDegree(0));
  CHECK_EQ(3, g.OutDegree(1));
  CHECK_EQ(1, g.OutDegree(2));
  CHECK_EQ(3, g.OutDegree(3));
  CHECK_EQ(0, g.OutDegree(4));
  CHECK_EQ("[]", VectorToSetStr(g.Neighbors(0)));
  CHECK_EQ("[0, 2, 3]", VectorToSetStr(g.Neighbors(1)));
  CHECK_EQ("[0]", VectorToSetStr(g.Neighbors(2)));
  CHECK_EQ("[1, 4, 4]", VectorToSetStr(g.Neighbors(3)));
  CHECK_EQ("[]", VectorToSetStr(g.Neighbors(4)));

  cout << "SUCCESS!\n";
}
