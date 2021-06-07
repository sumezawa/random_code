CXX = clang++

CXXFLAGS = -std=c++11 -Wall

BINARIES = stream_filter

all: ${BINARIES}

stream_filter: stream_filter.o
	${CXX} $^ -o $@

test: ${BINARIES}
	- valgrind -q --leak-check=full ./stream_filter

clean:
	/bin/rm -f ${BINARIES} *.o
