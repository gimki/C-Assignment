//
//  Rook.cpp
//  
//
//  Created by Colman Yau on 01/12/2015.
//
//
#include "Rook.h"
#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

Rook::Rook(bool _white): ChessPiece(_white){
    _king=0;
}

Rook::~Rook(){
    
}


string Rook::name(){
    return "Rook";
}

bool Rook::validmove(string s_sq, string d_sq, map<string,ChessPiece*>* chessboard1){
    
    if(!(sameColumn(s_sq,d_sq)||sameRow(s_sq,d_sq))){
        return 0;
    }
    
    if(sameColumn(s_sq,d_sq)&&vObstruction(s_sq,d_sq,chessboard1)){
        return 0;
    }
    if(sameRow(s_sq,d_sq)&&hObstruction(s_sq,d_sq,chessboard1)){
        return 0;
    }
    
    if(clashWithFriendly(d_sq,chessboard1)){
        return 0;
    }
    
    return 1;
    
}
