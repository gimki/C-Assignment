//
//  Bishop.cpp
//  
//
//  Created by Colman Yau on 01/12/2015.
//
//

#include "Bishop.h"
#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

Bishop::Bishop(bool _white): ChessPiece(_white){
    _king=0;
}

Bishop::~Bishop(){
}

string Bishop::name(){
    return "Bishop";
}

bool Bishop::validmove(string s_sq, string d_sq, map<string,ChessPiece*>* chessboard1){
  
    if(!(sameDiagonal(s_sq,d_sq))){
        return 0;
    }
   
    if(sameDiagonal(s_sq,d_sq)&&diagonalObstruction(s_sq,d_sq,chessboard1)){
        return 0;
    }
 
    if(clashWithFriendly(d_sq,chessboard1)){
        return 0;
    }
    
    return 1;
    
}
