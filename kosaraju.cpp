#include "kosaraju.h"

Kosaraju::Kosaraju(Graph graph) {
    graph_ = graph;
    incomingList_ = graph_.getIncomingAdjacencyDict();
    outgoingList_ = graph_.getOutgoingAdjacencyDict();
}

std::vector<std::set<int>> Kosaraju::getSCC() {
    std::stack<int> st;
    std::unordered_map<int, bool> visited;

    std::cout<<"Traversal0" <<std::endl;
    //first pass: go through each node and build a stack with decreasing finish times of dfs (last edge is at the top)
    for (auto& kV : outgoingList_) {
        if (visited[kV.first]) {
            continue;
        }
        buildStackDFS(kV.first, visited, st);
    }

    std::cout<<"stack size: "<<st.size()<<std::endl;

    //clear the visited unordered_map as we have finished our first pass throught the graph
    visited.clear();

    std::vector<std::set<int>> sccVec;
    //second pass: use the stack we have built to find the strongly connected components
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if (visited[node]) {
            continue;
        }
        std::set<int> scc;
        buildStackDFS2(node, visited, scc);
        std::cout<<"scc size: "<<scc.size()<<std::endl;
        sccVec.push_back(scc);
    }

    return sccVec;
}

void Kosaraju::buildStackDFS(int node, std::unordered_map<int, bool>& visited, std::stack<int>& st) {
    visited[node] = true;
    std::cout<<"Traversal1" <<std::endl;
    std::list<int> neighbors = outgoingList_[node];
    std::cout<<"Traversal2" <<std::endl;
    for (auto& vertex : neighbors) {
        if (visited[vertex]) {
            continue;
        }
        buildStackDFS(vertex, visited, st);
    }
    std::cout<<"Traversal3" <<std::endl;
    st.push(node);
}

void Kosaraju::buildStackDFS2(int node, std::unordered_map<int, bool>& visited, std::set<int>& scc) {
    visited[node] = true;
    // std::cout<<"Traversal Completion: "<<visited.size()/875713<<"%"<<std::endl;
    scc.insert(node);
    std::list<int> neighbors = incomingList_[node];
    for (auto& vertex : neighbors) {
        if (visited[vertex]) {
            continue;
        }
        buildStackDFS2(vertex, visited, scc);
    }
}