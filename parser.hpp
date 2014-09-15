#pragma once

#include <string>

namespace json {
    class SyntaxError : public std::exception {
        size_t at;
        size_t lino;
        std::string msg;
        public:
        explicit SyntaxError(size_t at, size_t lino, std::string msg);
        virtual const char *what();
    };

    class JSONObject {
        public:
            virtual std::string ToString();
    };

    class Object : public JSONObject {
    };

    class Array : public JSONObject {
    };

    class Number : public JSONObject {
    };

    class Integer : public Number {
        long value;
        public:
        explicit Integer(long value) : value(value) {};
        long GetValue() { return value; };
        virtual std::string ToString();
    };

    class Float : public Number {
        double value;
        public:
        explicit Float(double value) : value(value) {};
        double GetValue() { return value; };
        virtual std::string ToString();
    };

    class String : public JSONObject {
        std::string value;
        public:
        explicit String(std::string value) : value(value) {};
        std::string GetValue() { return value; };
        virtual std::string ToString();
    };

    class True : public JSONObject {
    };

    class False : public JSONObject {
    };

    class Null : public JSONObject {
    };

    class Parser {
        std::string text;
        char ch;
        size_t at;
        size_t lino;
        char Next();
        char Eat(char);
        void SkipWhite();
        JSONObject *ParseObject();
        JSONObject *ParseArray();
        JSONObject *ParseString();
        JSONObject *ParseNumber();
        JSONObject *ParseKeyword();
        public:
        explicit Parser(std::string &);
        JSONObject *Parse();
    };
}
