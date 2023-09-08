#pragma once
#include "Player.h"
class RandomPlayer : public Player
{
	// Inherited via Player
	void processMove(Coordinate&, TicTacToe*, int) override;
};

