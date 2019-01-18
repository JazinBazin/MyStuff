#include <iostream>
#include "DataStructures/Graph.h"

int main() {
    Graph g;
    g.addUnorderedEdge(1, 0, 0);
    g.addUnorderedEdge(2, 3, 0);
    g.addUnorderedEdge(3, 4, 0);
    for(auto components : g.connectedComponents()) {
        for(auto v : components)
            std::cout << v << " ";
        std::cout << "\n";
    }
    return 0;
}
