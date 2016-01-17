//
//  Queen.cpp
//  
//
//  Created by Colman Yau on 01/12/2015.
//
//

#include "Queen.h"
#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;
Queen::Queen(bool _white): ChessPiece(_white){
    _king=0;
}

Queen::~Queen(){

}

string Queen::name(){
    return "Queen";
}

bool Queen::validmove(string s_sq, string d_sq, map<string,ChessPiece*>* chessboard1){
    
    if(sameDiagonal(s_sq,d_sq)){
        
        if(sameDiagonal(s_sq,d_sq)&&diagonalObstruction(s_sq,d_sq,chessboard1)){
            return 0;
        }
        
        if(clashWithFriendly(d_sq,chessboard1)){
            return 0;
        }
        
        return 1;
        
    }else if(sameColumn(s_sq,d_sq)||sameRow(s_sq,d_sq)){
        
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
    
    }else{
    
        return 0;
    
    }
    
    return 0;
    
}
