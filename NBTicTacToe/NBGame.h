#pragma once

#ifndef NBGAME_H
#define NBGAME_H

#include "Coordinate.h"
#include "NBTicTacToe.h"

namespace NBGAME
{
	enum GameState
	{
		IsPlaying = 0,
		GameOver = 1,
		GameDrawn = 2
	};

	class NBGame
	{
	private:
		Coordinate nb_currentBoard;
		NBTicTacToe nbTicTacToe;
		Player* players[2];

		GameState currentGameState = IsPlaying;
		int amountOfFullBoards = 0;

		bool allBoardsFull();
		void determineWinner(int);

		void initialisePlayers();

	public:
		NBGame(Coordinate _startingBoard)
		{
			nb_currentBoard = _startingBoard;
			nbTicTacToe.setCurrentBoard(_startingBoard);
		}
		void play();
	};
}

#endif