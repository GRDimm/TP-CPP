#include <vector>
#include <unordered_map>
#include "2.3.h"

std::vector<int> GetBfsDistances(const std::vector<int>& parent) {
    std::vector<int> distances(parent.size(), -1);

    // Trouver la racine et initialiser sa distance à 0.
    for (int i = 0; i < parent.size(); ++i) {
        if (parent[i] == static_cast<int>(i)) {
            distances[i] = 0;
            break;
        }
    }

    // Calculer les distances pour chaque noeud.
    for (int i = 0; i < parent.size(); ++i) {
        if (parent[i] != -1 && distances[i] == -1) {
            int distance = 0;
            int current = i;
            while (parent[current] != current) {
                current = parent[current];
                distance++;
            }
            distances[i] = distance;
        }
    }

    return distances;
}
