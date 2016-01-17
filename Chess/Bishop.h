//
//  Bishop.h
//  
//
//  Created by Colman Yau on 01/12/2015.
//
//

#ifndef Bishop_h
#define Bishop_h

#include <map>
#include <string>
#include "ChessPiece.h"

using namespace std;

class Bishop: public ChessPiece{

public:
    
    //Constructor Function: creating a Bishop Piece which is a subclass of ChessPiece
    Bishop(bool _white);
    
    //Destructor Function: destroying the object Bishop
    virtual ~Bishop();
    
    //validmove: a boolean function which return True or False depending whether the move is valid or not
    //it will check whether the path is in the same diagonal, whether there is obstruction on the diagonal
    //and whether the destination square is occupied by friendly unit (clash)
    virtual bool validmove(string s_sq, string d_sq, map<string,ChessPiece*>* chessboard1);
    
    //name: returning "Bishop" upon calling
    virtual string name();
};
#endif /* Bishop_h */
