#pragma once
#include <string>
#include <vector>

class Parser {
    public:
        Parser();
        void parseData();
    private:
        //data structure: adjacency list
        std::vector<std::pair<int, int>> data_;

};