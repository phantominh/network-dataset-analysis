#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <vector>
#include <string>
#include <unordered_map>

#include "../graph.h"
#include "../parser.h"

using std::string;

// TODO: Some data here for testing (vector of edge pairs)
std::vector<std::pair<int, int>> getPairs(string path) {
    Parser p;
    p.parseData(path);

    return p.data_;
}

// TODO: Delete this after you complete at least 1 test case, else Makefile linker will break
TEST_CASE("Foo") {
    REQUIRE(1==1);
}

TEST_CASE("Constructor parses the data correctly from a given vector of edge pairs") {
    // TODO: dvalen25
    std::vector<std::pair<int, int>> data = getPairs("../tests/graphs/line_graph.txt");
    Graph g(data);

    std::unordered_map<int, std::list<int>> map = g.getOutgoingAdjacencyDict();
    std::unordered_map<int, std::list<int>> check;
    check[0] = std::list<int>({1});
    check[1] = std::list<int>({2});
    check[2] = std::list<int>({3});
    check[3] = std::list<int>({4});
    REQUIRE(check == map);
    // for (int i = 0; i <= 4; i++) {
    //     REQUIRE(map.find(i) != map.end());
    //     if (i <  4) {
    //         REQUIRE(map[i].front() == i + 1);
    //     }
    // }

}

TEST_CASE("insertVertex already in graph") {
    // // TODO: dvalen25
    // std::vector<std::pair<int, int>> data = getPairs("tests/graphs/line_graph.txt");
    // Graph g(data);

    // CHECK(map.find(1) != map.end());

    // g.insertVertex(1);

    // // REQUIRE(map.find(1) != map.end());
    // // REQUIRE(map[1].front() == 2);
}

TEST_CASE("insertVertex empty graph") {
    // TODO: dvalen25
    // Graph g;
    // g.insertVertex(1);
    // std::unordered_map<int, std::list<int>> map = g.getAdjacencyDict();

    // // REQUIRE(map.find(1) != map.end());
    // // REQUIRE(map[1].empty() == true);
}

TEST_CASE("adjacentVertexes works correctly") {
    // TODO: dvalen25
}

TEST_CASE("areAdjacent on 2 adjacent vertexes") {
    // TODO: dvalen25
}

TEST_CASE("areAdjacent on 2 NOT adjacent vertexes") {
    // TODO: dvalen25
}

TEST_CASE("insertEdge works correctly") {
    // TODO: minhtp2
}

// TODO: Additional edge cases that you can think of ...