#define CATCH_CONFIG_MAIN

#include <memory>
#include <string>
#include <iostream>

#include "catch.hpp"
#include "parser.h"

using namespace json;

TEST_CASE("Parse integer", "[json::Parser::ParseNumber]") {
    auto s = std::string(" 42 ");
    auto parser = std::make_shared<Parser>(s);
    auto r = parser->Parse();
    REQUIRE(dynamic_cast<Integer *>(r)->GetValue() == 42);
}

TEST_CASE("Parse float", "[json::Parser::ParseNumber]") {
	auto s = std::string("0.618");
	auto parser = std::make_shared<Parser>(s);
	auto r = parser->Parse();
	REQUIRE(dynamic_cast<Float *>(r)->GetValue() == 0.618);
}

TEST_CASE("Parse negative number", "[json::Parser::ParseNumber]") {
	auto s = std::string("   -42 ");
	auto parser = std::make_shared<Parser>(s);
	auto r = parser->Parse();
	REQUIRE(dynamic_cast<Integer *>(r)->GetValue() == -42);
}