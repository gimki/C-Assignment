//
//  ChessBoard.cpp
//  
//
//  Created by Colman Yau on 01/12/2015.
//
//

#include "ChessBoard.h"
#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>


ChessBoard::ChessBoard(){
    
    chessboard= new map<string, ChessPiece*>;
    whiteturn=1;
    gameEnded=0;
    resetBoard();
}

ChessBoard::~ChessBoard(){
    deleteBoard(chessboard);
}



void ChessBoard::resetBoard(){
    for(char i='A';i<='H';i++){
        
        for(char j='3';j<='6';j++){
            
            char empty[3];
            empty[0]=i;
            empty[1]=j;
            empty[2]='\0';
            (*chessboard)[empty] = NULL;
            
        }
        
        char blackpawn[3];
        blackpawn[0]=i;
        blackpawn[1]='7';
        blackpawn[2]='\0';
        (*chessboard)[blackpawn]= new Pawn(false);
        char whitepawn[3];
        whitepawn[0]=i;
        whitepawn[1]='2';
        whitepawn[2]='\0';
        (*chessboard)[whitepawn]= new Pawn(true);
        
    }
    
    (*chessboard)["A1"]=new Rook(true);
    (*chessboard)["B1"]=new Knight(true);
    (*chessboard)["C1"]=new Bishop(true);
    (*chessboard)["D1"]=new Queen(true);
    (*chessboard)["E1"]=new King(true);
    (*chessboard)["F1"]=new Bishop(true);
    (*chessboard)["G1"]=new Knight(true);
    (*chessboard)["H1"]=new Rook(true);
    
    (*chessboard)["A8"]=new Rook(false);
    (*chessboard)["B8"]=new Knight(false);
    (*chessboard)["C8"]=new Bishop(false);
    (*chessboard)["D8"]=new Queen(false);
    (*chessboard)["E8"]=new King(false);
    (*chessboard)["F8"]=new Bishop(false);
    (*chessboard)["G8"]=new Knight(false);
    (*chessboard)["H8"]=new Rook(false);
    
    whiteturn=1;
    gameEnded=0;
    cout<<"A new chess game is started!"<<endl;
}


void ChessBoard::deleteBoard(map<string, ChessPiece*>* board){
    
    for(char i='A';i<='H';i++){
        for(char j='1'; j<='8';j++){
            char temp[3];
            temp[0]=i;
            temp[1]=j;
            temp[2]='\0';
	  
            map<string, ChessPiece*>::iterator it = board->find(temp);
            if (board->end() == it) {
                cerr << "position " << temp << " was not found in the map" << endl;
                
            }
            
            if(board->at(temp)==NULL){
                continue;
            }else{
                delete board->at(temp);
            }
        }
    }
}



