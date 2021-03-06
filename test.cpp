#define CATCH_CONFIG_MAIN

#include <memory>
#include <string>
#include <iostream>
#include "catch.hpp"
#include "parser.hpp"

using namespace json;

TEST_CASE("Parse integer", "[json::Parser::ParseNumber]") {
    auto s = std::string(" 42 ");
    auto parser = std::make_shared<Parser>(s);
    auto r = parser->Parse();
    REQUIRE(dynamic_cast<Integer *>(r)->GetValue() == 42);
    delete r;
}

TEST_CASE("Parse float", "[json::Parser::ParseNumber]") {
	auto s = std::string("0.618");
	auto parser = std::make_shared<Parser>(s);
	auto r = parser->Parse();
	REQUIRE(dynamic_cast<Float *>(r)->GetValue() == 0.618);
    delete r;
}

TEST_CASE("Parse negative number", "[json::Parser::ParseNumber]") {
	auto s = std::string("   -42 ");
	auto parser = std::make_shared<Parser>(s);
	auto r = parser->Parse();
	REQUIRE(dynamic_cast<Integer *>(r)->GetValue() == -42);
    delete r;
}

TEST_CASE("Parse true", "[json::Parser::ParseKeyword]") {
	auto s = std::string("  true ");
	auto parser = std::make_shared<Parser>(s);
	auto r = parser->Parse();
	REQUIRE(dynamic_cast<True *>(r) != NULL);
    delete r;
}

TEST_CASE("Parse false", "[json::Parser::ParseKeyword]") {
	auto s = std::string("  false ");
	auto parser = std::make_shared<Parser>(s);
	auto r = parser->Parse();
	REQUIRE(dynamic_cast<False *>(r) != NULL);
    delete r;
}

TEST_CASE("Parse null", "[json::Parser::ParseKeyword]") {
	auto s = std::string("  null ");
	auto parser = std::make_shared<Parser>(s);
	auto r = parser->Parse();
	REQUIRE(dynamic_cast<Null *>(r) != NULL);
    delete r;
}

TEST_CASE("Parse string", "[json::Parser::ParseString]") {
	auto s = std::string(" \"Hello World!\"  ");
	auto parser = std::make_shared<Parser>(s);
	auto r = parser->Parse();
	REQUIRE(dynamic_cast<String *>(r)->GetValue() == std::string("Hello World!"));
    delete r;
}
