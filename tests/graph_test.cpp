#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

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

TEST_CASE("Constructor parses the data correctly from a given vector of edge pairs") {
    // TODO: dvalen25
    std::vector<std::pair<int, int>> data = getPairs("tests/graphs/line_graph.txt");
    Graph g(data);

    std::unordered_map<int, std::list<int>> map = g.getAdjacencyDict();

    for (int i = 0; i <= 4; i++) {
        REQUIRE(map.find(i) != map.end());
        if (i <  4) {
            REQUIRE(map[i].front() == i + 1);
        }
    }

}

TEST_CASE("insertVertex already in graph") {
    // TODO: dvalen25
    Graph g(data);

    CHECK(map.find(1) != map.end());

    g.insertVertex(1);

    REQUIRE(map.find(1) != map.end());
    REQUIRE(map[1].front() == 2);
}

TEST_CASE("insertVertex empty graph") {
    // TODO: dvalen25
    Graph g;
    g.insertVertex(1);
    std::unordered_map<int, std::list<int>> map = g.getAdjacencyDict();

    REQUIRE(map.find(1) != map.end());
    REQUIRE(map[1].empty() == true);
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