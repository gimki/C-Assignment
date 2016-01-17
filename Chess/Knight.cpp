//
//  Knight.cpp
//  
//
//  Created by Colman Yau on 01/12/2015.
//
//

#include "Knight.h"
#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;


Knight:: Knight(bool _white): ChessPiece(_white){
    _king=0;
}

Knight::~Knight(){

}

string Knight::name(){
    return "Knight";
}

bool Knight::validmove(string s_sq, string d_sq, map<string,ChessPiece*>* chessboard1){
    
    char s_col=s_sq.at(0);
    char s_row=s_sq.at(1);
    char d_col=d_sq.at(0);
    char d_row=d_sq.at(1);
    
    int horizontal_diff=abs(d_row-s_row);
    int vertical_diff=abs(d_col-s_col);
    
    if(horizontal_diff*vertical_diff!=2){
        return 0;
    }
    
    if(clashWithFriendly(d_sq, chessboard1)){
        return 0;
    }
    
    return 1;
    
}
