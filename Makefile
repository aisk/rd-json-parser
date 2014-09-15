default: a.out
	./a.out

catch.hpp:
	wget https://raw.github.com/philsquared/Catch/master/single_include/catch.hpp

a.out: catch.hpp test.cpp parser.cpp parser.hpp
	clang++ -std=c++11 -g parser.cpp test.cpp -o a.out

clean:
	rm -rf a.out a.out.dSYM

.PHONY: default clean test
