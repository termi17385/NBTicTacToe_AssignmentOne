#pragma once

#ifndef NBGAME_H
#define NBGAME_H

#include "Coordinate.h"
#include "NBTicTacToe.h"
#include "Player.h"

#include "HumanPlayer.h"
#include "RandomPlayer.h"
#include "SmartPlayer.h"

namespace NBGAME
{
	enum PlayerSelect : int
	{
		SmartVPlayer = 0,
		SmartXRandO = 1,
		SmartVSmart = 2,
		RandomVRand = 3,
		BothPlayers = 4
	};

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
		NBTicTacToe* nbTicTacToe;
		Player* players[3];

		Coordinate handleLevelChange(int&, Coordinate);
		GameState currentGameState = IsPlaying;
		int amountOfFullBoards = 0;

		bool allBoardsFull();
		void determineWinner(int&);
		bool checkGameState();

		int naughtValue = -1;
		int crossValue = -1;

		int determinePlayer(int);
		void deletePointers();
		void selectGameMode(int);

	public:
		NBGame() = default;

		NBGame(Coordinate _startingBoard, int _gameMode)
		{
			nbTicTacToe = new NBTicTacToe;

			nbTicTacToe->setCurrentBoard(_startingBoard);

			nb_currentBoard = _startingBoard;
			
			players[0] = new HumanPlayer();
			players[1] = new RandomPlayer();
			players[2] = new SmartPlayer(nbTicTacToe);

			selectGameMode(_gameMode);
		} 
		void play();

		int xWinCounter = 0;
	};
}

#endif