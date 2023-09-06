#include "NBTicTacToe.h"
#include <ctime>
#include <iostream>

int main()
{
	srand(time(NULL));
	//TicTacToe game;

	NBTicTacToe game((int)rand % 3, (int)rand % 3);
	game.play();
	//game.displayBoards();

	return 0;
}