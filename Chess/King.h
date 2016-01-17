//
//  King.h
//  
//
//  Created by Colman Yau on 01/12/2015.
//
//

#ifndef King_h
#define King_h

#include <map>
#include <string>
#include "ChessPiece.h"
using namespace std;

class King: public ChessPiece{
    
public:
    //Constructor Function: creating a King Piece which is a subclass of ChessPiece
    King(bool _white);
    
    //Destructor Function: destroying the object King
    virtual ~King();
    
    //validmove: a boolean function which return True or False depending whether the move is valid or not
    //it will check whether the move is valid according to the rule,
    //and whether the destination square is occupied by friendly unit (clash)
    virtual bool validmove(string s_sq, string d_sq, map<string,ChessPiece*>* chessboard1);
    
    //name: returning "King" upon calling
    virtual string name();
    
private:
    bool fitMoveRule(string s_sq,string d_sq);
    
};
#endif /* King_h */
