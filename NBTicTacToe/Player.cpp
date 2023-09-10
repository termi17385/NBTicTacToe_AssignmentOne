#include "Player.h"

void Player::addMoveToBoard(TicTacToe* _board, Coordinate _cellCoordinate, int _player)
{
	_board->addMove(_cellCoordinate.x, _cellCoordinate.y, _player);
}

char Player::getPlayerCharacter(int _cellValue)
{
	return _cellValue == 1 ? 'X' : (_cellValue == -1 ? 'O' : ' ');
}
