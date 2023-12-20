#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>
#include "2.6.h"

struct NodeDistance {
    int node;
    double distance;

    NodeDistance(int n, double d) : node(n), distance(d) {}

    bool operator>(const NodeDistance& other) const {
        return distance > other.distance;
    }
};

std::vector<int> Dijkstra(const DirectedGraph& graph, int src) {
    int N = graph.NumNodes();
    std::vector<int> parent(N, -1);
    std::vector<double> dist(N, std::numeric_limits<double>::max());
    std::priority_queue<NodeDistance, std::vector<NodeDistance>, std::greater<NodeDistance>> pq;

    dist[src] = 0.0;
    parent[src] = src; // Le parent du noeud source est lui-même.
    pq.push(NodeDistance(src, 0.0));

    while (!pq.empty()) {
        NodeDistance current = pq.top();
        pq.pop();

        if (dist[current.node] < current.distance) {
            continue; // Déjà visité avec une distance plus courte.
        }

        const auto& neighbors = graph.Neighbors(current.node);
        for (const auto& neighbor : neighbors) {
            int neighborNode = neighbor.first;
            double weight = neighbor.second;
            double newDist = dist[current.node] + weight;

            if (newDist < dist[neighborNode]) {
                dist[neighborNode] = newDist;
                parent[neighborNode] = current.node;
                pq.push(NodeDistance(neighborNode, newDist));
            }
        }
    }

    return parent;
}
