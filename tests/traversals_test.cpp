#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include <string>
#include <unordered_map>

#include "../traversals.h"

#include "../graph.h"
#include "../parser.h"

using std::string;
// TODO: Delete this after you complete at least 1 test case, else Makefile linker will break
TEST_CASE("Foo") {
    REQUIRE(1==1);
}

TEST_CASE("test linker make file", "[traversals]") {
    Traversal obj = Traversal();
    std::string test = obj.message();
    REQUIRE(test == "Hello, World!");
}

Traversal setUpTraversal(string path) {
    Parser p;
    p.parseData(path);

    Graph g(p.data_);

    return Traversal(g.getOutgoingAdjacencyDict());
}

TEST_CASE("dfs traversal to node in path") {
    Traversal t = setUpTraversal("tests/graphs/line_graph.txt");
    REQUIRE(t.dfs(1, 2) == true);
    REQUIRE(t.dfs(1, 4) == true);
}

TEST_CASE("dfs traversal to node not in path") {
    Traversal t = setUpTraversal("tests/graphs/line_graph.txt");
    REQUIRE(t.dfs(3, 2) == false);
    REQUIRE(t.dfs(4, 1) == false);
}

TEST_CASE("dfs traversal to node not in graph") {
    Traversal t = setUpTraversal("tests/graphs/line_graph.txt");
    REQUIRE(t.dfs(4, 5) == false);
    REQUIRE(t.dfs(0, 100) == false);
}

TEST_CASE("dfs traversal from and to node not in graph") {
    Traversal t = setUpTraversal("tests/graphs/line_graph.txt");
    REQUIRE(t.dfs(6, 5) == false);
    REQUIRE(t.dfs(50, 100) == false);
}

TEST_CASE("dfs traversal from and to the same node") {
    Traversal t = setUpTraversal("tests/graphs/line_graph.txt");
    REQUIRE(t.dfs(4, 4) == true);
    REQUIRE(t.dfs(0, 0) == true);
}

TEST_CASE("dfs traversal between two disconnected components") {
    Traversal t = setUpTraversal("tests/graphs/disconnected_graph.txt");
    REQUIRE(t.dfs(0, 1) == true);
    REQUIRE(t.dfs(0, 3) == false);
    REQUIRE(t.dfs(1, 2) == false);
}

TEST_CASE("dfs traversal in doubly connected graph") {
    Traversal t = setUpTraversal("tests/graphs/doubly_connected_line_graph.txt");
    REQUIRE(t.dfs(0, 1) == true);
    REQUIRE(t.dfs(1, 0) == true);
}

TEST_CASE("dfs traversal from node with multiple ends") {
    Traversal t = setUpTraversal("tests/graphs/hub_graph.txt");
    REQUIRE(t.dfs(0, 1) == true);
    REQUIRE(t.dfs(0, 2) == true);
    REQUIRE(t.dfs(0, 3) == true);
}

TEST_CASE("dfs traversal from one connected component to another") {
    Traversal t = setUpTraversal("tests/graphs/connected_component_graph.txt");
    REQUIRE(t.dfs(2, 5) == true);
}

// I realized these tests might be better after proving the bool function worked, this one should give us the path so we will do the same tests
TEST_CASE("dfs path to node in path") {
    Traversal t = setUpTraversal("tests/graphs/line_graph.txt");
    REQUIRE(t.pathToNode(1, 4) == std::vector<int>({1, 2, 3, 4}));
}

TEST_CASE("dfs path to node not in path") {
    Traversal t = setUpTraversal("tests/graphs/line_graph.txt");
    REQUIRE(t.pathToNode(3, 2) == std::vector<int>());
    REQUIRE(t.pathToNode(4, 1) == std::vector<int>());
}

TEST_CASE("dfs path to node not in graph") {
    Traversal t = setUpTraversal("tests/graphs/line_graph.txt");
    REQUIRE(t.pathToNode(4, 5) == std::vector<int>());
    REQUIRE(t.pathToNode(0, 100) == std::vector<int>());
}

TEST_CASE("dfs path from and to node not in graph") {
    Traversal t = setUpTraversal("tests/graphs/line_graph.txt");
    REQUIRE(t.pathToNode(6, 5) == std::vector<int>());
    REQUIRE(t.pathToNode(50, 100) == std::vector<int>());
}

TEST_CASE("dfs path from and to the same node") {
    Traversal t = setUpTraversal("tests/graphs/line_graph.txt");
    REQUIRE(t.pathToNode(4, 4) == std::vector<int>({4}));
    REQUIRE(t.pathToNode(0, 0) == std::vector<int>({0}));
}

TEST_CASE("dfs path between two disconnected components") {
    Traversal t = setUpTraversal("tests/graphs/disconnected_graph.txt");
    REQUIRE(t.pathToNode(0, 1) == std::vector<int>({0, 1}));
    REQUIRE(t.pathToNode(0, 3) == std::vector<int>());
    REQUIRE(t.pathToNode(1, 2) == std::vector<int>());
}

TEST_CASE("dfs path in doubly connected graph") {
    Traversal t = setUpTraversal("tests/graphs/doubly_connected_line_graph.txt");
    REQUIRE(t.pathToNode(0, 1) == std::vector<int>({0, 1}));
    REQUIRE(t.pathToNode(1, 0) == std::vector<int>({1, 2, 0}));
}

TEST_CASE("dfs path from node with multiple ends") {
    Traversal t = setUpTraversal("tests/graphs/hub_graph.txt");
    REQUIRE(t.pathToNode(0, 1) == std::vector<int>({0, 1}));
    REQUIRE(t.pathToNode(0, 2) == std::vector<int>({0, 1, 2}));
    REQUIRE(t.pathToNode(0, 3) == std::vector<int>({0, 1, 2, 3}));
}

