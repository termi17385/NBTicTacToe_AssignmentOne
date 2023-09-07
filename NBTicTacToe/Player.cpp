#include "Player.h"

	char Player::getPlayerCharacter(int _cellValue)
	{
		return _cellValue == 1 ? 'X' : (_cellValue == -1 ? 'O' : ' ');
	}
