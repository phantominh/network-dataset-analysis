#include "kosaraju.h"

std::vector<std::set<int>> Kosaraju::getSCC(Graph graph) {
    std::stack<int> st;
    std::set<int> visited;

    //first pass: go through each node and build a stack with decreasing finish times of dfs (last edge is at the top)
    for (auto& kV : graph.getOutgoingAdjacencyDict()) {
        if (visited.find(kV.first) != visited.end()) {
            continue;
        }
        buildStackDFS(kV.first, visited, st, graph);
    }

    std::cout<<"stack size: "<<st.size()<<std::endl;

    //clear the visited set as we have finished our first pass throught the graph
    visited.clear();

    std::vector<std::set<int>> sccVec;
    //second pass: use the stack we have built to find the strongly connected components
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if (visited.find(node) != visited.end()) {
            continue;
        }
        std::set<int> scc;
        buildStackDFS2(node, visited, scc, graph);
        std::cout<<"scc size: "<<scc.size()<<std::endl;
        sccVec.push_back(scc);
    }

    return sccVec;
}

void Kosaraju::buildStackDFS(int node, std::set<int>& visited, std::stack<int>& st, Graph graph) {
    visited.insert(node);
    std::list<int> neighbors = graph.getOutgoingAdjacencyDict()[node];
    for (auto& vertex : neighbors) {
        if (visited.find(vertex) != visited.end()) {
            continue;
        }
        buildStackDFS(vertex, visited, st, graph);
    }
    st.push(node);
}

void Kosaraju::buildStackDFS2(int node, std::set<int>& visited, std::set<int>& scc, Graph graph) {
    visited.insert(node);
    scc.insert(node);
    std::list<int> neighbors = graph.getIncomingAdjacencyDict()[node];
    for (auto& vertex : neighbors) {
        if (visited.find(vertex) != visited.end()) {
            continue;
        }
        buildStackDFS2(vertex, visited, scc, graph);
    }
}