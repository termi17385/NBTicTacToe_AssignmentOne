#pragma once
#include "Coordinate.h"
#include "TicTacToe.h"

class Player
{
public:
	virtual void processMove(Coordinate&, TicTacToe*, int) = 0;
protected:
	void addMoveToBoard(TicTacToe*, Coordinate, int);
	char getPlayerCharacter(int);
};