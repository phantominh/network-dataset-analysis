#include <string>
using namespace std;
#include "parser.h"
#include <iostream>
#include <fstream>

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::pair;

Parser::Parser() {}

void Parser::parseData(string fileName) {
    std::ifstream file (fileName);

    int node1;
    int node2;
    
    while(file >> node1 >> node2) {   
        data_.emplace_back(node1, node2);
    }
    
    //print first 5 pairs

    // int i = 0;
    // for (int i = 0; i < 5; i++)
    // {
    //     std::cout << data[i].first << " " << data[i].second << std::endl;
    // }
}
