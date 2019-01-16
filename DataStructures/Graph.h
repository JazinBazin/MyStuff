#pragma once
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <cstdint>

class Graph {
public:
    Graph();
    void addEdge(int64_t u, int64_t v);
    void DFS(int64_t u);
    void BFS(uint64_t u);

private:
    void DFS(uint64_t u, std::vector<bool>& visited);
    void BFS(uint64_t u, std::vector<bool>& visited);

private:
    std::unordered_map<int64_t, std::list<int64_t>> adjacencyLists;
};