void ChessBoard::submitMove(const string s_sq, const string d_sq){
    
    //check if the game is ended
    if(gameEnded){
        cout<<"The game has already ended. Move cannot be done."<<endl;
        return;
    }
    
    //check if the input position valid
    if(!(validPos(s_sq)||validPos(d_sq))){
        cout<<"The input positions are invalid. Move cannot be done."<<endl;
        return;
    }
    
    if(s_sq.compare(d_sq)==0){
        cout<<"Destination square equals to Source square. Move cannot be done."<<endl;
        return;
    }
    
    //check if source is empty
    if(chessboard->at(s_sq)==NULL){
        cout<<"There is no piece at position "<<s_sq<<"!"<<endl;
        return;
    }
    
    //check if it is right side term
    if(((chessboard->at(s_sq))->iswhite())&&(!whiteturn)){
        cout<< "It is not White's turn to move!"<<endl;
        return;
    }else if((!(chessboard->at(s_sq))->iswhite())&&(whiteturn)){
        cout<< "It is not Black's turn to move!"<<endl;
        return;
    }
    
    //check if the move is valid of not
    if(!((chessboard->at(s_sq))->validmove(s_sq,d_sq,chessboard))){
        
        output_invalid_move(s_sq,d_sq,chessboard);
        return;
    }
    
    
    ChessPiece* original_dest_piece=chessboard->at(d_sq);
    
    chessboard->at(d_sq)=chessboard->at(s_sq);
    chessboard->at(s_sq)=NULL;
    
    //check if after moved, the king is in checked or not
    if(isGameInChecked(whiteturn,chessboard)){
        
        chessboard->at(s_sq)=chessboard->at(d_sq);
        chessboard->at(d_sq)=original_dest_piece;
        
        output_invalid_move(s_sq,d_sq,chessboard);
        return;
    }
    
    
    
  
    //the move creates no check and is good to carry on
    if(!isGameInChecked(!whiteturn, chessboard)){
        
        
        if(original_dest_piece==NULL){
            
            chessboard->at(s_sq)=chessboard->at(d_sq);
            chessboard->at(d_sq)=original_dest_piece;
        
            output_valid_move(s_sq,d_sq,chessboard);
            
        }else{
            chessboard->at(s_sq)=chessboard->at(d_sq);
            chessboard->at(d_sq)=original_dest_piece;
            
            output_capture_move(s_sq,d_sq,chessboard);
        }
        
        chessboard->at(d_sq)=chessboard->at(s_sq);
        chessboard->at(s_sq)=NULL;
        
        chessboard->at(d_sq)->confirmmove();
        
        if(gameStalemate(!whiteturn,chessboard)){
            cerr<<"This game ends in stalemate!";
            gameEnded=1;
            return;
        }
       
        whiteturn=!whiteturn;
        return;
    }else{
        //if created check, is it check mate?
        if(!isGameInCheckmate(!whiteturn, chessboard)){
            if(original_dest_piece==NULL){
                chessboard->at(s_sq)=chessboard->at(d_sq);
                chessboard->at(d_sq)=original_dest_piece;
                
                output_valid_move(s_sq,d_sq,chessboard);
            
            }else{
                chessboard->at(s_sq)=chessboard->at(d_sq);
                chessboard->at(d_sq)=original_dest_piece;
                
                output_capture_move(s_sq,d_sq,chessboard);
                
            }
            
            if(whiteturn==1){
                cout<<"Black is in check"<<endl;
            }else{
                cout<<"White is in check"<<endl;
            }
            whiteturn=!whiteturn;
            chessboard->at(d_sq)=chessboard->at(s_sq);
            chessboard->at(s_sq)=NULL;
            
            chessboard->at(d_sq)->confirmmove();
            
            return;
        }else{
            if(original_dest_piece==NULL){
                chessboard->at(s_sq)=chessboard->at(d_sq);
                chessboard->at(d_sq)=original_dest_piece;
                
                output_valid_move(s_sq,d_sq,chessboard);
                
            }else{
                chessboard->at(s_sq)=chessboard->at(d_sq);
                chessboard->at(d_sq)=original_dest_piece;
                
                output_capture_move(s_sq,d_sq,chessboard);
                
            }
            
            if(whiteturn==1){
                cout<<"Black is in checkmate"<<endl;
            }else{
                cout<<"White is in checkmate"<<endl;
            }
            gameEnded=1;
            return;
        }
    }
    return;
}



