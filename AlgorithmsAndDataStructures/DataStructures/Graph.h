#pragma once
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <cstdint>

class Graph {
public:
    Graph();
    void addEdge(uint64_t u, uint64_t v, int64_t d);
    void addUnorderedEdge(uint64_t u, uint64_t v, int64_t d);
    void DFS(int64_t u);
    void BFS(uint64_t u);
    void DijkstraAlgorithm(uint64_t startVertex, std::vector<uint64_t> &distance, std::vector<uint64_t> &parent);
    static std::vector<uint64_t> restoreTheWay(uint64_t u, uint64_t v, const std::vector<uint64_t> &parent);

private:
    void DFS(uint64_t u, std::vector<bool>& visited);
    void BFS(uint64_t u, std::vector<bool>& visited);

    struct AdjacentVertex {
        uint64_t vertex;
        int64_t distance;
    };

private:
    std::unordered_map<uint64_t, std::vector<AdjacentVertex>> adjacencyLists;
};

