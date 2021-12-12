#include <iostream>
#include "traversals.h"
#include <vector>
#include "parser.h"
#include "graph.h"
#include "pagerank.h"
#include "kosaraju.h"
#include <chrono>
using namespace std::chrono;

int main() {
    std::cout<<"start parsing..."<<std::endl;
    auto start = high_resolution_clock::now();
    Parser parseObj = Parser();
    parseObj.parseData("web-Google.txt");
    // parseObj.parseData("web-Google.txt");
    std::cout<<"building graph..."<<std::endl;
    Graph myGraph = Graph(parseObj.data_);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    std::cout<<"Parsing took: " <<duration.count()/1000<<"."<<duration.count()%1000<<"s"<<std::endl;

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
    // std::cout<<"printing out the incoming adj list: "<<std::endl;
    // for (auto& kV : myGraph.getIncomingAdjacencyDict()) {
    //     std::cout<<"Node "<<kV.first<<" has the following neighbors: "<<std::endl;
    //     for (auto& node : kV.second) {
    //         std::cout<<node<<std::endl;
    //     }
    // }


    // std::cout<<"printing out the outgoing adj list: "<<std::endl;

    
    std::cout << "Performing Kosaraju's Algorithm" << std::endl;
    start = high_resolution_clock::now();
    Kosaraju k = Kosaraju(myGraph);
    std::vector<std::set<int>> sccVec = k.getSCC();
    // for (auto& scc : sccVec) {
    //     for (auto& node : scc) {
    //         std::cout<<node;
    //     }
    //     std::cout<<"\n";
    // }
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    std::cout<<"Kosaraju took: " <<duration.count()/1000<<"."<<duration.count()%1000<<"s"<<std::endl;

    std::cout << "Page Ranking" << std::endl;
    start = high_resolution_clock::now();
    PageRank p = PageRank(myGraph, 0.85, 2);
    p.rank();
    
    // for (auto i : p.get_rank()) {
    //     std::cout << "Node: " << i.first << ": " << i.second << std::endl;
    // }
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    std::cout<<"Page Rank took: " <<duration.count()/1000<<"."<<duration.count()%1000<<"s"<<std::endl;


    return 0;
}