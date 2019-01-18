#include <iostream>
#include "Graphs/DijkstraAlgorithm.h"

std::unordered_map<uint64_t, std::vector<std::pair<uint64_t, uint64_t>>> graph;

void addEdge(uint64_t u, uint64_t v, int64_t d) {
    graph[u].push_back({v, d});
    if(graph.find(v) == graph.end())
        graph[v];
}

int main() {
    addEdge(0, 1, 4);
    addEdge(0, 7, 8);
    addEdge(1, 0, 4);
    addEdge(1, 2, 8);
    addEdge(1, 7, 11);
    addEdge(2, 1, 8);
    addEdge(2, 3, 7);
    addEdge(2, 5, 4);
    addEdge(2, 8, 2);
    addEdge(3, 2, 7);
    addEdge(3, 4, 9);
    addEdge(3, 5, 14);
    addEdge(4, 3, 9);
    addEdge(4, 5, 10);
    addEdge(5, 2, 4);
    addEdge(5, 3, 14);
    addEdge(5, 4, 10);
    addEdge(5, 6, 2);
    addEdge(6, 5, 2);
    addEdge(6, 7, 1);
    addEdge(6, 8, 6);
    addEdge(7, 0, 8);
    addEdge(7, 1, 11);
    addEdge(7, 6, 1);
    addEdge(7, 8, 7);

    std::vector<uint64_t> distance;
    std::vector<uint64_t> parent;
    DijkstraAlgorithm(graph, 0, distance, parent);
    std::vector<uint64_t> way = restoreTheWay(0, 4, parent);
    for(auto d : distance)
        std::cout << d << " ";
    std::cout << "\n";
    for(auto v : way)
        std::cout << v << " ";
    std::cout << "\n";
    return 0;
}
