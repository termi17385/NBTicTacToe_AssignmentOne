/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from
any other student’s work or from any other source. No part of the
code has been written/produced for me by another person or copied
from any other source.

I hold a copy of this assignment that I can produce if the original
is lost or damaged.
**************************/

#include <ctime>
#include <iostream>
#include "Coordinate.h"
#include "NBGame.h"

// Done: [x] Not Done: [ ]
// 
// TODO: [x] code needs to be cleaned up with better decomposition
// TODO: [x] next is to implement NBGame and other abstractions
// TODO: [x] need a player class that can be inherited for each player type
// TODO: [x] split logic flow into correct classes

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

	cout << "Please select who you want the random player to be! Must be Upper Case!\n\n"
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
	game.play();
}
int main() { runGame(); }