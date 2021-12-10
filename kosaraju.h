#pragma once

#include "graph.h"
#include <vector>
#include <set>
#include <stack>
#include <list>
#include <unordered_map>

class Kosaraju {
    public: 
        //returns the strongly connected components of a graph
        static std::vector<std::set<int>> getSCC(Graph graph);

    private:
        static void buildStackDFS(int node, std::set<int>& visited, std::stack<int>& st, Graph graph);
        static void buildStackDFS2(int node, std::set<int>& visited, std::set<int>& scc, Graph graph);

};