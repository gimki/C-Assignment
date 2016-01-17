//
//  ChessPiece.cpp
//  
//
//  Created by Colman Yau on 01/12/2015.
//
//

#include "ChessPiece.h"
#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

ChessPiece::ChessPiece(bool _white){
    _whiteside=_white;
}

ChessPiece::~ChessPiece(){

}

bool ChessPiece::iswhite(){
    return _whiteside;
}

bool ChessPiece::isking(){
    return _king;
}

bool ChessPiece::isenermy(ChessPiece* cp){
    
    if(this->iswhite()==cp->iswhite()){
        return 0;
    }else{
        return 1;
    }

}

bool ChessPiece::clashWithFriendly(string d_sq, map<string, ChessPiece*>* chessboard1){
    
    if(chessboard1->at(d_sq)==NULL){
        return false;
    }

    if(isenermy(chessboard1->at(d_sq))){
        return false;
    }else{
        return true;
    }
    
}

bool ChessPiece::vObstruction(string s_sq, string d_sq, map<string, ChessPiece*>* chessboard1){
    
    char s_col=s_sq.at(0);
    char s_row=s_sq.at(1);
    char d_row=d_sq.at(1);
    
    char min_row;
    char high_row;
    
    if (s_row<d_row){
        min_row=s_row;
        high_row=d_row;
    }else{
        min_row=d_row;
        high_row=s_row;
    }
    
    for(char i=min_row+1; i<high_row; i++){
        string T;
        T+=s_col;
        T+=i;
        if(chessboard1->at(T)!=NULL){
            return true;
        }
    }
    return false;
    
}

bool ChessPiece::hObstruction(string s_sq, string d_sq, map<string, ChessPiece*>* chessboard1){
    
    char s_col=s_sq.at(0);
    char s_row=s_sq.at(1);
    char d_col=d_sq.at(0);
    
    char min_col;
    char high_col;
    
    if (s_col<d_col){
        min_col=s_col;
        high_col=d_col;
    }else{
        min_col=d_col;
        high_col=s_col;
    }
    
    for(char i=min_col+1; i<high_col; i++){
        string T;
        T+=i;
        T+=s_row;
	
        if(chessboard1->at(T)!=NULL){
            return true;
        }
        
    }
    return false;
}

bool ChessPiece::diagonalObstruction(string s_sq, string d_sq, map<string, ChessPiece*>* chessboard1){
    
    if(!sameDiagonal(s_sq, d_sq)){
        return 0;
    }
    char s_col=s_sq.at(0);
    char s_row=s_sq.at(1);
    char d_col=d_sq.at(0);
    char d_row=d_sq.at(1);
    
    char min_col=(s_col<d_col)? s_col: d_col;
    
    char min_row=(s_row<d_row)? s_row: d_row;
    char max_row=(s_row<d_row)? d_row: s_row;
    
    bool up_slope;
    
    if(d_col-s_col==d_row-s_row){
        up_slope=1;
    }else{
        up_slope=0;
    }
    
    for(int i=1; i<(max_row-min_row);i++){
        string T;
        if(up_slope){
            T+=(char)(min_col+i);
            T+=(char)(min_row+i);
        }else{
            T+=(char)(min_col+i);
            T+=(char)(max_row-i);
        }
       
        if(chessboard1->at(T)!=NULL){
            return true;
        }
    }
    return false;
}

bool ChessPiece::sameColumn(string sourPos, string destPos){
    
    if(sourPos[0]==destPos[0]){
        return 1;
    }else{
        return 0;
    }
}

bool ChessPiece::sameRow(string sourPos, string destPos){
    if(sourPos.at(1)==destPos.at(1)){
        return 1;
    }else{
        return 0;
    }
}

bool ChessPiece::sameDiagonal(string sourPos, string destPos){
    
    char s_col=sourPos.at(0);
    char s_row=sourPos.at(1);
    char d_col=destPos.at(0);
    char d_row=destPos.at(1);
    
    if(abs(d_row-s_row)==abs(d_col-s_col)){
        return 1;
    }else{
        return 0;
    }
}
