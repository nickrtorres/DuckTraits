# vim: tw=80:noexpandtab:sw=8:ts=8:sts=8
.POSIX:
.SUFFIXES:

CXXFLAGS = -D GOOD

all: main

main: main.o
	c++ -std=c++11 $(CXXFLAGS) $@.o -o $@

main.o: main.cpp Duck.h DuckTraits.h DuckOps.h

.SUFFIXES: .cpp .o
.cpp.o:
	c++ -std=c++11 -c $(CXXFLAGS) $< -o $@

clean:
	rm -f main.o main
