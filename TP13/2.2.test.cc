#include "2.1.h"
#include "2.2.h"
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
  // Graph like the example in 2.1.h
  DirectedGraph g;
  g.AddArc(1, 0);
  g.AddArc(1, 3);
  g.AddArc(3, 1);
  g.AddArc(2, 0);
  g.AddArc(1, 2);
  g.AddArc(3, 4);
  g.AddArc(3, 4);

  // From node "0", nothing is explored (except 0!): the BFS tree looks
  // like: 0
  CHECK_EQ("0, -1, -1, -1, -1", StrJoin(BFS(g, 0), ", "));

  // From node "1", the entire graph is accessible and explored: the BFS tree is
  // 1 ---> 0
  //   `--> 2
  //   `--> 3 --> 4  
  CHECK_EQ("1, 1, 1, 1, 3", StrJoin(BFS(g, 1), ", "));

  // From node "2", only "0" is reached.
  CHECK_EQ("2, -1, 2, -1, -1", StrJoin(BFS(g, 2), ", "));

  // From node "3"
  CHECK_EQ("1, 3, 1, 3, 3", StrJoin(BFS(g, 3), ", "));

  // From node "4"
  CHECK_EQ("-1, -1, -1, -1, 4", StrJoin(BFS(g, 4), ", "));

  // More complex example.
  g.AddArc(2, 5);
  g.AddArc(3, 5);
  g.AddArc(0, 5);
  g.AddArc(5, 7);
  g.AddArc(4, 5);
  g.AddArc(5, 7);
  g.AddArc(4, 7);
  g.AddArc(4, 4);
  g.AddArc(4, 4);
  g.AddArc(7, 6);
  g.AddArc(8, 1);
  CHECK_EQ("1, 0, 1, 1, 2, 2, 4, 3, -1",
           StrJoin(GetBfsDistances(BFS(g, 1)), ", "));

  cout << "SUCCESS!\n";
}
