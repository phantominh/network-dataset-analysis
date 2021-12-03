#pragma once
#include <string>
#include <vector>

class Parser {
    public:
        Parser();
        void parseData(std::string fileName);
        std::vector<std::pair<int, int> > data_;
    private:
        //data structure: adjacency list
        // std::vector<std::pair<int, int>> data_;

};