#include "Coordinate.h"
#include "NBGame.h"
#include <iostream>

using namespace std;

const int MAXMOVES = 9;

Coordinate NBGAME::NBGame::handleLevelChange(int& _symbolBeingPlayed, Coordinate _newCurrentBoard)
{
	_symbolBeingPlayed = _symbolBeingPlayed ==  1 ? -1 : 1;
	Coordinate newBoard = _newCurrentBoard;

	if (nbTicTacToe->getBoard(newBoard)->t_isBoardFull())
	{
		srand(time(NULL));
		do
		{
			newBoard = Coordinate(rand()%3, rand()%3);
		} while (!nbTicTacToe->getBoard(newBoard)->t_isBoardFull());
	}

	nbTicTacToe->setCurrentBoard(newBoard);
	return newBoard;
}

bool NBGAME::NBGame::checkGameState()
{
	return currentGameState == IsPlaying;
}

int NBGAME::NBGame::determinePlayer(int _currentSymbol)
{
	if (_currentSymbol == 1) return crossValue;
	else return naughtValue;
}

void NBGAME::NBGame::deletePointers()
{
	delete nbTicTacToe;

	for (int i = 0; i < 3; i++)
	{
		delete players[i];
	}
}

void NBGAME::NBGame::selectGameMode(int _ans)
{
	PlayerSelect selection = (PlayerSelect)_ans;
	switch (selection)
	{
	case NBGAME::SmartVPlayer:
		naughtValue = 0;
		crossValue = 2;

		cout << endl << "Selected: Smart v Player" << endl;
		break;
	case NBGAME::SmartXRandO:
		naughtValue = 1;
		crossValue = 2;

		cout << endl << "Selected: Smart v Random" << endl;
		break;
	case NBGAME::SmartVSmart:
		naughtValue = 2;
		crossValue = 2;
		
		cout << endl << "Selected: Smart v Smart" << endl;
		break;
	case NBGAME::RandomVRand:
		naughtValue = 1;
		crossValue = 1;
		
		cout << endl << "Selected: Random v Random" << endl;
		break;
	case NBGAME::BothPlayers:
		naughtValue = 0;
		crossValue = 0;
		
		cout << endl << "Selected: Player v Player" << endl;
		break;
	default:
		break;
	}
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

	do {
		
		TicTacToe* board = nbTicTacToe->getBoard(nb_currentBoard);
		
		players[determinePlayer(symbolBeingPlayed)]->processMove(movePosition, board, symbolBeingPlayed);

		determineWinner(winner);

		nb_currentBoard = handleLevelChange(symbolBeingPlayed, movePosition);
		
		cout << endl << endl;

		nbTicTacToe->displayNBTicTacToe();

	} while (checkGameState());

	displayWinConditionInformation(currentGameState, winner);

	deletePointers();
}

bool NBGAME::NBGame::allBoardsFull()
{
	return amountOfFullBoards >= MAXMOVES;
}

void NBGAME::NBGame::determineWinner(int& _winningPlayer)
{
	TicTacToe* _board = nbTicTacToe->getBoard(nb_currentBoard);
	int result = _board->gameStatus();

	if (result == 1 || result == -1)
	{
		currentGameState = GameOver;
		_winningPlayer = result;

		if (result == 1) xWinCounter++;

		return;
	}

	else if (result == 2)
	{
		currentGameState = GameDrawn;
		return;
	}
}