#pragma once
#include "Player.h"

class HumanPlayer : public Player
{
	// Inherited via Player
public:
	char processMove(Coordinate&, TicTacToe*, int) override;
};

