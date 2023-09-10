#pragma once

#ifndef NBGAME_H
#define NBGAME_H

#include "Coordinate.h"
#include "NBTicTacToe.h"
#include "Player.h"

#include "HumanPlayer.h"
#include "RandomPlayer.h"

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

		Coordinate handleLevelChange(int&, Coordinate);
		GameState currentGameState = IsPlaying;
		int amountOfFullBoards = 0;

		bool allBoardsFull();
		void updateGameState(int&);
		bool checkGameState();

		bool randomX = false;
		bool randomO = false;
		bool randomBoth = false;

		int determinePlayer(int);


	public:
		NBGame(Coordinate _startingBoard, bool _x, bool _o, bool _both)
		{
			players[0] = new HumanPlayer();
			players[1] = new RandomPlayer();

			nb_currentBoard = _startingBoard;
			nbTicTacToe.setCurrentBoard(_startingBoard);

			if (_both)
			{
				randomBoth = _both;
				return;
			}

			randomX = _x;
			randomO = _o;
		} 
		void play();
	};
}
void displayWinner(NBGAME::GameState _state, int _winningPlayer);
#endif
