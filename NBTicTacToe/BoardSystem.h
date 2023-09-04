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
	Coordinate currentBoard;
	
	int calculateYPosition(int, int);
	bool checkXY(int x, int y);
	void displayBarsOrDividers(int, std::string, std::string);
	
	bool debug = false;

public:
	void displayBoards();
	void boardSelection(int, int);
	
	BoardSystem(int x, int y, bool _debug)
	{
		currentBoard.x = x;
		currentBoard.y = y;

		debug = _debug;
	}
};