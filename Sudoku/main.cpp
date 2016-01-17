/*
File name: Main.cpp
Author: Yau Ho Man
Coursework: MSc C++ Programming Assessment 1
Program last changed: 2 November 2015
*/

/*
This main program will be able to solve sudoku by trial and error. 
*/


#include <iostream>
#include <cstdio>
#include "sudoku.h"

using namespace std;

int main() {

  char board[9][9];

  /* This section illustrates the use of the pre-supplied helper functions. */
  cout << "============== Pre-supplied functions ==================" << endl << endl;

  cout << "Calling load_board():" << endl;
  load_board("easy.dat", board);

  cout << endl << "Displaying Sudoku board with display_board():" << endl;
  display_board(board);
  cout << "Done!" << endl << endl;

  cout << "====================== Question 1 ======================" << endl << endl;

  load_board("easy.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << endl << endl;

  load_board("easy-solution.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << endl << endl;

  cout << "====================== Question 2 ======================" << endl << endl;

  load_board("easy.dat", board);

  // Should be OK
  cout << "Putting '1' into I8 is ";
  if (!make_move("I8", '1', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);

	// write more tests

  cout << "====================== Question 3 ======================" << endl << endl;

  load_board("easy.dat", board);
  if (save_board("easy-copy.dat", board))
    cout << "Save board to 'easy-copy.dat' successful." << endl;
  else
    cout << "Save board failed." << endl;
  cout << endl;

  cout << "====================== Question 4 ======================" << endl << endl;

  load_board("easy.dat", board);
  if (solve_board(board)) {
    cout << "The 'easy' board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;

  load_board("medium.dat", board);
  if (solve_board(board)) {
    cout << "The 'medium' board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;

  cout << "====================== Question 5 ======================" << endl << endl;

  load_board("mystery1.dat", board);

  int count_try_1=0;

  if (solve_board_1_9(board, count_try_1)) {
  
    cout << "The 'mystery1' board has a solution:" << endl;

    display_board(board);

    cout << "If we have our guess starting from 1 to 9, we will have "<< endl;
    cout <<count_try_1<<" trials." <<endl;
  
    } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;



  load_board("mystery2.dat", board);

  int count_try_2=0;

  if (solve_board_1_9(board, count_try_2)) {
   
    cout << "The 'mystery2' board has a solution:" << endl;

    display_board(board);

    cout << "If we have our guess starting from 1 to 9, we will have "<< endl;
    cout <<count_try_2<<" trials. "<<endl;

  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;



  load_board("mystery3.dat", board);

  int count_try_3=0;

  if (solve_board_1_9(board, count_try_3)) {
  
    cout << "The 'mystery3' board has a solution:" << endl;

    display_board(board);

    cout << "If we have our guess starting from 1 to 9, we will have "<< endl;
    cout <<count_try_3<<" trials. "<<endl;

  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;


  cout<< endl << ">>>>>>>>Program ended<<<<<<<<"<<endl<<endl;

  return 0;
}
