#pragma once

#ifndef NBGAME_H
#define NBGAME_H

#include "Coordinate.h"
#include "NBTicTacToe.h"
#include "Player.h"

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
		Player* players[3];

		Coordinate handleLevelChange(int&, Coordinate);
		GameState currentGameState = IsPlaying;
		int amountOfFullBoards = 0;

		bool allBoardsFull();
		void determineWinner(int&);
		bool checkGameState();

		bool randomX = false;
		bool randomO = false;
		bool randomBoth = false;

		int determinePlayer(int);
		void initialisePlayers();


	public:
		NBGame(Coordinate _startingBoard, bool _x, bool _o, bool _both)
		{
			nb_currentBoard = _startingBoard;
			nbTicTacToe.setCurrentBoard(_startingBoard);

			if (_both)
			{
				randomBoth = _both;
				return;
			}

			randomX = _x;
			randomO = _o;

			initialisePlayers();
		} 
		void play();
	};
}

#endif