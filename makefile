CXXFLAGS=-g -Wall -std=c++1y
CXX=g++

SRC=$(wildcard *.cpp)
TRG=$(patsubst %.cpp,%,$(SRC))

list:
	echo $(SRC)
	echo $(TRG)

build: $(TRG)

node.o: node.cpp node.hpp
	$(CXX) $(CXXFLAGS) -c $<
btree: btree.cpp node.o
	$(CXX) $(CXXFLAGS) $^ -o $@



clean:
	rm *.exe $(TRG) *.o
