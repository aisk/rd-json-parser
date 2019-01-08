default: a.out
	./a.out

catch.hpp:
	wget https://github.com/catchorg/Catch2/releases/download/v2.5.0/catch.hpp

a.out: catch.hpp test.cpp parser.cpp parser.hpp
	clang++ -std=c++11 -g parser.cpp test.cpp -o a.out

clean:
	rm -rf a.out a.out.dSYM

.PHONY: default clean test
