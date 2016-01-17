/*
File name: sudoku.cpp
Author: Yau Ho Man
Coursework: MSc C++ Programming Assessment 1
Program last changed: 2 November 2015
*/

/*
This is the implementation file for supporting the main program. 
*/

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "sudoku.h"

using namespace std;
/* You are pre-supplied with the functions below. Add your own
 function definitions to the end of this file. */

/* pre-supplied function to load a Sudoku board from a file */
void load_board(const char *filename, char board[9][9]) {
    
    cout << "Loading Sudoku board from file '" << filename << "'... ";
    
    ifstream in(filename);
    if (!in)
        cout << "Failed!" << endl;
    assert(in);
    
    char buffer[512];
    
    int row = 0;
    in.getline(buffer,512);
    while (in && row < 9) {
        for (int n=0; n<9; n++) {
            assert(buffer[n] == '.' || isdigit(buffer[n]));
            board[row][n] = buffer[n];
        }
        row++;
        in.getline(buffer,512);
    }
    
    cout << ((row == 9) ? "Success!" : "Failed!") << endl;
    assert(row == 9);
}

/* internal helper function */
void print_frame(int row) {
    if (!(row % 3))
        cout << "  +===========+===========+===========+" << endl;
    else
        cout << "  +---+---+---+---+---+---+---+---+---+" << endl;
}

/* internal helper function */
void print_row(const char *data, int row) {
    cout << (char) ('A' + row) << " ";
    for (int i=0; i<9; i++) {
        cout << ( (i % 3) ? ':' : '|' ) << " ";
        cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
    }
    cout << "|" << endl;
}

/* pre-supplied function to display a Sudoku board */
void display_board(const char board[9][9]) {
    cout << "    ";
    for (int r=0; r<9; r++)
        cout << (char) ('1'+r) << "   ";
    cout << endl;
    for (int r=0; r<9; r++) {
        print_frame(r);
        print_row(board[r],r);
    }
    print_frame(9);
}

/* add your functions here */

/* Question 1 */

bool is_complete(char board[9][9]){
    
    for(int i=1;i<=9;i++){

        for (int j=1; j<=9; j++){

            if(board[i-1][j-1]>'9'||board[i-1][j-1]<'1'){
                return false;
            }

        }

    }

    return true;
}

/* Question 2 */

bool make_move(char position[3] , char digit, char board[9][9]){

    // row and col starts from 0
    int row_try=position[0]-65;
    int col_try=position[1]-49;

    // check whether the input of position[3] valid on our grid system or not
    if (row_try>8||row_try<0){
        return false;
    }
    if (col_try>8||col_try<0){
        return false;
    }

    // check if there is the same digit in same row or column after we input the digit(input) into the position(input)
    for (int row_1=0;row_1<=8; row_1++){

        if (board[row_1][col_try]==digit){
            return false;
        }

    }

    for (int col_1=0;col_1<=8; col_1++){

      if (board[row_try][col_1]==digit){
            return false;
        }

    }
    
    
    // check within the subboard whether any digits clash
    for (int row_2=row_try-row_try%3; row_2<=row_try-row_try%3+2; row_2++){

      for(int col_2=col_try-col_try%3; col_2<=col_try-col_try%3+2; col_2++){

            if (board[row_2][col_2]==digit){
                return false;
            }

        }

    }

    // If the new input digit at the given position on the board does not conflict with the rule of Sudoku, we will update the board with the new input digit.
    board[row_try][col_try]=digit;
    
    // return true as output to show the input of the digit at the given position is valid and board has been updated
    return true;
}


/* Question 3*/

bool save_board(const char *filename, char board[9][9]){

    ofstream out(filename);

    //check whether we have opened the ofstream file
    if(out.fail()){
        return false;
    }

    //copy the board to the output file
    for (int row_1=1;row_1<=9; row_1++){

        for(int col_1=1; col_1<=9; col_1++){

            out<<board[row_1-1][col_1-1];
        }

        out<<endl;
    }
    
    //close the output file
    out.close();

    //return true after the process
    return true;
}


/* Question 4*/

bool solve_board(char board[9][9]){

  // define variable
  char position[3];

  // check if the board is already completed
  if(is_complete(board)){
    return 1;
  }

  // searching by row to get to an empty entry on the board
  for(int row=0;row<=8;row++){

    for(int col=0;col<=8;col++){
      
      //Assign variables
      position[0]=row+65;
      position[1]=col+49;
 
      //If we encounter an empty entry on the board
      if(board[row][col]=='.'){
	
	//we try to input digit from 1 to 9 into the empty entry and check whether it is a valid input
	for(char digit='1';digit<='9';digit++){
	  
	  //if it is a valid input, we update the board with that input and recursively use the same program 
	  //to solve the updated board
	  if(make_move(position,digit,board)){
	    
	    //if the board is solved, return 1
	    if(solve_board(board)){
		return 1;
	    }
	    
	    //if the board is not solved, which means the (guess) input was wrong, we turn it back to '.'
	    board[row][col]='.';
	  }

        }

	//if there is no digits that can produce a valid solution at this position, we will send back 0 to notify
	//that there is an error somewhere before this digit which is not valid.
	return 0;
      }

    }

  }

  return 0;
}



/* Question 5*/

bool solve_board_1_9(char board[9][9],int &count_try){
  char position[3];
  
  if(is_complete(board)){
    return 1;
  }
  
  for(int row=0;row<=8;row++){

    for(int col=0;col<=8;col++){

      position[0]=row+65;
      position[1]=col+49;     

     if(board[row][col]=='.'){

	for(char digit='1';digit<='9';digit++){

	  if(make_move(position,digit,board)){
	    count_try=count_try+1;	     
	    if(solve_board_1_9(board,count_try)){
		return 1;
	    }

	      board[row][col]='.';
	    
	  
	  }
	
	}

	return 0;
     }

    }

  }

  return 0;
}
