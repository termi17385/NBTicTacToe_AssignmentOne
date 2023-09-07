#pragma once
#include "Player.h"
class RandomPlayer : public Player
{
	// Inherited via Player
	char processMove(Coordinate&, TicTacToe*, int) override;
};

