/**
	@file sudoku.cpp
*/
#include <iostream>
#include <string>
#include <stdexcept>

#include <stdlib.h> // for atoi

using namespace std;

#include "sudoku.h"

/**********************
***********************
**  PUBLIC METHODS   **
***********************
**********************/

bool Sudoku::solve()
{
  if(solved())
      return true;
    
  
  for(int row_num=0;row_num<9;row_num++) {
    for(int col_num=0;col_num<9;col_num++) {
      if(board[col_num + 9*row_num] == 0) {
        //col_num + 9*row_num = cell working are in
        for(int i=0;i<9;i++) {
          if(allowed(col_num, row_num, i+1)) {
            //cout << "allowed value of " << (i+1) << " at index " << (col_num + 9*row_num) << endl;
            board[col_num + 9*row_num] = (i+1);
            if(solve()) { return true; }
          } //end if allowed
          if(i == 8) { // no solution exists for this route
            board[col_num + 9*row_num] = 0;
            //cout << "BACKTRACK index " << (col_num + 9*row_num) << " has reached 9" << endl;
            return false;
          } //end if i == 8
        } //end for value
      } //end if == 0
    } //end for columns
	} //end for rows
	
  return false;
}



void Sudoku::printBoards(ostream& os)
{
	printBoard(orig_board, "   Original Puzzle", os);
  os << endl << endl;
	printBoard(board, "   Solved Puzzle", os);
}


void Sudoku::insertLine(string line, int row_num)
{
	if(row_num > 9 or row_num < 0)
		throw out_of_range("Too Many Lines");
	
  int temp_int;
  char temp_char;
	
	for(int i=0;i<9;i++) {
	  if(line[i] == '_')
        line[i] = '0';
    
    temp_char = line[i];    
    temp_int  = atoi(&temp_char);
    
		board[i + 9*row_num]      = temp_int;
		orig_board[i + 9*row_num] = temp_int;
	}
}


/**********************
***********************
**  PRIVATE METHODS  **
***********************
**********************/

bool Sudoku::allowed(int col_num, int row_num, int value) const
{
  return check_rows_and_columns(col_num, row_num, value) && check_3_x_3(col_num, row_num, value);
}

    bool Sudoku::check_rows_and_columns(int col_num, int row_num, int value) const
    {
      for(int i=0;i<9;i++) {
        //check row
        if((board[i + 9*row_num] == value) && (i != col_num)) { //if square value != value and not the col working in
          return false;
        } //end if

        //check col
        if((board[col_num + 9*i] == value) && (i != row_num)) { //if square value != value and not the row working in
          return false;
        }
      } //end for
      
      return true;
    }
    
    bool Sudoku::check_3_x_3(int col_num, int row_num, int value) const
    {
      //check square
      int corner_index  = 27*(row_num/3) + 3*(col_num / 3); //math magic
      for(int row_iter=0;row_iter < 20;row_iter=row_iter+9) {
        for(int col_iter=0;col_iter<3;col_iter++) {
          if(board[corner_index + row_iter + col_iter] == value) {
            return false;
          } //end if == value
        } //end for col_iter
      } //end for row_iter
      
      return true;
    }

bool Sudoku::locked(int index) const
{
  if(board[index] == 0)
      return false;
  return orig_board[index] == board[index];
}

bool Sudoku::solved() const
{
  for(int i=0;i<81;i++)
  {
    if(board[i]==0)
      return false;
  }
  return true;
}

void Sudoku::printBoard(int temp_board[], string title, ostream& os)
{
		os << "\t\t" << title << endl;
		
		for(int i=0;i<81;i++) {
			if(i % 9 == 0)
				os << "|-----|-----|-----|-----|-----|-----|-----|-----|-----|" << endl << "|"; //add bar across top of row and first bar at beginning of line
				
			if(temp_board[i] == 0)
  			  os << "     |";
			else
    			os << "  " <<  temp_board[i] << "  |";
			
			if((i+1) % 9 == 0)
				os << endl; //add line return at end of line
		}
		os << "|-----|-----|-----|-----|-----|-----|-----|-----|-----|" << endl;
}