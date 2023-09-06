#pragma once

const int BOARDSIZE = 3;
#include<string>

class TicTacToe
{
private:
	int noOfMoves;								// how many moves the players have made in total
	int board[BOARDSIZE][BOARDSIZE];			// An array for the board with declared size

	// Game Status
	int checkRows();
	int checkColumns();
	int checkDiagonals();

public:

	// Moves
	void addMove(int, int, int);
	int getMove(int, int);

	// Move validation
	bool isValidMove(int, int);
	int getNoOfMoves();

	// Game Status
	int gameStatus();
	bool isBoardFull();

	TicTacToe();
	//std::string displayBoard();
};