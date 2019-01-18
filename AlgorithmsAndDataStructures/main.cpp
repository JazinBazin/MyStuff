#include <iostream>
#include "DataStructures/Graph.h"

int main() {
    Graph g;
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 0, 4);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 1, 8);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 5, 4);
    g.addEdge(2, 8, 2);
    g.addEdge(3, 2, 7);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 3, 9);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 2, 4);
    g.addEdge(5, 3, 14);
    g.addEdge(5, 4, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 5, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 0, 8);
    g.addEdge(7, 1, 11);
    g.addEdge(7, 6, 1);
    g.addEdge(7, 8, 7);

    std::vector<uint64_t> distance;
    std::vector<uint64_t> parent;
    g.DijkstraAlgorithm(0, distance, parent);
    std::vector<uint64_t> way = Graph::restoreTheWay(0, 4, parent);
    for(auto d : distance)
        std::cout << d << " ";
    std::cout << "\n";
    for(auto v : way)
        std::cout << v << " ";
    std::cout << "\n";
    return 0;
}
