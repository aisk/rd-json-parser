#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include <typeinfo>
#include "parser.h"

using namespace json;

SyntaxError::SyntaxError(size_t at, size_t lino, std::string msg) {
    this->at = at;
    this->lino = lino;
    this->msg = msg;
}

const char *SyntaxError::what() {
    return this->msg.c_str();
}

std::string JSONObject::ToString() {
    throw std::exception();
}

std::string Integer::ToString() {
    return std::to_string(value);
}

std::string Float::ToString() {
    return std::to_string(value);
}

std::string String::ToString() {
    return value;
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
        std::stringstream s;
        s << "expect: " << c << ", got: " << ch;
        throw SyntaxError(this->at, this->lino, s.str());
    }
    ch = text[at];
    at++;
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
    while (isdigit(ch)) {
        s.push_back(ch);
        Next();
    }
    if (ch == '.') {
        // float
        this->Eat('.');
        s.push_back('.');
        while (isdigit(ch)) {
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
    auto s = std::string();
    while (Next()) {
        if (ch == '"') {
            return new String(s);
        }
        if (ch == '\\') {

        }
        else {
            s.push_back(ch);
        }
    }
}

JSONObject *Parser::ParseKeyword() {
    switch (ch) {
        case 't':
            Eat('t');
            Eat('r');
            Eat('u');
            Eat('e');
            return new True();
        case 'f':
            Eat('f');
            Eat('a');
            Eat('l');
            Eat('s');
            Eat('e');
            return new False();
        case 'n':
            Eat('n');
            Eat('u');
            Eat('l');
            Eat('l');
            return new Null();
        default:
            std::stringstream s;
            s << "Unexpected '" << ch << "'";
            throw SyntaxError(at, lino, s.str());
    }
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
            return ParseKeyword();
    }
}
