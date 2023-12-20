#include "2.5.h"
#include "main_utils.h"
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

ostream& operator<<(ostream& o, const pair<int, double>& p) {
  return o << "(" << p.first << ", " << p.second << ")";
}

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

template<typename T>
string ToSetStr(const T& v) {
  T sorted = v;
  sort(sorted.begin(), sorted.end());
  return "[" + StrJoin(sorted, ", ") + "]"; 
}

int main() {
  DirectedGraph g;
  // Empty graph
  CHECK_EQ(0, g.NumNodes());

  // Build the example in 2.1.h
  g.AddArc(1, 0, 4.5);
  g.AddArc(1, 3, 3.2);
  g.AddArc(3, 1, 0.0);
  g.AddArc(2, 0, 0.1);
  g.AddArc(1, 2, 7.7);
  g.AddArc(3, 4, 8.8);
  g.AddArc(3, 4, 0.9);
  CHECK_EQ(5, g.NumNodes());
  CHECK_EQ(0, g.OutDegree(0));
  CHECK_EQ(3, g.OutDegree(1));
  CHECK_EQ(1, g.OutDegree(2));
  CHECK_EQ(3, g.OutDegree(3));
  CHECK_EQ(0, g.OutDegree(4));
  CHECK_EQ("[]", ToSetStr(g.Neighbors(0)));
  CHECK_EQ("[(0, 4.5), (2, 7.7), (3, 3.2)]", ToSetStr(g.Neighbors(1)));
  CHECK_EQ("[(0, 0.1)]", ToSetStr(g.Neighbors(2)));
  CHECK_EQ("[(1, 0), (4, 0.9), (4, 8.8)]", ToSetStr(g.Neighbors(3)));
  CHECK_EQ("[]", ToSetStr(g.Neighbors(4)));

  cout << "SUCCESS!\n";
}
