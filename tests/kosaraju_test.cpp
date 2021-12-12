#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../kosaraju.h"
#include "../parser.h"
#include "../graph.h"
#include <iostream>

// TODO: Delete this after you complete at least 1 test case, else Makefile linker will break
TEST_CASE("No strongly connected components") {
    Parser parseObj = Parser();
    parseObj.parseData("data/kosarajuSimple/df0.txt");
    Graph myGraph = Graph(parseObj.data_);
    Kosaraju k = Kosaraju(myGraph);
    std::vector<std::set<int>> sccVec = k.getSCC();
    REQUIRE(sccVec.size() == 4);
}

TEST_CASE("Simple graph test 1") {
    Parser parseObj = Parser();
    parseObj.parseData("data/kosarajuSimple/df1.txt");
    Graph myGraph = Graph(parseObj.data_);
    std::cout<<"size of graph "<<myGraph.getIncomingAdjacencyDict().size()<<std::endl;
    Kosaraju k = Kosaraju(myGraph);
    std::vector<std::set<int>> sccVec = k.getSCC();
    std::vector<std::set<int>> expected = {std::set<int>{1,2,3}, std::set<int>{4,5,6}};
    REQUIRE(sccVec == expected);
}

TEST_CASE("Complex graph test 1") {
    Parser parseObj = Parser();
    parseObj.parseData("data/kosarajuComplex/df1.txt");
    Graph myGraph = Graph(parseObj.data_);
    Kosaraju k = Kosaraju(myGraph);
    std::vector<std::set<int>> sccVec = k.getSCC();
    std::vector<std::set<int>> expected = {std::set<int>{7}, std::set<int>{4,5,6}, std::set<int>{3}, std::set<int>{0,1,2}};
    REQUIRE(sccVec == expected);
}

TEST_CASE("Simple graph test 2") {
    Parser parseObj = Parser();
    parseObj.parseData("data/kosarajuSimple/df2.txt");
    Graph myGraph = Graph(parseObj.data_);
    Kosaraju k = Kosaraju(myGraph);
    std::vector<std::set<int>> sccVec = k.getSCC();
    std::vector<std::set<int>> expected = {std::set<int>{0,1,2}};
    REQUIRE(sccVec == expected);
}

TEST_CASE("Complex graph test 2") {
    Parser parseObj = Parser();
    parseObj.parseData("data/kosarajuComplex/df2.txt");
    Graph myGraph = Graph(parseObj.data_);
    Kosaraju k = Kosaraju(myGraph);
    std::vector<std::set<int>> sccVec = k.getSCC();
    std::vector<std::set<int>> expected = {std::set<int>{3},std::set<int>{1},std::set<int>{2},std::set<int>{0}};
    REQUIRE(sccVec == expected);
}

TEST_CASE("Simple graph test 3") {
    Parser parseObj = Parser();
    parseObj.parseData("data/kosarajuSimple/df3.txt");
    Graph myGraph = Graph(parseObj.data_);
    Kosaraju k = Kosaraju(myGraph);
    std::vector<std::set<int>> sccVec = k.getSCC();
    std::vector<std::set<int>> expected = {std::set<int>{1,2,3,4,5}};
    REQUIRE(sccVec == expected);
}

TEST_CASE("Complex graph test 3") {
    Parser parseObj = Parser();
    parseObj.parseData("data/kosarajuComplex/df3.txt");
    Graph myGraph = Graph(parseObj.data_);
    Kosaraju k = Kosaraju(myGraph);
    std::vector<std::set<int>> sccVec = k.getSCC();
    std::vector<std::set<int>> expected = {std::set<int>{1}, std::set<int>{5,2,3,4}};
    REQUIRE(sccVec == expected);
}

TEST_CASE("Simple graph test 4") {
    Parser parseObj = Parser();
    parseObj.parseData("data/kosarajuSimple/df4.txt");
    Graph myGraph = Graph(parseObj.data_);
    Kosaraju k = Kosaraju(myGraph);
    std::vector<std::set<int>> sccVec = k.getSCC();
    std::vector<std::set<int>> expected = {std::set<int>{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}};
    REQUIRE(sccVec == expected);
}

TEST_CASE("Complex graph test 4") {
    Parser parseObj = Parser();
    parseObj.parseData("data/kosarajuComplex/df4.txt");
    Graph myGraph = Graph(parseObj.data_);
    Kosaraju k = Kosaraju(myGraph);
    std::vector<std::set<int>> sccVec = k.getSCC();
    std::vector<std::set<int>> expected = {std::set<int>{0}, std::set<int>{1}, std::set<int>{2}, std::set<int>{3}, std::set<int>{4,5,6}};
    REQUIRE(sccVec == expected);
}

TEST_CASE("Simple graph test 5") {
    Parser parseObj = Parser();
    parseObj.parseData("data/kosarajuSimple/df5.txt");
    Graph myGraph = Graph(parseObj.data_);
    Kosaraju k = Kosaraju(myGraph);
    std::vector<std::set<int>> sccVec = k.getSCC();
    std::vector<std::set<int>> expected = {std::set<int>{1,2}};
    REQUIRE(sccVec == expected);
}

TEST_CASE("Complex graph test 5 (disconnected graph)") {
    Parser parseObj = Parser();
    parseObj.parseData("data/kosarajuComplex/df5.txt");
    Graph myGraph = Graph(parseObj.data_);
    Kosaraju k = Kosaraju(myGraph);
    std::vector<std::set<int>> sccVec = k.getSCC();
    std::vector<std::set<int>> expected = {std::set<int>{2,-1,0}, std::set<int>{-99, -87, 98}};
    REQUIRE(sccVec == expected);
}

TEST_CASE("Big Graph") {
    Parser parseObj = Parser();
    parseObj.parseData("data/kosarajuBig.txt");
    Graph myGraph = Graph(parseObj.data_);
    Kosaraju k = Kosaraju(myGraph);
    std::vector<std::set<int>> sccVec = k.getSCC();
    std::vector<std::set<int>> expected = {std::set<int>{31}, std::set<int>{23,25,26,27,28,29,30},std::set<int>{11,12,13,14,16},std::set<int>{15,17,18,19,20,21,22,24},std::set<int>{1,2,3,4,5,6,7,8,9,10}};
    REQUIRE(sccVec == expected);
}