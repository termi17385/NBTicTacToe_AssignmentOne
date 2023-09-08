#pragma once
#include "Player.h"

class HumanPlayer : public Player
{
	// Inherited via Player
public:
	void processMove(Coordinate&, TicTacToe*, int) override;
};

