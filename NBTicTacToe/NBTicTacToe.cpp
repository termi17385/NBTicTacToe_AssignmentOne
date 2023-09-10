#include <iostream>
#include <iomanip>
#include "Coordinate.h"
#include "NBTicTacToe.h"
using namespace std;

#pragma region Constant Variables
// Bar selection and non selection, are the board top and bottom bars
const std::string BAR_SELECTION = "  * * * * *  ";
const std::string BAR_NO_SELECTION = "  - - - - -  ";

// Divider selection and no selection are the boards cell divider
const std::string DIVIDER_SELECTION = "* --|---|-- *";
const std::string DIVIDER_NO_SELECTION = "| --|---|-- |";
#pragma endregion
#pragma region Public Methods
void NBTicTacToe::setCurrentBoard(Coordinate _currentBoard) { currentBoard = _currentBoard; }
void NBTicTacToe::displayNBTicTacToe() { displayBoards(); }
TicTacToe* NBTicTacToe::getBoard(Coordinate _gridCoords) { return &boards[_gridCoords.x][_gridCoords.y]; }
bool NBTicTacToe::isBoardFull(Coordinate _current) { return getBoard(_current)->t_isBoardFull(); }
#pragma endregion
#pragma region Board Display Logic
void NBTicTacToe::displayBoards()
{
	bool isBoardSelected = false;
	int counter = 1;

	cout << "      1 " << "           2" << "            3" << endl;
	cout << "      v " << "           v" << "            v" << endl;

	for (int boardX = 0; boardX < BOARDSIZE; boardX++)
	{
		displayBarsOrDividers(boardX);

		for (int cellX = 0; cellX < BOARDSIZE; cellX++)
		{
			// Loop through each cell in the row
			displayCells(boardX, cellX, counter, isBoardSelected);

			cout << endl;

			if (cellX != 2) displayBarsOrDividers(boardX, true);
		}

		displayBarsOrDividers(boardX);
	}
}
void NBTicTacToe::displayCells(int _boardX, int _cellX, int& _counter, bool _isBoardSelected)
{
	for (int boardY = 0; boardY < BOARDSIZE; boardY++)
	{
		for (int cellY = 0; cellY < BOARDSIZE; cellY++)
		{
			Coordinate boardCoord(_boardX, boardY);
			displayCell(boardCoord, _isBoardSelected, _cellX, cellY);
		}

		if (boardY == 2 && _cellX == 1)
		{
			cout << " < " << _counter;
			_counter++;
		}
	}
}
void NBTicTacToe::displayCell(Coordinate _boardCoords, bool _isBoardSelected, int _cellX, int _cellY)
{
	_isBoardSelected = validateCurrentBoard(_boardCoords);
	char selectedBoardChar = _isBoardSelected == true ? '*' : '|';

	if (_cellY == 0) cout << selectedBoardChar;
	else cout << '|';

	displayPlayerOnBoard(_boardCoords, _cellX, _cellY);
	if (_cellY == 2) cout << selectedBoardChar;
}
#pragma endregion
#pragma region Display Logic Helper functions and decomp
#pragma region Displaying Player Logic
char getPlayerForCell(int _value)
{
	char player = ' ';
	if (_value == 1) player =  'X';
	else if (_value == -1) player = 'O';
	else player = ' ';
	return player;
}
void NBTicTacToe::displayPlayerOnBoard(Coordinate _boardCoords, int _cellX, int _cellY)
{
	TicTacToe board = boards[_boardCoords.x][_boardCoords.y];
	int player = board.getMove(_cellX, _cellY);
	cout << setw(2) << getPlayerForCell(player) << " ";
}
#pragma endregion
#pragma region Board validation and Selected board seperators
bool NBTicTacToe::validateCurrentBoard(Coordinate _validate)
{
	return currentBoard == _validate;
}
void NBTicTacToe::displayBarsOrDividers(int _x, bool _isDivider)
{
	std::string selection = _isDivider ? DIVIDER_SELECTION : BAR_SELECTION;
	std::string noSelection = _isDivider ? DIVIDER_NO_SELECTION : BAR_NO_SELECTION;

	for (int i = 0; i < 3; i++)
	{
		std::string barType = noSelection;
		barType = validateCurrentBoard({_x,i}) ? selection : noSelection;
		cout << barType;
	}
	cout << endl;
}
void displayDividerCharacter(int _cellY, bool _selected)
{
	char dividerCharacter = _selected == true ? '*' : '|';
	if (_cellY == 0) cout << dividerCharacter;
	else cout << '|'; 
}
#pragma endregion
#pragma endregion