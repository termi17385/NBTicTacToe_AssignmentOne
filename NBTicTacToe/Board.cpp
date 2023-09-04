#include "Board.h"
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int Board::getBoardValue(int x, int y)
{
	return board[x][y];
}

void Board::randomizeBoardValues()
{
    // Seed the random number generator once at the beginning of your program
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(nullptr)));
        seeded = true;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Generate either -1 or 1
            int value = (rand() % 2 == 0) ? 1 : -1;
            board[i][j] = value;
        }
    }
}
