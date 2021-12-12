#include <iostream>
#include "traversals.h"
#include <vector>
#include "parser.h"
#include "graph.h"
#include "pagerank.h"
#include "kosaraju.h"
#include <chrono>

using namespace std::chrono;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cout << "Usage: ./main <kosaraju/pagerank> <input_file> <output_file>" << std::endl;
        return -1;
    }

    std::string algorithm(argv[1]);
    std::string input_file(argv[2]);
    std::string output_file(argv[3]);

    std::cout<<"Parsing data ..."<<std::endl;
    auto start = high_resolution_clock::now();
    Parser parseObj;
    // parseObj.parseData(input_file);
    parseObj.parseData("web-Google.txt");

    std::cout<<"Building graph..."<<std::endl;
    Graph myGraph = Graph(parseObj.data_);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    std::cout<<"Parsing took: " <<duration.count()/1000<<"."<<duration.count()%1000<<"s"<<std::endl;

    if (algorithm == "kosaraju") {
        std::cout << "Performing Kosaraju's Algorithm" << std::endl;
        start = high_resolution_clock::now();
        Kosaraju k = Kosaraju(myGraph);
        std::vector<std::set<int>> sccVec = k.getSCC();
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        std::cout<<"Kosaraju took: " <<duration.count()/1000<<"."<<duration.count()%1000<<"s"<<std::endl;
        std::cout<<"Writing SCC result to a file"<<std::endl;
        k.write_to_file(output_file);
    }

    else if (algorithm == "pagerank") {
        std::cout << "Page Ranking" << std::endl;
        start = high_resolution_clock::now();
        PageRank p = PageRank(myGraph, 0.85, 1);
        p.rank();
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        std::cout<<"Page Rank took: " <<duration.count()/1000<<"."<<duration.count()%1000<<"s"<<std::endl;
        std::cout<<"Writing Page Rank result to a file"<<std::endl;
        p.write_to_file(output_file);
    }

    else {
        std::cout << "FAILED" << std::endl;
    }

    return 0;
}