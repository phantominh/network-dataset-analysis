#include "../traversals.h"

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"



TEST_CASE("test linker make file", "[traversals]") {
    Traversal obj = Traversal();
    std::string test = obj.message();
    REQUIRE(test == "Hello, World!");
}

TEST_CASE("basic dfs traversal") {
    
}