enigma: enigma.o main.o errors.h
	g++  -g -Wall enigma.o main.o  -o enigma

enigma.o: enigma.cpp enigma.h errors.h
	g++  -g -Wall -c enigma.cpp

main.o: main.cpp enigma.h errors.h
	g++  -g -Wall -c main.cpp
