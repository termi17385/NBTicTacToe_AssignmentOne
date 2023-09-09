#pragma once
#include "Player.h"
#include "NBTicTacToe.h"
class SmartPlayer : public Player
{
	// Inherited via Player
	void processMove(Coordinate&, TicTacToe*, int) override;

private:
	NBTicTacToe nbTicTacToe;
	bool checkCurrentBoard(TicTacToe&, Coordinate&);
public:

	SmartPlayer(NBTicTacToe _nbttt)
	{
		nbTicTacToe = _nbttt;
	}
};

