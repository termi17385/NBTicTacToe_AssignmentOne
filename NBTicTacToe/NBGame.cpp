#include "NBGame.h"
const int MAXMOVES = 9;

namespace NBG
{
	void NBGame::play()
	{
		int player = 1;
		int winningPlayer = 0;
		Coordinate movePosition(0, 0);

		do
		{
			// handle movement first
			TicTacToe* Board = nbTicTacToe.getBoard(movePosition);

		} while (true);
	}

	bool NBGame::allBoardsFull()
	{
		return amountOfFullBoards >= MAXMOVES;
	}

	void NBGame::determineWinner(int)
	{

	}
};