//next turn is _white move and see if there is anymove that is not under check
bool ChessBoard::gameStalemate(bool _white, map<string, ChessPiece*>* board){
    
    for(map<string, ChessPiece*>::iterator it=board->begin();it !=board->end();++it){
        string pos_sour=it->first;
        ChessPiece* pos_piece=it->second;
 
        if(pos_piece==NULL){
            continue;
        }
    
        if(pos_piece->iswhite()!=_white){
            continue;
        }
 
        for(char i='A'; i<='H'; i++){
            for(char j='1';j<='8';j++){
                
                string pos_des;
                pos_des+=i;
                pos_des+=j;
                
                if(pos_piece->validmove(pos_sour,pos_des,board)){
                    
                    ChessPiece* original_dest_piece=board->at(pos_des);
                    board->at(pos_des)=board->at(pos_sour);
                    board->at(pos_sour)=NULL;
                    
                    if(isGameInChecked(_white,board)){
                        board->at(pos_sour)=board->at(pos_des);
                        board->at(pos_des)=original_dest_piece;
                        continue;
                    }else{
                        board->at(pos_sour)=board->at(pos_des);
                        board->at(pos_des)=original_dest_piece;
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

bool ChessBoard::validPos(const string sq){
    
    if((sq.at(0)<'A')||(sq.at(0)>'H')){
        return 0;
    }
    if((sq.at(1)<'1')||(sq.at(1)>'8')){
        return 0;
    }
    
    return 1;
}

string ChessBoard::findKing(bool _white, map<string, ChessPiece*>* board){
    for(char i='A';i<='H';i++){
        for(char j='1'; j<='8';j++){
            string temp;
            temp=i;
            temp+=j;
            if(board->at(temp)==NULL){
                continue;
            }
            ChessPiece* test=board->at(temp);
            if(test->isking()&&(test->iswhite()==_white)){
                return temp;
            }
        }
    }
    return 0;
}

bool ChessBoard::isGameInChecked(bool _white,map<string, ChessPiece*>* board){
    
    string _king=findKing(_white, board);
    
    for(char i='A';i<='H';i++){
        for(char j='1'; j<='8';j++){
            string temp;
            temp=i;
            temp+=j;
            
            if(board->at(temp)==NULL){
                continue;
            }
            ChessPiece* test=board->at(temp);
            
            if (test->iswhite()==_white){
                continue;
            }
            
            if((temp.compare(_king))==0){
                continue;
            }
            if(test->validmove(temp,_king, board)){
                return 1;
            }
            
        }
    }
    return 0;
    
}

bool ChessBoard::isPossibleMove(bool _white, string _pos, map<string, ChessPiece*>* board){
    for (char i='A'; i<='H';i++){
        for (char j='1'; j<='8';j++){
            
            char position[3];
            position[0]=i;
            position[1]=j;
            position[2]='\0';
            
            if(_pos.compare(position)==0){
                continue;
            }
            
            
            if(board->at(position)==NULL){
                continue;
            }
            if(((board->at(position))->iswhite())!=_white){
                continue;
            }
            
            if(board->at(position)->validmove(position,_pos, board)){
                return 1;
            }else{
                continue;
            }
            
        }
    }
    return 0;
}


bool ChessBoard::isPossibleMove_notking(bool _white, string _pos, map<string, ChessPiece*>* board){
    
    string _king=findKing(_white,board);
    for (char i='A'; i<='H';i++){
        for (char j='1'; j<='8';j++){
            
            char position[3];
            position[0]=i;
            position[1]=j;
            position[2]='\0';
            
            if(_pos.compare(position)==0){
                continue;
            }
            
            if(_king.compare(position)==0){
                continue;
            }
            
            if(board->at(position)==NULL){
                continue;
            }
            if(((board->at(position))->iswhite())!=_white){
                continue;
            }
            
            if(board->at(position)->validmove(position,_pos, board)){
                return 1;
            }else{
                continue;
            }
            
        }
    }
    return 0;
}
bool ChessBoard::isGameInCheckmate(bool _white, map<string, ChessPiece*>* board){
    
    //it assume next term is white and check if white have any move to avoid a checkmate
    if(!isGameInChecked(_white, board)){
        return 0;
    }
    
    //the king try to move to escape
    string _king=findKing(_white, board);
    char x,y;
    x=_king[0];
    y=_king[1];
    
    for(char k=(x-1);k<=(x+1);k++){
        for(char t=(y-1);t<=(y+1);t++){
            char position[3];
            position[0]=k;
            position[1]=t;
            position[2]='\0';
            
            if(!validPos(position)){
                continue;
            }
            if(board->at(_king)->validmove(_king,position, board)){
                ChessPiece* original_dest_piece=board->at(position);
                board->at(position)=board->at(_king);
                board->at(_king)=NULL;
                if(isGameInChecked(_white,board)){
                    board->at(_king)=board->at(position);
                    board->at(position)=original_dest_piece;
                    continue;
                }else{
                    board->at(_king)=board->at(position);
                    board->at(position)=original_dest_piece;
                    return 0;
                }
                
            }
        }
    }
    
    //is blocking possible?
    ChessPiece* dummyPiece;
    dummyPiece=new Queen(_white);
    for (char i='A'; i<='H';i++){
        for (char j='1'; j<='8';j++){
            
            char position[3];
            position[0]=i;
            position[1]=j;
            position[2]='\0';
            if(board->at(position)!=NULL){
                continue;
            }else{
                board->at(position)=dummyPiece;
                
                if(isGameInChecked(_white, board)){
                    board->at(position)=NULL;
                    continue;
                }else{
                    
                    board->at(position)=NULL;
                    if(isPossibleMove_notking(_white,position, board)){
                        delete dummyPiece;
                        return 0;
                    }else{
                        continue;
                    }
                }
            }
        }
    }
    delete dummyPiece;
    return 1;
}



void ChessBoard::output_capture_move(string s_sq, string d_sq, map<string, ChessPiece*>* board){
    
    string color_s;
    if(board->at(s_sq)->iswhite()){
        color_s="White's";
    }else{
        color_s="Black's";
    }
    string color_d;
    if(board->at(d_sq)->iswhite()){
        color_d="White's";
    }else{
        color_d="Black's";
    }
    string source=board->at(s_sq)->name();
    string dest=board->at(d_sq)->name();
    
    cout<<color_s<<" "<<source<<" moves from "<<s_sq<<" to "<<d_sq<<" taking ";
    cout<<color_d<<" "<<dest<<endl;
    return;
    
}


void ChessBoard::output_valid_move(string s_sq, string d_sq, map<string, ChessPiece*>* board){
    
    string color_s;

    if(board->at(s_sq)->iswhite()){
        color_s="White's";
    }else{
        color_s="Black's";
    }

    string source=board->at(s_sq)->name();
    
    cout<<color_s<<" "<<source<<" moves from "<<s_sq<<" to "<<d_sq<<endl;
    return;
    
}


void ChessBoard::output_invalid_move(string s_sq, string d_sq, map<string, ChessPiece*>* board){
    
    string color_s;
    if(board->at(s_sq)->iswhite()){
        color_s="White's";
    }else{
        color_s="Black's";
    }
    
    string source=board->at(s_sq)->name();
    
    cout<<color_s<<" "<<source<<" cannot move to "<<d_sq<<endl;
    return;
    
}


