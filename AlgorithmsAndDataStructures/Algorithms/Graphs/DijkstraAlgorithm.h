#pragma once
#include <cstdint>
#include <limits>
#include <unordered_map>
#include <vector>
#include <algorithm>

// the graph should contain adjacency lists for all vertices in the graph. (including empty adjacency lists)
void DijkstraAlgorithm(const std::unordered_map<uint64_t, std::vector<std::pair<uint64_t, uint64_t>>> &graph,
                       uint64_t startVertex, std::vector<uint64_t> &distance, std::vector<uint64_t> &parent)
{
    uint64_t infinity = std::numeric_limits<uint64_t>::max();
    std::vector<bool> visited(graph.size(), false);
    distance = std::vector<uint64_t>(graph.size(), infinity);
    parent = std::vector<uint64_t>(graph.size(), infinity);
    distance[startVertex] = 0;
    for(uint64_t i = 0; i < graph.size(); ++i) {
        uint64_t u, minDistance = infinity;
        for(size_t j = 0; j < distance.size(); ++j)
            if(!visited[j] && distance[j] < minDistance) {
                minDistance = distance[j];
                u = j;
            }
        if(minDistance == infinity)
            break;
        visited[u] = true;
        for(uint64_t j = 0; j < graph.at(u).size(); ++j) {
            uint64_t v = graph.at(u)[j].first;
            uint64_t d = graph.at(u)[j].second;
            if(distance[u] + d < distance[v]) {
                distance[v] = distance[u] + d;
                parent[v] = u;
            }
        }
    }
}

std::vector<uint64_t> restoreTheWay(uint64_t u, uint64_t v, const std::vector<uint64_t> &parent)
{
    uint64_t infinity = std::numeric_limits<uint64_t>::max();
    std::vector<uint64_t> way;
    uint64_t i;
    for(i = v; i != infinity && i != u; i = parent[i])
        way.push_back(i);
    if(i == infinity)
        return std::vector<uint64_t>();
    way.push_back(u);
    std::reverse(way.begin(), way.end());
    return way;
}
