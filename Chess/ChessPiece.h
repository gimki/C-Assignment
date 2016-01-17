//
//  ChessPiece.h
//  
//
//  Created by Colman Yau on 01/12/2015.
//
//

#ifndef ChessPiece_h
#define ChessPiece_h


#include <map>
#include <string>
#include <cmath>

using namespace std;

class ChessPiece{
    
protected:
    
    //boolean to define whether the chess piece is white(1) or not(0)
    bool _whiteside;
    
    //boolean to define whether the chess piece is king(1) or not(0)
    bool _king;
    
    //clashWithFriendly will only check whether the d_sq is enermy or not
    //will not check whether d_sq is valid or d_sq is empty
    bool clashWithFriendly(string d_sq, map<string, ChessPiece*>* chessboard1);
    
    //checking whether there is any obstruction in the vertical/horizontal direction
    bool vObstruction(string s_sq, string d_sq, map<string, ChessPiece*>* chessboard1);
    bool hObstruction(string s_sq, string d_sq, map<string, ChessPiece*>* chessboard1);
    
    //checking whether there is any obstruction on the diagonal
    bool diagonalObstruction(string s_sq, string d_sq, map<string, ChessPiece*>* chessboard1);
    
    //checking whether the two squares are in the same column/row/diagonal
    bool sameColumn(string sourPos, string destPos);
    bool sameRow(string sourPos, string destPos);
    bool sameDiagonal(string sourPos, string destPos);
    
public:
    
    ChessPiece(bool _white);
    
    virtual ~ChessPiece();
    
    //check whether the piece is white(1) or not(0)
    bool iswhite();
    
    //check whether the piece is king(1) or not(0)
    bool isking();
    
    //check whether the other piece is enermy(1) or not(0)
    bool isenermy(ChessPiece* cp);
    
    //check if it is a validmove
    virtual bool validmove(string s_sq, string d_sq, map<string, ChessPiece*>* chessboard1) = 0;
    
    //return the name of the piece accordingly
    virtual string name()=0;
    
    //mainly for Pawn as they has different move rule if they are on their first move
    virtual void confirmmove(){};
};


#endif /* ChessPiece_h */
