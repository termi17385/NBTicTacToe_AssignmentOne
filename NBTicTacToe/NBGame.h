#pragma once

#ifndef NBGAME_H
#define NBGAME_H

#include "Coordinate.h"
#include "NBTicTacToe.h"

namespace NBG
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
		Coordinate currentBoard;
		NBTicTacToe nbTicTacToe;

		GameState currentGameState = IsPlaying;
		int amountOfFullBoards = 0;

		bool allBoardsFull();
		void determineWinner(int);

	public:
		NBGame(Coordinate _startingBoard)
		{
			currentBoard = _startingBoard;
			nbTicTacToe.setCurrentBoard(_startingBoard);
		}
		void play();
	};
};

#endif