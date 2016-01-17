#ifndef SUDOKU_H
#define SUDOKU_H

void load_board(const char *filename, char board[9][9]);
void display_board(const char board[9][9]);



/* The following program will have input char board[9][9] as input with boolean output if all entries on the board are filled by a digit.*/
/* Remark: is_complete does not check whether the locations of the digits correct or not according rule of Sudoku.*/
bool is_complete(char board[9][9]);



/* This program will try to put in the digit(input) into the position(input) on board(input) and verify whether the input action*/
/* violates the rule of Sudoku or not. If it does have conflicts with the rule of Sudoku, the boolean function will return false and */
/* board will not be updated; in the other case, the boolean function will return true and board will be updated with the new input onto the board.*/
/* As 2D arrays are passed by reference, the update in the board within the program will also be effective in the main program. */
bool make_move(char position [3], char digit, char board[9][9]);



/* The following program will have 2 input arguments: const char *filename, char board[9][9]*/
/* save_board will take in the board(input) and output as a file with (char *filename).*/
/* If the board has been successfully saved, it will return true to the system; otherwise, false.*/
bool save_board(const char *filename, char board[9][9]);



/* The following program will have 1 input: char board[9][9] which represent the board that we are trying to solve*/
/* If the board is solvable, it will return True to the system and update the board as the completed and valid solution to the original input board.*/
bool solve_board(char board[9][9]);



/* The following program could solve any sudoku problem given the board. It also has a variable pass-by-reference to */
/* show the number of guesses (count_1) and we have made given that we make our guesses from 1 to 9. */
bool solve_board_1_9(char board[9][9],int &count_1);

#endif
