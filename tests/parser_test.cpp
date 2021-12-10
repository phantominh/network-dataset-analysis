#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../parser.h"
#include <unordered_map>
#include <iostream>

// TODO: Delete this after you complete at least 1 test case, else Makefile linker will break
TEST_CASE("Foo") {
    REQUIRE(1==1);
}

TEST_CASE("empty data") {
    Parser parseObj = Parser();
    parseObj.parseData("data/parser_empty.txt");
    std::vector<std::pair<int, int>> result (parseObj.data_);

    REQUIRE(result.size()==0);
    
}

TEST_CASE("data with 1 observation") {
    Parser parseObj = Parser();
    parseObj.parseData("data/parser_1.txt");
    std::vector<std::pair<int, int>> result (parseObj.data_);

    REQUIRE(result[0].first == 0);
    REQUIRE(result[0].second == 1);
}

TEST_CASE("data small") {
    Parser parseObj = Parser();
    parseObj.parseData("data/df_small.txt");
    std::vector<std::pair<int, int>> result (parseObj.data_);

    REQUIRE(result.size()==36);
}