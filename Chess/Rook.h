//
//  Rook.h
//  
//
//  Created by Colman Yau on 01/12/2015.
//
//

#ifndef Rook_h
#define Rook_h

#include <map>
#include <string>
#include "ChessPiece.h"

using namespace std;

class Rook: public ChessPiece{
    
public:
    
    //Constructor Function: creating a Rook Piece which is a subclass of ChessPiece
    Rook(bool _white);
    
    //Destructor Function: destroying the object Rook
    virtual ~Rook();
    
    //validmove: a boolean function which return True or False depending whether the move is valid or not
    //it will check whether the path is in the same column or row, whether there is obstruction on the path
    //and whether the destination square is occupied by friendly unit (clash)
    virtual bool validmove(string s_sq, string d_sq, map<string,ChessPiece*>* chessboard1);
    
    //name: returning "Rook" upon calling
    virtual string name();
    
    
    
    
};
#endif /* Rook_h */
