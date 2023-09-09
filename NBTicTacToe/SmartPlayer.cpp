#include "SmartPlayer.h"

void SmartPlayer::processMove(Coordinate& _movePosition, TicTacToe* _board, int)
{
	bool canMove = false;

	do
	{
		
		checkCurrentBoard(*_board, _movePosition);
	} while (!canMove);
}

bool SmartPlayer::checkCurrentBoard(TicTacToe& _board, Coordinate& _movePosition)
{
	TicTacToe _boardCopy = _board;

	// Need to scan the board look for any positions that might be a possible win
	// Compare the possible win with the player int, to determine if its our win or an enemy win
	// Store that position if its an enemy win, or win.

	// Check if there is any other positions that might be a win then check if that position leads to a winning board
	// if it leads to a winning board avoid that board no matter who is winning, as either the enemy wins or blocks our win

	return false;
}
