#pragma once
#include "TicTacToe.h"

#ifndef NBTICTACTOE_H
#define NBTICTACTOE_H

class NBTicTacToe
{
private:

	TicTacToe boards[BOARDSIZE][BOARDSIZE];
	Coordinate currentBoard;

	bool validateCurrentBoard(Coordinate); 
	void displayBarsOrDividers(int, bool _isDivider = false);
	void displayPlayerOnBoard(Coordinate, int, int);

	void displayBoards();
	void displayCells(int, int, int&, bool);
	void displayCell(Coordinate, bool, int, int);

public:

	TicTacToe* getBoard(Coordinate _gridCoords);
	void setCurrentBoard(Coordinate _currentBoard);
	bool isBoardFull(Coordinate _currentBoard);
	void displayNBTicTacToe();
};

#endif