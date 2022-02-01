CC=g++

all: main

main: Proj2.cpp Sort.o
	g++ -std=c++11 Proj2.cpp Sort.o -o main

Sort.o: Sort.cpp
	g++ -c -std=c++11 Sort.cpp

clean: rm -rf *.o main