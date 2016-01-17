sudoku: main.o sudoku.o
	g++ -g  -Wall main.o sudoku.o -o sudoku

sudoku.o: sudoku.cpp sudoku.h
	g++ -g -Wall -c sudoku.cpp
main.o: main.cpp sudoku.h
	g++ -g -Wall -c main.cpp
