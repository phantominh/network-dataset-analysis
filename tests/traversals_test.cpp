#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../traversals.h"

// TODO: Delete this after you complete at least 1 test case, else Makefile linker will break
TEST_CASE("Foo") {
    REQUIRE(1==1);
}

TEST_CASE("test linker make file", "[traversals]") {
    Traversal obj = Traversal();
    std::string test = obj.message();
    REQUIRE(test == "Hello, World!");
}

TEST_CASE("basic dfs traversal") {
    
}