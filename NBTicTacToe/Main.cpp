#include <ctime>
#include <iostream>
#include "Coordinate.h"
#include "NBGame.h"

using namespace std;

Coordinate getRandomStartingPoint()
{
	srand(time(NULL));
	int randX = rand() % 3;
	int randY = rand() % 3;
	return Coordinate(randX, randY);
}

void runGame()
{
	bool x;
	bool o;
	bool both;

	cout << "Please select who you want the random player to be!\n\n"
		 << "{X}: Makes Crosses be random controlled\n"
		 << "{O]: Makes Naughts be random controlled\n"
		 << "{B}: Makes them both random controlled\n"
		 << "{N}: Makes non of them random controlled\n\n"
		 << "Input your answer here: ";

	char ans;
	cin >> ans;

	x = ans == 'X';
	o = ans == 'O';
	both = ans == 'B';

	Coordinate startCoordinate = getRandomStartingPoint();
	NBGAME::NBGame game(startCoordinate, x, o, both);
	game.initialisePlayers();
	game.play();
}

int main() { runGame(); }