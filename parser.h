#pragma once

#include <string>

namespace json {
    class JsonObject {
        virtual std::string ToString();
    };

    class Object : Json {
    };

    class Array : Json {
    };

    class Number : Json {
    };

    class String : Json {
    };

    class True : Json {
    };

    class False : Json {
    };

    class Null : Json {
    };

    class Parser {
        std::string text;
        char ch;
        size_t at;
        size_t lino;
        char Next();
        char Eat(char);
        void SkipWhite();
        JsonObject *ParseObject();
        JsonObject *ParseArray();
        JsonObject *ParseString();
        JsonObject *ParseNumber();
        JsonObject *ParseWord();
        public:
        Parser(std::string &);
        JsonObject *Parse();
    };
}
