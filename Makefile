CXX=g++

CXXFLAGS = -std=c++11 -Wall -Wextra

all: prog1

prog1: main.o prog1.o hashTable.o minHeap.o
	${CXX} $^ -o $@

clean: 
	/bin/rm -f prog1 *.o