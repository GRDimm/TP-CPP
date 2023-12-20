#include "2.5.h"
#include "2.6.h"
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
  // Graph like the example in 2.1.h
  DirectedGraph g;
  g.AddArc(5, 3, 1.2);
  g.AddArc(1, 4, 2.0);
  g.AddArc(4, 0, 1.2);
  g.AddArc(0, 3, 0.1);
  g.AddArc(6, 6, 0.0);
  g.AddArc(3, 6, 7.4);
  g.AddArc(0, 4, 0.1);
  g.AddArc(4, 5, 3.5);
  g.AddArc(0, 5, 7.4);
  g.AddArc(5, 1, 1.0);
  g.AddArc(6, 5, 0.7);
  g.AddArc(6, 0, 0.0);
  g.AddArc(3, 6, 0.4);
  CHECK_EQ(7, g.NumNodes());

  CHECK_EQ("0, 5, -1, 0, 0, 6, 3", StrJoin(Dijkstra(g, 0), ", "));
  CHECK_EQ("4, 1, -1, 0, 1, 6, 3", StrJoin(Dijkstra(g, 1), ", "));
  CHECK_EQ("-1, -1, 2, -1, -1, -1, -1", StrJoin(Dijkstra(g, 2), ", "));
  CHECK_EQ("6, 5, -1, 3, 0, 6, 3", StrJoin(Dijkstra(g, 3), ", "));
  CHECK_EQ("4, 5, -1, 0, 4, 6, 3", StrJoin(Dijkstra(g, 4), ", "));
  CHECK_EQ("6, 5, -1, 5, 0, 5, 3", StrJoin(Dijkstra(g, 5), ", "));
  CHECK_EQ("6, 5, -1, 0, 0, 6, 6", StrJoin(Dijkstra(g, 6), ", "));

  cout << "SUCCESS!\n";
}
