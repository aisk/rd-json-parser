#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include <typeinfo>
#include "parser.h"

using namespace json;

std::string JSONObject::ToString() {
    throw std::exception();
}

std::string Integer::ToString() {
    return std::to_string(value);
}

Parser::Parser(std::string &text) {
    this->at = 0;
    this->lino = 0;
    this->text = text;
    this->ch = ' ';
}

char Parser::Next() {
    ch = text[at];
    at ++;
    return ch;
}

char Parser::Eat(char c) {
    if (ch != c) {
        throw std::exception();
    }
    at ++;
    ch = text[at];
    return ch;
}

void Parser::SkipWhite() {
    while (ch <= ' ') {
        Next();
    }
}

JSONObject *Parser::ParseObject() {
    return nullptr;
}

JSONObject *Parser::ParseNumber() {
    auto s = std::string("");
    if (ch == '-') {
        s.push_back(ch);
        Eat('-');
    }
    while (std::isdigit(ch)) {
        s.push_back(ch);
        Next();
    }
    if (ch == '.') {
        // float
        while (std::isdigit(ch)) {
            s.push_back(ch);
            Next();
        }
        return new Float(std::atof(s.c_str()));
    } else {
        // integer
        return new Integer(std::atol(s.c_str()));
    }
}

JSONObject *Parser::ParseArray() {
    return nullptr;
}

JSONObject *Parser::ParseString() {
    return nullptr;
}

JSONObject *Parser::ParseWord() {
    return nullptr;
}

JSONObject *Parser::Parse() {
    SkipWhite();
    switch(ch) {
    case '{':
        return ParseObject();
    case '[':
        return ParseArray();
    case '"':
        return ParseString();
    case '-':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '0':
        return ParseNumber();
    default:
        return ParseWord();
    }
}
