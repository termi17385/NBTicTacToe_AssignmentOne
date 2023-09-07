#include "NBTicTacToe.h"
#include "NBGame.h"
#include <ctime>
#include <iostream>

Coordinate getRandomStartingPoint()
{
	srand(time(NULL));
	int randX = rand() % 3;
	int randY = rand() % 3;
	return Coordinate(randX, randY);
}

void runGame()
{
	Coordinate startCoordinate = getRandomStartingPoint();
	NBG::NBGame game(startCoordinate);
	game.play();
}

int main() { runGame(); }