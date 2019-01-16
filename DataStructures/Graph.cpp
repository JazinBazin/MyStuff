#include "Graph.h"
#include <queue>

Graph::Graph() :
    adjacencyLists(std::unordered_map<int64_t, std::list<int64_t>>()) {};

void Graph::addEdge(int64_t u, int64_t v) {
    adjacencyLists[u].push_back(v);
}

void Graph::DFS(int64_t u) {
    if(adjacencyLists.find(u) != adjacencyLists.end()) {
        std::vector<bool> visited(adjacencyLists.size());;
        DFS(u, visited);
    }
}

void Graph::BFS(uint64_t u) {
    if(adjacencyLists.find(u) != adjacencyLists.end()) {
        std::vector<bool> visited(adjacencyLists.size());;
        BFS(u, visited);
    }
}

void Graph::DFS(uint64_t u, std::vector<bool>& visited) {
    visited[u] = true;
    std::cout << u << "\n";
    for(uint64_t v : adjacencyLists[u])
        if(!visited[v])
            DFS(v, visited);
}

void Graph::BFS(uint64_t u, std::vector<bool>& visited) {
    std::queue<uint64_t> q;
    q.push(u);
    while(!q.empty()) {
        uint64_t u = q.front();
        q.pop();
        std::cout << u << "\n";
        visited[u] = true;
        for(uint64_t v : adjacencyLists[u])
            if(!visited[v])
                q.push(v);
    }
}
