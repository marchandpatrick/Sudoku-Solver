/**
	@file main.cpp
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

#include "sudoku.h"


/** client function for the sudoku class
* @param  none
* @pre    none
* @post   the user has interacted with the sudoku class and used the command quit to exit
*/
int main(int argc, char* argv[])
{
  cout <<
  "\t               _       _  ___    _ " << endl <<
  "\t              | |     | |/ / |  | | " << endl <<
  "\t ___ _   _  __| | ___ | ' /| |  | | " << endl <<
  "\t/ __| | | |/ _` |/ _ \\|  < | |  | | " << endl <<
  "\t\\__ \\ |_| | (_| | (_) | . \\| |__| |" << endl <<
  "\t|___/\\__,_|\\__,_|\\___/|_|\\_\\_____/ v 1.0" << endl << endl << endl;
	
	Sudoku s;
	
	string line;
  ifstream puzzle (argv[1]);
  if (puzzle.is_open())
  {
  	int line_num = 0;
    while (puzzle.peek() != EOF)
    {
    	try {
		  	getline(puzzle, line);
		  	s.insertLine(line, line_num);
		  	line_num++;
    	}
    	catch(out_of_range) { cerr << "\tToo Many Lines" << endl; }
    }
    puzzle.close();
    if(s.solve()) { s.printBoards(cout); }
        else { cout << "\tThis puzzle can't be solved! :-(" << endl; }
  }
  else
      cout << "\tUnable to open puzzle file" << endl;

	return 0;
}
