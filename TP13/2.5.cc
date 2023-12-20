#include <utility>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include "2.5.h"



DirectedGraph::DirectedGraph() : maxvertex(0){}

void DirectedGraph::AddArc(int from, int to, double length){
    vertices[from].push_back(std::make_pair(to, length));
    maxvertex = std::max(maxvertex, std::max(from, to));
}

int DirectedGraph::NumNodes() const {
    if (maxvertex == 0) {
        return 0;
    } else {
        return maxvertex + 1;
    }
}

int DirectedGraph::OutDegree(int node) const {
    auto it = vertices.find(node);
    if (it != vertices.end()) {
        return it->second.size();
    }
    return 0;
}

const std::vector<std::pair<int, double>>& DirectedGraph::Neighbors(int node) const {
    static const std::vector<std::pair<int, double>> empty;
    auto it = vertices.find(node);
    if (it != vertices.end()) {
        return it->second;
    }
    return empty;
}


std::vector<int> BFS(const DirectedGraph& graph, int src) {
    int N = graph.NumNodes();
    std::vector<int> parent(N, -1);
    std::queue<int> Q;
    std::unordered_set<int> explored;

    Q.push(src);
    parent[src] = src; // Le parent du noeud source est lui-même.

    while (!Q.empty()) {
        int current = Q.front();
        Q.pop();

        if (explored.find(current) != explored.end()) {
            continue;
        }

        explored.insert(current);

        const std::vector<std::pair<int, double>>& neighbors = graph.Neighbors(current);
        for (const auto& neighbor : neighbors) {
            int neighborNode = neighbor.first;
            if (explored.find(neighborNode) == explored.end() && parent[neighborNode] == -1) {
                parent[neighborNode] = current;
                Q.push(neighborNode);
            }
        }
    }

    return parent;
}