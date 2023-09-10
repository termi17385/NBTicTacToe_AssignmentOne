#include <ctime>
#include <iostream>
#include "Coordinate.h"
#include "NBGame.h"

using namespace std;

/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from
any other student’s work or from any other source. No part of the
code has been written/produced for me by another person or copied
from any other source.

I hold a copy of this assignment that I can produce if the original
is lost or damaged.
**************************/

const int MAXITERATIONS = 10;

Coordinate getRandomStartingPoint()
{
	srand(time(NULL));
	int randX = rand() % 3;
	int randY = rand() % 3;
	return Coordinate(randX, randY);
}

int runGame(NBGAME::NBGame& _game, bool _debug = false)
{
	int ans = -1;
	if (!_debug)
	{
		cout << "Please select who you want the random player to be!\n\n"
			<< "{0]: Smart(x) vs Player(x)\n"
			<< "{1}: Smart(x) vs Random(o)\n"
			<< "{2}: Smart vs Smart\n"
			<< "{3}: Random vs Random\n"
			<< "{4}: Player(x) vs Player(o)\n\n"
			<< "Input your answer here: ";

		cin >> ans;
	}
	else ans = 1;
	
	_game = NBGAME::NBGame(getRandomStartingPoint(), ans);
	_game.play();

	return _game.xWinCounter;
}

int main() 
{ 
	char ans;
	cout << "Do you want to run test for Smart Player?(Y/N): ";
	cin >> ans;

	NBGAME::NBGame game{};

	int x_wins = 0;
	if (ans == 'Y' || ans == 'y')
	{
		for (int i = 0; i < MAXITERATIONS; i++)
		{
			x_wins = x_wins + runGame(game, true);
		}

		cout << endl << (x_wins / MAXITERATIONS) * 100 << "% Smart Player Win chance" << endl;
	}
	else runGame(game);
}