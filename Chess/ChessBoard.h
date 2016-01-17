//
//  ChessBoard.h
//  
//
//  Created by Colman Yau on 01/12/2015.
//
//

#ifndef ChessBoard_h
#define ChessBoard_h


#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <cmath>


#include "ChessPiece.h"
#include "King.h"
#include "Rook.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"



using namespace std;

class ChessBoard{
protected:
    
    //chessboard which holds chess itself as pointers
    //chessboard itself is a pointer here too
    //designed as if we need to change chessboard
    map<string, ChessPiece*>* chessboard;
    
    //keep track of which side's turn at the current move
    bool whiteturn;
    
    //keep track if the game has ended or not
    bool gameEnded;
    
public:
    
    //constructor function: creating a new chessboard and reset all the pieces positions
    ChessBoard();
    
    //destructor function: destroying all the pieces points on the board and the board itself
    ~ChessBoard();
    
    //reset all the pieces position and reset as it is the start of the game
    void resetBoard();
    
    //submitting a move and try to see whether it is valid or not;
    //move will be implemented if the move is valid
    void submitMove(const string s_sq, const string d_sq);
    
private:
    
    //checking whether the string sq is a valid position or not
    bool validPos(const string sq);
    
    //returning the position of the king of the _white side as a string
    string findKing(bool _white, map<string, ChessPiece*>* board);
    
    //Check whether or not the _white is in check
    bool isGameInChecked(bool _white,map<string, ChessPiece*>* board);
    
    //checking if there is a possible move to _pos from any piece on the board of the _white side
    bool isPossibleMove(bool _white, string _pos, map<string, ChessPiece*>* board);
    
    //check whether or not the _white is in checkmate or not
    bool isGameInCheckmate(bool _white, map<string, ChessPiece*>* chessboard1);
    
    //a void function that cout if there is an invalid move made
    void output_invalid_move(string s_sq, string d_sq, map<string, ChessPiece*>* board);
    
    //a void function that cout if the move is valid
    void output_valid_move(string s_sq, string d_sq, map<string, ChessPiece*>* board);
    
    //a void function that cout if the move is valid and will capture a piece
    void output_capture_move(string s_sq, string d_sq, map<string, ChessPiece*>* board);
    
    //a void function that delete all the points of the pieces on the board
    void deleteBoard(map<string, ChessPiece*>* board);
    
    //a boolean function showing if there is a possible move to _pos (except moving the King)
    bool isPossibleMove_notking(bool _white, string _pos, map<string, ChessPiece*>* board);
    
    //a boolean function to check if the game is ended in stalemate
    bool gameStalemate(bool _white, map<string, ChessPiece*>* board);
};




#endif /* ChessBoard_h */
