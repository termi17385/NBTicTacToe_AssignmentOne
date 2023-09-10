#include "RandomPlayer.h"
#include <iostream>
#include <ctime>

void RandomPlayer::processMove(Coordinate& _movePosition, TicTacToe* _board, int _cellValue)
{
	char p = getPlayerCharacter(_cellValue);

	int x = 0;
	int y = 0;

	srand(time(NULL));

	std::cout << std::endl << "Player: " << p << "'s move. Please enter a coord (X Y): ";

	do
	{
		x = rand() % 3;
		y = rand() % 3;
	} 
	while (!_board->isValidMove(x, y));
	_movePosition = Coordinate(x, y);

	addMoveToBoard(_board, _movePosition, _cellValue);
}
