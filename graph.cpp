#include "graph.h"

Graph::Graph() {
    /* Nothing to see here */
}

Graph::Graph(const Graph& other) {
    _adjacency_dict = other._adjacency_dict;
}

Graph::Graph(std::vector<std::pair<int, int>> data) {
    for (auto it : data) {
        int v1 = it.first;
        int v2 = it.second;
        // This will work even when v1 did not exist
        _adjacency_dict[v1].emplace_back(v2);
        if (_adjacency_dict.find(v2) == _adjacency_dict.end()) {
            _adjacency_dict[v2] = std::list<int>();
        }
    }
}

void Graph::insertVertex(int v) {
    if (_adjacency_dict.find(v) == _adjacency_dict.end()) {
        _adjacency_dict[v] = std::list<int>();
    }
}

std::list<int> Graph::adjacentVertexes(int v) {
    return _adjacency_dict[v];
}

bool Graph::areAdjacent(int v1, int v2) {
    if (_adjacency_dict[v1].size() < _adjacency_dict[v2].size()) {
        for (auto i : _adjacency_dict[v1]) {
            if (i == v2) {
                return true;
            }
        }
    } else {
        for (auto i : _adjacency_dict[v2]) {
            if (i == v1) {
                return true;
            }
        }
    }

    return false;
}

void Graph::insertEdge(int v1, int v2) {
    _adjacency_dict[v1].emplace_back(v2);
    if (_adjacency_dict.find(v2) == _adjacency_dict.end()) {
        _adjacency_dict[v2] = std::list<int>();
    }
}

std::unordered_map<int, std::list<int>> Graph::getAdjacencyDict() {
    return _adjacency_dict;
}