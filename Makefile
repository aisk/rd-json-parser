default: a.out
	./a.out

catch.hpp:
	wget https://raw.github.com/philsquared/Catch/master/single_include/catch.hpp

a.out: catch.hpp
	clang++ -std=c++11 -g parser.cc test.cc -o a.out

clean:
	rm -rf a.out a.out.dSYM

.PHONY: default clean test
