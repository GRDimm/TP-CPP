#include <vector>
#include <queue>
#include <unordered_set>
#include "2.2.h"

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

        const std::vector<int>& neighbors = graph.Neighbors(current);
        for (int neighbor : neighbors) {
            if (explored.find(neighbor) == explored.end() && parent[neighbor] == -1) {
                parent[neighbor] = current;
                Q.push(neighbor);
            }
        }
    }

    return parent;
}
