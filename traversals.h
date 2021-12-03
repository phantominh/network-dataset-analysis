#pragma once
#include <string>
#include <map>
#include <list>
#include <vector>
#include <unordered_map>
#include <iostream>

class Traversal {
    public:
        //default constructor
        Traversal();
        //constructor taking in an adjacency list
        Traversal(std::map<int, std::list<int> > graph);
        //dfs traversal to find if a node exists
        bool dfs(int curr, int node, std::unordered_map<int, bool> visited = std::unordered_map<int, bool>());
        //get path to node by using dfs traversal
        std::vector<int> pathToNode(int curr, int destination, std::unordered_map<int, bool> visited = std::unordered_map<int, bool>(), std::vector<int>& path = *(new std::vector<int>()));
        //testing
        std::string message();

    private:
        //data structure: adjacency list
        std::map<int, std::list<int> > graph_;
};