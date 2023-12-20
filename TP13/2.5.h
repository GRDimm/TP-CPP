
#ifndef DirectedGraph_H5
#define DirectedGraph_H5

#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;
#include <utility>

// A directed graph is a set of nodes, linked by arcs. Arcs are directed: they
// go from a node to another node.
// In this implementation, each node is an integer in [0, num_nodes-1].
//
// For example, the following graph:
//
//  0 <--- 1 <--> 3 ---> 4
//  ^      |       \     ^
//  |      v        `----'
//  '----- 2
//
// Can be obtained by calling this on a fresh DirectedGraph:
//   AddArc(1, 0);
//   AddArc(1, 3);
//   AddArc(3, 1);
//   AddArc(2, 0);
//   AddArc(1, 2);
//   AddArc(3, 4);
//   AddArc(3, 4);
//


class DirectedGraph {
 public:
  DirectedGraph();
  void AddArc(int from, int to, double length);

  // Returns 1 + the highest node index that was ever given to AddArc(), as
  // 'from' or 'to' argument.
  int NumNodes() const;

  // Returns the number of arcs originating from "node".
  int OutDegree(int node) const;

  // Returns all the destination nodes that were added with arcs
  // originating from "node", along with the lengths of these arcs.
  const std::vector<std::pair<int, double>>& Neighbors(int node) const;

 private:
  std::unordered_map<int, std::vector<std::pair<int, double>>> vertices;
  int maxvertex;
};


#endif