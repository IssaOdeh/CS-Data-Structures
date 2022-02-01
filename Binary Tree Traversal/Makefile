CC=g++



all: main



main: PA03.cpp Binary.o

	g++ -std=c++11 PA03.cpp Binary.o -o main



Binary.o: Binary.cpp

	g++ -c -std=c++11 Binary.cpp



clean: rm -rf *.o main