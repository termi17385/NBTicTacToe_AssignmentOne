#include "Coordinate.h"
#include "NBGame.h"

#include "Player.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"

#include <iostream>


const int MAXMOVES = 9;

void NBGAME::NBGame::initialisePlayers()
{
	players[0] = new HumanPlayer();
	players[1] = new RandomPlayer();
}

void NBGAME::NBGame::play()
{
	int player = 1;
	int winningPlayer = 0;
	Coordinate movePosition(0, 0);

	do
	{
		// handle movement first
		TicTacToe* board = nbTicTacToe.getBoard(movePosition);


	} while (true);
}

bool NBGAME::NBGame::allBoardsFull()
{
	return amountOfFullBoards >= MAXMOVES;
}

void NBGAME::NBGame::determineWinner(int)
{
	
}


