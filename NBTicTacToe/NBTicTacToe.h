#pragma once
#include "TicTacToe.h"

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
	NBTicTacToe(int x, int y)
	{
		currentBoard = Coordinate(x,y);
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
	char getPlayerForCell(Coordinate cell, Coordinate board);

	// Board Methods
	TicTacToe grid[3][3];
	Coordinate currentBoard;
	TicTacToe getBoard(Coordinate _boardCoords);
	void displayBoards();
};