#pragma once
#include <string>
#include <unordered_map>
#include <vector>

class Traversal {
    public:
        //default constructor
        Traversal();
        //constructor taking in an adjacency list
        Traversal(std::unordered_map<int, std::vector<int> > graph);
        //dfs traversal to find if a node exists
        bool dfs(int curr, int node);
        //get path to node by using dfs traversal
        std::vector<int> pathToNode(int curr, int node);
        //testing
        std::string message();

    private:
        //data structure: adjacency list
        std::unordered_map<int, std::vector<int> > graph_;

};