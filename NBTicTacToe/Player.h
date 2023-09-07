#pragma once
#include "Coordinate.h"
#include "TicTacToe.h"

class Player
{
public:
	virtual char processMove(Coordinate&, TicTacToe*, int) = 0;
protected:
	char getPlayerCharacter(int);
};