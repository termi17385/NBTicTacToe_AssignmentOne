#include <ctime>
#include <iostream>
#include "Coordinate.h"
#include "NBGame.h"

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
	NBGAME::NBGame game(startCoordinate);
	game.play();
}

int main() { runGame(); }