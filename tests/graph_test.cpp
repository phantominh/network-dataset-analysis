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

TEST_CASE("Constructor parses the data correctly from a given vector of edge pairs") {

    std::vector<std::pair<int, int>> data = getPairs("tests/graphs/line_graph.txt");
    Graph g(data);

    std::unordered_map<int, std::list<int>> check;
    check[0] = std::list<int>({1});
    check[1] = std::list<int>({2});
    check[2] = std::list<int>({3});
    check[3] = std::list<int>({4});
    check[4] = std::list<int>();
    REQUIRE(check == g.getOutgoingAdjacencyDict());

    std::unordered_map<int, std::list<int>> check1;
    check1[0] = std::list<int>();
    check1[1] = std::list<int>({0});
    check1[2] = std::list<int>({1});
    check1[3] = std::list<int>({2});
    check1[4] = std::list<int>({3});

    REQUIRE(check1 == g.getIncomingAdjacencyDict());
}

TEST_CASE("insertVertex already in graph") {
    std::vector<std::pair<int, int>> data = getPairs("tests/graphs/line_graph.txt");
    Graph g(data);
    std::unordered_map<int, std::list<int>> map = g.getOutgoingAdjacencyDict();

    CHECK(map.find(1) != map.end());

    g.insertVertex(1);

    REQUIRE(map.find(1) != map.end());

    REQUIRE(map[1] == std::list<int>({2}));
}

TEST_CASE("insertVertex empty graph") {
    Graph g;
    g.insertVertex(0);
    std::unordered_map<int, std::list<int>> map = g.getOutgoingAdjacencyDict();

    REQUIRE(map.size() == 1);

    std::unordered_map<int, std::list<int>> check;
    check[0] = std::list<int>();

    REQUIRE(check == map);
}

TEST_CASE("adjacentVertexes works correctly") {
    std::vector<std::pair<int, int>> data = getPairs("tests/graphs/line_graph.txt");
    Graph g(data);

    REQUIRE(std::list<int>({1}) == g.outgoingAdjacentVertexes(0));
    REQUIRE(std::list<int>({2}) == g.outgoingAdjacentVertexes(1));
    REQUIRE(std::list<int>({3}) == g.outgoingAdjacentVertexes(2));
    REQUIRE(std::list<int>({4}) == g.outgoingAdjacentVertexes(3));
    REQUIRE(std::list<int>() == g.outgoingAdjacentVertexes(4));

    // Incoming
    REQUIRE(std::list<int>() == g.incomingAdjacentVertexes(0));
    REQUIRE(std::list<int>({0}) == g.incomingAdjacentVertexes(1));
    REQUIRE(std::list<int>({1}) == g.incomingAdjacentVertexes(2));
    REQUIRE(std::list<int>({2}) == g.incomingAdjacentVertexes(3));
    REQUIRE(std::list<int>({3}) == g.incomingAdjacentVertexes(4));
}

TEST_CASE("areAdjacent on 2 adjacent vertexes") {
    std::vector<std::pair<int, int>> data = getPairs("tests/graphs/line_graph.txt");
    Graph g(data);

    REQUIRE(g.areAdjacent(0, 1));
    REQUIRE(!g.areAdjacent(1, 0));
}

TEST_CASE("areAdjacent on 2 adjacent vertexes from and to") {
    std::vector<std::pair<int, int>> data = getPairs("tests/graphs/doubly_connected_line_graph.txt");
    Graph g(data);

    REQUIRE(g.areAdjacent(0, 1));
    REQUIRE(g.areAdjacent(1, 0));
    REQUIRE(g.areAdjacent(1, 2));
    REQUIRE(g.areAdjacent(2, 1));
}

TEST_CASE("areAdjacent on 1 vertex exist other doesn't") {
    std::vector<std::pair<int, int>> data = getPairs("tests/graphs/line_graph.txt");
    Graph g(data);

    REQUIRE(g.areAdjacent(3, 4));
    REQUIRE(!g.areAdjacent(4, 5));
}

TEST_CASE("areAdjacent on 2 NOT adjacent vertexes") {
    std::vector<std::pair<int, int>> data = getPairs("tests/graphs/line_graph.txt");
    Graph g(data);

    REQUIRE(!g.areAdjacent(3, 0));
}

TEST_CASE("insertEdge works correctly") {
    Graph g;
    g.insertEdge(1,2);

    REQUIRE(g.areAdjacent(1, 2));

    // Updates maps

    std::unordered_map<int, std::list<int>> checkOut;
    checkOut[1] = std::list<int>({2});
    checkOut[2] = std::list<int>();

    REQUIRE(checkOut == g.getOutgoingAdjacencyDict());

    std::unordered_map<int, std::list<int>> checkIn;
    checkIn[1] = std::list<int>();
    checkIn[2] = std::list<int>({1});

    REQUIRE(checkIn == g.getIncomingAdjacencyDict());
}

// TODO: Additional edge cases that you can think of ...