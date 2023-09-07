#pragma once
#include "TicTacToe.h"

struct Coordinate
{
	int x = 0;
	int y = 0;

	Coordinate() : x(0), y(0) {} // Default constructor

	Coordinate(int _x, int _y)
	{
		this->x = _x;
		this->y = _y;
	}	

	bool operator==(const Coordinate& _other) const
	{
		return (x == _other.x && y == _other.y);
	}
};

// Used to simplify determining the game state
enum GameState
{
	IsPlaying = 0,
	GameOver = 1,
	GameDrawn = 2
};

class NBTicTacToe
{
public:
	// Constructor and play
	NBTicTacToe(int _x, int _y)
	{
		currentBoard = Coordinate(_x,_y);
	
		currentState = IsPlaying;
		fullBoards = 0;
	}
	void play();

private:

	// Game Status
	bool isBoardFull(Coordinate _cBoard);
	GameState currentState = IsPlaying;
	int fullBoards = 0;
	void determineWinner(int);

	// Player Methods
	void getXMove(int&, int&);
	void getOMove(int&, int&);
	void processMove(int&, int&, int&);

	// Board Methods
	TicTacToe grid[BOARDSIZE][BOARDSIZE];
	Coordinate currentBoard;

	// Display Methods
	int calculateYPosition(int, int);
	bool checkXY(Coordinate);
	void displayBarsOrDividers(int, bool _isDivider = false);
	void displayBoards();
	void displayCells(int, int, int&, int, bool, Coordinate&);
	void displayPlayerOnBoard(Coordinate, int, int);
};