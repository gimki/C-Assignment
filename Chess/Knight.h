//
//  Knight.h
//  
//
//  Created by Colman Yau on 01/12/2015.
//
//

#ifndef Knight_h
#define Knight_h

#include <map>
#include <string>
#include "ChessPiece.h"

using namespace std;

class Knight: public ChessPiece{
    
public:
    
    //Constructor Function: creating a Knight Piece which is a subclass of ChessPiece
    Knight(bool _white);
    
    //Destructor Function: destroying the object Knight
    virtual ~Knight();
    
    //validmove: a boolean function which return True or False depending whether the move is valid or not
    //it will check whether the move is valid according to the rule,
    //and whether the destination square is occupied by friendly unit (clash)
    bool validmove(string s_sq, string d_sq, map<string,ChessPiece*>* chessboard1);
    
    //name: returning "Knight" upon calling
    virtual string name();
    
    
    
    
};
#endif /* Knight_h */
