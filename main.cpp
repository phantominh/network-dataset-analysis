#include <iostream>
#include "traversals.h"
#include <vector>
#include "parser.h"
#include "graph.h"

int main() {
    std::cout<<"start parsing..."<<std::endl;
    Parser parseObj = Parser();
    parseObj.parseData("web-Google.txt");

    std::cout<<"building graph..."<<std::endl;
    Graph myGraph = Graph(parseObj.data_);

    //neighbours of node 1
    std::map<int, std::list<int>> myAdjList = myGraph.getAdjacencyDict();
    std::list<int> neighbours = myAdjList[1];

    for (auto& i : neighbours) {
        std::cout<<"neighbour of 1: "<< i <<std::endl;
    }

    //traversal
    //finding if a path exists
    std::cout<<"doing traversals..."<<std::endl;
    Traversal obj = Traversal(myAdjList);
    int source = 0;
    int destination = 136593;
    (obj.dfs(source,destination) == 1) ? std::cout<<"there is a path from "<<source<<" to "<<destination<<std::endl : std::cout<<"there is no path from "<<source<<" to "<<destination<<std::endl;

    //getting the path
    source = 0;
    destination = 136593;
    std::vector<int> path = obj.pathToNode(source, destination);
    for(auto& i : path) {
        std::cout<<"path "<<": "<<i<<std::endl;
    }


    return 0;
}