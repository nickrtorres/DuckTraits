# vim: tw=80:noexpandtab:sw=8:ts=8:sts=8
.POSIX:
.SUFFIXES:

CXXFLAGS = -D GOOD

all: main

main: main.o
	c++ -std=c++11 -Wall -Werror $(CXXFLAGS) $@.o -o $@

main.o: main.cpp Duck.h

.SUFFIXES: .cpp .o
.cpp.o:
	c++ -std=c++11 -Wall -Werror -c $(CXXFLAGS) $< -o $@

clean:
	rm -f main.o main
