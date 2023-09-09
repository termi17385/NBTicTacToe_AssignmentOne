#include "SmartPlayer.h"
#include <iostream>
using namespace std;

void SmartPlayer::processMove(Coordinate& _movePosition, TicTacToe* _board, int _cellValue)
{
	bool canMove = false;

	do
	{
		canMove = checkCurrentBoard(*_board, _movePosition, _cellValue);
	} while (!canMove);

	addMoveToBoard(_board, _movePosition, _cellValue);
}

bool SmartPlayer::checkCurrentBoard(TicTacToe& _board, Coordinate& _movePosition, int _player)
{
	TicTacToe _boardCopy = _board;

	// grab the avaliable positions for a placement
	Coordinate rowCoord;
	Coordinate colCoord;
	Coordinate diagCoord;

	bool winningSpot;

	cout << endl << endl << "Checking Rows";
	rowCoord = checkRows(_boardCopy, _player, winningSpot);
	if (winningSpot)
	{
		_movePosition = rowCoord;
		return true;
	}

	cout << endl << "Checking Columns";
	colCoord = checkColumns(_boardCopy, _player, winningSpot);
	if (winningSpot)
	{
		_movePosition = colCoord;
		return true;
	}

	cout << endl << "Checking Diagonals";
	diagCoord = checkDiagonals(_boardCopy, _player, winningSpot);
	if (winningSpot)
	{
		_movePosition = diagCoord;
		return true;
	}
	

	// Compare the possible win with the player int, to determine if its our win or an enemy win
	// Store that position if its an enemy win, or win.
	
	if (checkNextBoard(rowCoord))
	{
		_movePosition = rowCoord;
		return true;
	}

	if (checkNextBoard(colCoord))
	{
		_movePosition = colCoord;
		return true;
	}

	if (checkNextBoard(diagCoord))
	{
		_movePosition = diagCoord;
		return true;
	}

	return false;
}

bool SmartPlayer::checkNextBoard(Coordinate& _gridCoords)
{
	if (nbTicTacToe.getBoard(_gridCoords)->getNoOfMoves() <= 1) return true;
	// Check if there is any other positions that might be a win then check if that position leads to a winning board
	// if it leads to a winning board avoid that board no matter who is winning, as either the enemy wins or blocks our win

	return false;
}

Coordinate SmartPlayer::checkRows(TicTacToe _board, int _player, bool& _winSpotted)
{
	Coordinate coordToReturn;
	for (int i = 0; i < BOARDSIZE; i++)
	{
		int a = _board.getMove(i, 0);
		int b = _board.getMove(i, 1);
		int c = _board.getMove(i, 2);

		cout << endl << "Scanning rows: {" << 0 << "," << i << " " << 1 << "," << i << " " << 2 << "," << i << "}" << endl;

		// prioritise winning spots
		if (a == b && c == 0)
		{
			if (a != _player);
			{
				cout << endl << "Winning spot identified";
				_winSpotted = true;
				return Coordinate(i, 2);
			}
			
			coordToReturn = Coordinate(i, 2);
		}

		if (a == c && b == 0)
		{
			if (a != _player);
			{
				cout << endl << "Winning spot identified";
				_winSpotted = true;
				return Coordinate(i, 1);
			}

			coordToReturn = Coordinate(i, 1);
		}

		if (b == c && a == 0)
		{
			if (b != _player)
			{
				cout << endl << "Winning spot identified";
				_winSpotted = true;
				return Coordinate(i, 0);
			}

			coordToReturn = Coordinate(i, 0);
		}
	}
}

Coordinate SmartPlayer::checkColumns(TicTacToe _board, int _player, bool& _winSpotted)
{
	Coordinate coordToReturn;
	for (int i = 0; i < BOARDSIZE; i++)
	{
		int a = _board.getMove(0, i);
		int b = _board.getMove(1, i);
		int c = _board.getMove(2, i);
								  
		cout << endl << "Scanning rows: {" << i << "," << 0 << " " << i << "," << 1 << " " << i << "," << 2 << "}" << endl;

		// prioritise winning spots
		if (a == b && c == 0)
		{
			if (a != _player);
			{
				cout << endl << "Winning spot identified";
				_winSpotted = true;
				return Coordinate(2, i);
			}

			coordToReturn = Coordinate(2, i);
		}

		if (a == c && b == 0)
		{
			if (a != _player);
			{
				cout << endl << "Winning spot identified";
				_winSpotted = true;
				return Coordinate(1, i);
			}

			coordToReturn = Coordinate(1, i);
		}

		if (b == c && a == 0)
		{
			if (b != _player)
			{
				cout << endl << "Winning spot identified";
				_winSpotted = true;
				return Coordinate(0, i);
			}

			coordToReturn = Coordinate(0, i);
		}
	}
}

Coordinate SmartPlayer::checkDiagonals(TicTacToe, int _player, bool& _winSpotted)
{
	return Coordinate();
}
