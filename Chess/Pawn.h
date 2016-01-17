//
//  Pawn.h
//  
//
//  Created by Colman Yau on 01/12/2015.
//
//

#ifndef Pawn_h
#define Pawn_h

#include <map>
#include <string>
#include "ChessPiece.h"

using namespace std;

class Pawn: public ChessPiece{
    
private:
    
    //Pawn can advance two steps if they are on the first move
    //this boolean indicate whether the pawn has taken the first move or not
    bool first_move;
    
    //Function that can check whether the source square and the destination square are in
    //adjacent column
    bool adjacentColumn(string s_sq, string d_sq);
    
public:
    
    //Constructor Function: creating a Pawn Piece which is a subclass of ChessPiece
    Pawn(bool _white);
    
    //Destructor Function: destroying the object Pawn
    virtual ~Pawn();
    
    //validmove: a boolean function which return True or False depending whether the move is valid or not
    //it will check whether the move is valid according to the rule,
    //and whether the destination square is occupied by friendly unit (clash)
    virtual bool validmove(string s_sq, string d_sq, map<string,ChessPiece*>* chessboard1);
    
    //name: returning "Pawn" upon calling
    virtual string name();
    
    //it will turn first_move into 0
    virtual void confirmmove();
    
    
    
    
};
#endif /* Pawn_h */
