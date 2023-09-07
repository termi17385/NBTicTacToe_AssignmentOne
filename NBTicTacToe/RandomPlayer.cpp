#include "RandomPlayer.h"
#include <ctime>

char RandomPlayer::processMove(Coordinate& _movePosition, TicTacToe* _board, int _cellValue)
{
	char p = getPlayerCharacter(_cellValue);

	int x = 0;
	int y = 0;

	srand(time(NULL));

	do
	{
		x = rand() % 3;
		x = rand() % 3;
	} 
	while (!_board->isValidMove(x, y));
	_movePosition = Coordinate(x, y);
	return p;
}
