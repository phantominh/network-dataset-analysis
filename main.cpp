#include <iostream>
#include "traversals.h"
#include <vector>
#include "parser.h"
#include "graph.h"
#include "pagerank.h"

int main() {
    std::cout<<"start parsing..."<<std::endl;
    Parser parseObj = Parser();
    //parseObj.parseData("data/pagerank_small.txt");

    parseObj.parseData("web-Google.txt");

    std::cout<<"building graph..."<<std::endl;
    Graph myGraph = Graph(parseObj.data_);

    // //neighbours of node 1
    // std::unordered_map<int, std::list<int>> myAdjList = myGraph.getOutgoingAdjacencyDict();
    // std::list<int> neighbours = myAdjList[1];

    // for (auto& i : neighbours) {
    //     std::cout<<"neighbour of 1: "<< i <<std::endl;
    // }

    // //traversal
    // //finding if a path exists
    // std::cout<<"doing traversals..."<<std::endl;
    // Traversal obj = Traversal(myAdjList);
    // int source = 1;
    // int destination = 27;
    // (obj.dfs(source,destination) == 1) ? std::cout<<"there is a path from "<<source<<" to "<<destination<<std::endl : std::cout<<"there is no path from "<<source<<" to "<<destination<<std::endl;

    // //getting the path
    // source = 1;
    // destination = 27;
    // std::vector<int> path = obj.pathToNode(source, destination);
    // for(auto& i : path) {
    //     std::cout<<"path "<<": "<<i<<std::endl;
    // }

    std::cout << "Page Ranking" << std::endl;
    PageRank p = PageRank(myGraph, 0.85, 2);
    p.rank();
    
    // for (auto i : p.get_rank()) {
    //     std::cout << "Node: " << i.first << ": " << i.second << std::endl;
    // }

    return 0;
}