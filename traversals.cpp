#include "traversals.h"

Traversal::Traversal(){};

Traversal::Traversal(std::unordered_map<int, std::vector<int> > graph) {
    graph_ = graph;
}

std::string Traversal::message() {
    return "Hello, World!";
}

bool Traversal::dfs(int curr, int node) {
    if (curr == node) {
        return true;
    }
    for (auto& neighbors : graph_[curr]) {
        if (dfs(neighbors, node)) {
            return true;
        }
    }
    return false;
}

std::vector<int> pathToNode(int curr, int node) {
    return {1,2,3};
}