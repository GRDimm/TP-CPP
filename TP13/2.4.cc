#include <vector>
#include <algorithm>
#include "2.4.h"

std::vector<int> GetShortestPathFromRootedTree(const std::vector<int>& parent, int target) {
    std::vector<int> path;
    int current = target;

    // Si le noeud cible n'a pas été atteint (parent est -1), renvoyer un chemin vide.
    if (parent[current] == -1) {
        return path;
    }

    // Construire le chemin en remontant de la cible vers la source.
    while (current != parent[current]) {
        path.push_back(current);
        current = parent[current];
    }
    path.push_back(current); // Ajouter la source à la fin du chemin.

    // Inverser le chemin pour qu'il commence par la source.
    std::reverse(path.begin(), path.end());

    return path;
}
