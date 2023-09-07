#pragma once

#ifndef NBTICTACTOE_H
#define NBTICTACTOE_H

#include "TicTacToe.h"
#include "Coordinate.h"

class NBTicTacToe
{
private:

	TicTacToe grid[BOARDSIZE][BOARDSIZE];
	Coordinate currentBoard;

	int calculateYPosition(int, int);
	bool validateCurrentBoard(Coordinate); 
	void displayBarsOrDividers(int, bool _isDivider = false);
	void displayPlayerOnBoard(Coordinate, int, int);


	void displayBoards();
	void displayCells(int, int, int&, int, bool, Coordinate&);

public:

	TicTacToe* getBoard(Coordinate _gridCoords);
	void setCurrentBoard(Coordinate _currentBoard);
	bool isBoardFull(Coordinate _currentBoard);
	void displayNBTicTacToe();
};

#endif