#include "Graph.h"
#include <iostream>
#include <queue>
#include <limits>
#include <algorithm>

Graph::Graph() :
    adjacencyLists(std::unordered_map<uint64_t, std::vector<AdjacentVertex>>()) {};

void Graph::addEdge(uint64_t u, uint64_t v, int64_t d) {
    adjacencyLists[u].push_back({v, d});
    if(adjacencyLists.find(v) == adjacencyLists.end())
        adjacencyLists[v];
}

void Graph::addUnorderedEdge(uint64_t u, uint64_t v, int64_t d) {
    adjacencyLists[u].push_back({v, d});
    adjacencyLists[v].push_back({u, d});
}

void Graph::BFS(uint64_t u) {
    if(adjacencyLists.find(u) != adjacencyLists.end()) {
        std::vector<bool> visited(adjacencyLists.size());;
        BFS(u, visited);
    }
}

void Graph::BFS(uint64_t u, std::vector<bool>& visited) {
    std::queue<uint64_t> q;
    q.push(u);
    while(!q.empty()) {
        uint64_t u = q.front();
        q.pop();
        std::cout << u << "\n";
        visited[u] = true;
        for(const AdjacentVertex& adjacent : adjacencyLists[u])
            if(!visited[adjacent.vertex])
                q.push(adjacent.vertex);
    }
}

void Graph::DFS(int64_t u) {
    if(adjacencyLists.find(u) != adjacencyLists.end()) {
        std::vector<bool> visited(adjacencyLists.size());;
        DFS(u, visited);
    }
}

void Graph::DFS(uint64_t u, std::vector<bool>& visited) {
    visited[u] = true;
    std::cout << u << "\n";
    for(const AdjacentVertex& adjacent: adjacencyLists[u])
        if(!visited[adjacent.vertex])
            DFS(adjacent.vertex, visited);
}


// the graph should contain adjacency lists for all vertices in the graph. (including empty adjacency lists)
void Graph::DijkstraAlgorithm(uint64_t startVertex, std::vector<uint64_t> &distance, std::vector<uint64_t> &parent)
{
    uint64_t infinity = std::numeric_limits<uint64_t>::max();
    std::vector<bool> visited(adjacencyLists.size(), false);
    distance = std::vector<uint64_t>(adjacencyLists.size(), infinity);
    parent = std::vector<uint64_t>(adjacencyLists.size(), infinity);
    distance[startVertex] = 0;
    for(uint64_t i = 0; i < adjacencyLists.size(); ++i) {
        uint64_t u, minDistance = infinity;
        for(size_t j = 0; j < distance.size(); ++j)
            if(!visited[j] && distance[j] < minDistance) {
                minDistance = distance[j];
                u = j;
            }
        if(minDistance == infinity)
            break;
        visited[u] = true;
        for(uint64_t adjacency = 0; adjacency < adjacencyLists.at(u).size(); ++adjacency) {
            uint64_t v = adjacencyLists.at(u)[adjacency].vertex;
            uint64_t d = adjacencyLists.at(u)[adjacency].distance;
            if(distance[u] + d < distance[v]) {
                distance[v] = distance[u] + d;
                parent[v] = u;
            }
        }
    }
}

std::vector<uint64_t> Graph::restoreTheWay(uint64_t u, uint64_t v, const std::vector<uint64_t> &parent)
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
