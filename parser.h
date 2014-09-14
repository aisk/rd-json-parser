#pragma once

#include <string>

namespace json {
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
        Integer(long value) : value(value) {};
        long GetValue() { return value; };
        virtual std::string ToString();
    };

    class Float : public Number {
        double value;
        public:
        Float(double value) : value(value) {};
		double GetValue() { return value; };
		virtual std::string ToString();
    };

    class String : public JSONObject {
        std::string value;
        public:
        String(std::string value) : value(value) {};
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
        JSONObject *ParseWord();
        public:
        Parser(std::string &);
        JSONObject *Parse();
    };
}
