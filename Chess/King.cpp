//
//  King.cpp
//  
//
//  Created by Colman Yau on 01/12/2015.
//
//

#include "King.h"
#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

King:: King(bool _white): ChessPiece(_white){
    _king=1;
}

King::~King(){
}


bool King::fitMoveRule(string s_sq, string d_sq){
    
    char s_col=s_sq.at(0);
    char s_row=s_sq.at(1);
    char d_col=d_sq.at(0);
    char d_row=d_sq.at(1);
    
    if(max(abs(d_row-s_row),abs(d_col-s_col))==1){
        return 1;
    }else{
        return 0;
    }
    
}
string King::name(){
    return "King";
}

bool King::validmove(string s_sq, string d_sq, map<string,ChessPiece*>* chessboard1){
    
    if(clashWithFriendly(d_sq, chessboard1)==1){
        return 0;
    }
    if(!fitMoveRule(s_sq,d_sq)){
        return 0;
    }
    
    return 1;
    
}
