#pragma once

#include <string>

namespace json {
    class Parser {
        std::string text;
        char ch;
        size_t at;
        size_t lino;
        char Next();
        char Eat(char);
        void SkipWhite();
        public:
        Parser(std::string &);
        void Parse();
    };
}
