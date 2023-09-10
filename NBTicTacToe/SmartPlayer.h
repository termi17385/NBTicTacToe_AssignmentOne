#pragma once
#include "Player.h"
#include "NBTicTacToe.h"

struct CellData
{
	int nextCell;
	int previousCell;

	CellData(int _nextCell, int _previousCell)
	{
		nextCell = _nextCell;
		previousCell = _previousCell;
	}

	CellData() = default;
};

class SmartPlayer : public Player
{
	// Inherited via Player
	void processMove(Coordinate&, TicTacToe*, int) override;

private:
	NBTicTacToe *nbTicTacToe;

	Coordinate potentialBlocksRows[9];
	Coordinate potentialBlocksColumns[9];

	CellData xCell;
	CellData yCell;

	void checkRowsAndColumns(Coordinate&, TicTacToe&, int, bool&, bool&);

	void randomMove(Coordinate&, TicTacToe&);

	void checkNextBoard(Coordinate&, int);

public:
	SmartPlayer(NBTicTacToe* _nbttt)
	{
		xCell = CellData{};
		yCell = CellData{};

		nbTicTacToe = _nbttt;
	}
};

