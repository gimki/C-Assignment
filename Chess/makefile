chess: ChessMain.o Bishop.o ChessBoard.o ChessPiece.o King.o Knight.o Pawn.o Queen.o Rook.o 
	g++  -g -Wall  ChessMain.o ChessPiece.o ChessBoard.o Bishop.o King.o Knight.o Pawn.o Queen.o Rook.o  -o chess

ChessMain.o: ChessMain.cpp ChessBoard.h
	g++ -g -Wall -c ChessMain.cpp

Bishop.o: Bishop.cpp Bishop.h
	g++  -g -Wall -c Bishop.cpp
ChessBoard.o: ChessBoard.cpp ChessBoard.h
	g++  -g -Wall -c ChessBoard.cpp
ChessPiece.o: ChessPiece.cpp ChessPiece.h
	g++ -g -Wall -c ChessPiece.cpp
King.o: King.cpp King.h
	g++  -g -Wall -c King.cpp
Knight.o: Knight.cpp Knight.h
	g++  -g -Wall -c Knight.cpp
Pawn.o: Pawn.cpp Pawn.h
	g++  -g -Wall -c Pawn.cpp
Queen.o: Queen.cpp Queen.h
	g++  -g -Wall -c Queen.cpp
Rook.o: Rook.cpp Rook.h
	g++  -g -Wall -c Rook.cpp


.PHONY: clean
clean:
	rm *.o

