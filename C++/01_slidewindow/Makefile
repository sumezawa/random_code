CXX = clang++

CXXFLAGS = -std=c++11 -g -Wall

BINARIES = ksum

all: ${BINARIES}

ksum: ksum.o
	${CXX} $^ -o $@

test: ${BINARIES}
	- valgrind -q --leak-check=full ./ksum

clean:
	/bin/rm -f ${BINARIES} *.o
