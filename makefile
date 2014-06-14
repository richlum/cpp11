CXXFLAGS=-g -Wall -std=c++11
CXX=g++

build: btree

node.o: node.cpp node.hpp
	$(CXX) $(CXXFLAGS) -c $<
btree: btree.cpp node.o
	$(CXX) $(CXXFLAGS) $^ -o $@



clean:
	rm *.exe *.o
