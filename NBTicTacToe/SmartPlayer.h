#pragma once
#include "Player.h"
#include "NBTicTacToe.h"
class SmartPlayer : public Player
{
	// Inherited via Player
	void processMove(Coordinate&, TicTacToe*, int) override;

private:
	NBTicTacToe nbTicTacToe;
	bool checkCurrentBoard(TicTacToe&, Coordinate&, int);
	bool checkNextBoard(Coordinate&);

	Coordinate checkRows(TicTacToe, int, bool&);
	Coordinate checkColumns(TicTacToe, int, bool&);
	Coordinate checkDiagonals(TicTacToe, int, bool&);

public:
	SmartPlayer(NBTicTacToe _nbttt)
	{
		nbTicTacToe = _nbttt;
	}
};

