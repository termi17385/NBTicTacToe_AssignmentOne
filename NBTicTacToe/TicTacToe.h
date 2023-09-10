#pragma once

const int BOARDSIZE = 3;
#include<string>

class TicTacToe
{
private:
	int noOfMoves;								// how many moves the players have made in total
	int cells[BOARDSIZE][BOARDSIZE];			// An array for the board with declared size

	int checkRows();
	int checkColumns();
	int checkDiagonals();

public:

	void addMove(int, int, int);
	int getMove(int, int);

	bool isValidMove(int, int);
	int getNoOfMoves();

	int gameStatus();
	bool t_isBoardFull();

	TicTacToe();
};