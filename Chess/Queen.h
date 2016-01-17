//
//  Queen.h
//  
//
//  Created by Colman Yau on 01/12/2015.
//
//

#ifndef Queen_h
#define Queen_h

#include <map>
#include <string>
#include "ChessPiece.h"

using namespace std;

class Queen: public ChessPiece{
    
public:
    
    //Constructor Function: creating a Queen Piece which is a subclass of ChessPiece
    Queen(bool _white);
    
    //Destructor Function: destroying the object Queen
    virtual ~Queen();
    
    //validmove: a boolean function which return True or False depending whether the move is valid or not
    //it will check whether the path is in the same column or row/diagonal,
    //whether there is obstruction on the path,
    //and whether the destination square is occupied by friendly unit (clash)
    bool validmove(string s_sq, string d_sq, map<string,ChessPiece*>* chessboard1);
    
    //name: returning "Queen" upon calling
    virtual string name();
    
    
    
    
};
#endif /* Queen_h */
