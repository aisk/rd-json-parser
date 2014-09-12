#include <memory>
#include <string>
#include <iostream>
#include "parser.h"


using namespace json;

Parser::Parser(std::string &text) {
    this->at = 0;
    this->lino = 0;
    this->text = text;
    this->ch = ' ';
}

char Parser::Next() {
    ch = this->text[this->at];
    this->at ++;
    return ch;
}

char Parser::Eat(char c) {
    if (ch != c) {
        throw std::exception();
    }
    this->at ++;
    ch = this->text[this->at];
    return ch;
}

void Parser::SkipWhite() {
    std::cout << this->ch << std::endl;
    while (this->ch <= ' ') {
        this->Next();
    }
}

JsonObject *Parser::Parse() {
    this->SkipWhite();
    std::cout << this->at << std::endl;
    switch(ch) {
    case '{':
        return this->ParseObject();
    case '[':
        return this->ParseArray();
    case '"':
        return this->ParseString();
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
        return this->ParseNumber();
    default:
        return this->ParseWord();
    }
}

int main() {
    auto s = std::string(" 1 ");
    auto parser = std::make_shared<Parser>(s);
    parser->Parse();
}
