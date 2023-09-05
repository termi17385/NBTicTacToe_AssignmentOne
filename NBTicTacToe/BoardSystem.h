#pragma once
#include"Board.h"

#include <string>

struct Coordinate
{
	int x = 0;
	int y = 0;

	Coordinate() : x(0), y(0) {} // Default constructor

	Coordinate(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

const int BOARDSIZE = 9;
class BoardSystem
{
private:
	
	Board boards[BOARDSIZE][BOARDSIZE];
	Coordinate currentBoard;
	
	int calculateYPosition(int, int);
	bool checkXY(int x, int y);
	void displayBarsOrDividers(int _x, bool _isDivider);
	
	bool debug = false;

public:
	void displayBoards();
	void boardSelection(int, int);
	
	BoardSystem(int x, int y, bool _debug)
	{
		currentBoard = Coordinate(x,y);
		debug = _debug;
	}
};