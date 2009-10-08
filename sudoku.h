#ifndef SUDOKU_H
#define SUDOKU_H

class Sudoku
{

  private:
  	int board[81], orig_board[81];
  	
  	void printBoard(int temp_board[], string, ostream& os);
    bool locked(int) const;
    bool allowed(int, int, int) const;
        bool check_rows_and_columns(int, int, int) const;
        bool check_3_x_3(int, int, int) const;
    bool solved() const;

  public:
  	void insertLine(string, int);
  	void printBoards(ostream& os);
  	bool solve();

};

#endif
