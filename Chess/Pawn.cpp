//
//  Pawn.cpp
//  
//
//  Created by Colman Yau on 01/12/2015.
//
//
#include "Pawn.h"
#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;


Pawn::Pawn (bool _white): ChessPiece(_white){
    _king=0;
    first_move=1;
}

Pawn::~Pawn(){

}

string Pawn::name(){
    return "Pawn";
}

bool Pawn::adjacentColumn(string s_sq, string d_sq){
    
    char s_col=s_sq.at(0);
    char d_col=d_sq.at(0);
    
    if(abs(s_col-d_col)==1){
        return 1;
    }else{
        return 0;
    }
}

bool Pawn::validmove(string s_sq, string d_sq, map<string,ChessPiece*>* chessboard1){
    
    char d_row=d_sq.at(1);
    char s_row=s_sq.at(1);
    
    int dir_diff_row= _whiteside? d_row-s_row : s_row-d_row;
    
    //normal move on the same Column
    if(sameColumn(s_sq,d_sq)){
       
        switch(dir_diff_row){
                
            case 1:{
                
                if((chessboard1->at(d_sq))!=NULL){
                    
                    return 0;
                }
                return 1;
            }
                
            case 2: {
                
                if(!first_move){
                    return 0;
                }
                
                if(vObstruction(s_sq,d_sq, chessboard1)){
                    return 0;
                }
                
                if(chessboard1->at(d_sq)!=NULL){
                    return 0;
                }
                
                return 1;
            }
                
            default: {
                return 0;
            }
        }
        
    }else if(adjacentColumn(s_sq,d_sq)){
        
            if(dir_diff_row!=1){
                return 0;
            }
        
            if(chessboard1->at(d_sq)==NULL){
                return 0;
            }
        
            if(clashWithFriendly(d_sq, chessboard1)){
                return 0;
            }
            return 1;
    }

    return 0;
}


void Pawn::confirmmove(){
    first_move=0;
}
