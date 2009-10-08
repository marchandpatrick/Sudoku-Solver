CC = g++
CFLAGS = -g -Wall
OBJS = sudoku.o main.o

all:	$(OBJS)
	$(CC) $(OBJS) -o Sudoku

main.o: main.cpp sudoku.h
	$(CC) $(CFLAGS) -c main.cpp

sudoku.o:	sudoku.cpp	sudoku.h
	$(CC) $(CFLAGS) -c sudoku.cpp

clean:
	rm $(OBJS) Sudoku
