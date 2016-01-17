soundex: soundex.o main.o
	g++ -g -Wall soundex.o main.o -o soundex

main.o: main.cpp soundex.h
	g++ -g -Wall -c main.cpp

soundex.o: soundex.cpp soundex.h
	g++ -g -Wall -c soundex.cpp