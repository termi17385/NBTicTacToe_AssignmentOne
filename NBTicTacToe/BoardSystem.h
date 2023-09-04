#pragma once
#include"Board.h"

#include <string>

struct Coordinate
{
	int x = 0;
	int y = 0;
};

const int BOARDSIZE = 9;
class BoardSystem
{
private:
	Board boards[BOARDSIZE][BOARDSIZE];
	Coordinate selectedBoard;
	int calculatePosition(int, int);
	bool checkXY(int x, int y);
	void displayBar(int _x);
	void displayDivider(int _x);

public:
	Board currentBoard;
	const int size = 9;
	void displayBoards();
	void select(int, int);
	BoardSystem(int x, int y)
	{
		selectedBoard.x = x;
		selectedBoard.y = y;
	}
};