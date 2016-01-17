words: words.o main.o
	g++ -Wall -g words.o main.o -o words

words.o: words.cpp words.h
	g++ -Wall -g -c words.cpp

main.o: main.cpp words.h
	g++ -Wall -g -c main.cpp