#include "Coordinate.h"
#include "NBGame.h"

#include "HumanPlayer.h"
#include "RandomPlayer.h"
#include "SmartPlayer.h"

#include <iostream>

using namespace std;

const int MAXMOVES = 9;

void NBGAME::NBGame::initialisePlayers()
{
	players[0] = new HumanPlayer();
	players[1] = new RandomPlayer();
	players[2] = new SmartPlayer(nbTicTacToe);
}

Coordinate NBGAME::NBGame::handleLevelChange(int& _symbolBeingPlayed, Coordinate _newCurrentBoard)
{
	_symbolBeingPlayed = _symbolBeingPlayed ==  1 ? -1 : 1;
	nbTicTacToe.setCurrentBoard(_newCurrentBoard);
	return _newCurrentBoard;
}

bool NBGAME::NBGame::checkGameState()
{
	return currentGameState == IsPlaying;
}

int NBGAME::NBGame::determinePlayer(int _currentSymbol)
{
	if (randomBoth) return 1;
	else if (_currentSymbol == 1 && randomX) return 1;
	else if (_currentSymbol == -1 && randomO) return 1;
	else return 0;
}

void displayWinConditionInformation(NBGAME::GameState _state, int _winningPlayer)
{
	char winningChar = _winningPlayer == 1 ? 'X' : 'O';
	if (_state == NBGAME::GameOver) cout << "The winner is {" << winningChar << "}!!";
	else if (_state == NBGAME::GameDrawn) cout << "The Game was a Draw!";
}

void NBGAME::NBGame::play()
{
	int symbolBeingPlayed = 1;
	Coordinate movePosition(0, 0);

	int winner = 0;

	do
	{
		TicTacToe* board = nbTicTacToe.getBoard(nb_currentBoard);
		
		players[determinePlayer(symbolBeingPlayed)]->processMove(movePosition, board, symbolBeingPlayed);

		determineWinner(winner);

		nb_currentBoard = handleLevelChange(symbolBeingPlayed, movePosition);
		
		cout << endl << endl;

		nbTicTacToe.displayNBTicTacToe();
	} 
	while (checkGameState());

	displayWinConditionInformation(currentGameState, winner);
}

bool NBGAME::NBGame::allBoardsFull()
{
	return amountOfFullBoards >= MAXMOVES;
}

void NBGAME::NBGame::determineWinner(int& _winningPlayer)
{
	TicTacToe* _board = nbTicTacToe.getBoard(nb_currentBoard);
	int result = _board->gameStatus();

	if (result == 1 || result == -1)
	{
		currentGameState = GameOver;
		_winningPlayer = result;
		return;
	}

	else if (result == 2)
	{
		currentGameState = GameDrawn;
		return;
	}
}