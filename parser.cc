#include <memory>
#include "parser.h"


using namespace json;

Parser::Parser(std::string &text) {
    this->at = 0;
    this->lino = 0;
    this->text = text;
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
    while (this->ch <= ' ') {
        this->Next();
    }
}

int main() {
    auto s = std::string("{}");
    auto parser = std::make_shared<Parser>(s);

}
