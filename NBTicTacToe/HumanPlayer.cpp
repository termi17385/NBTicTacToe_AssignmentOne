#include "HumanPlayer.h"
#include <iostream>

char HumanPlayer::processMove(Coordinate& _movePosition, TicTacToe* _board, int _cellValue)
{
	char p = getPlayerCharacter(_cellValue);

	int x = 0;
	int y = 0;

	do
	{
		std::cout << std::endl << "Player: " << p << "'s move. Please enter a coord (X Y): ";
		std::cin >> x >> y;

	} 
	while (!_board->isValidMove(x, y));	
	_movePosition = Coordinate(x, y);
	return p;
}
