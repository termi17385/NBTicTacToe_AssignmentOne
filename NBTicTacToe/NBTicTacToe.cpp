#include "NBTicTacToe.h"
#include <iostream>
#include <iomanip>


// TODO: code needs to be cleaned up with better decomposition
// TODO: next is to implement NBGame and other abstractions
// TODO: need a player class that can be inherited for each player type
// TODO: split logic flow into correct classes

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
void NBTicTacToe::setCurrentBoard(Coordinate _currentBoard)
{
	currentBoard = _currentBoard;
}

// Display Driver
void NBTicTacToe::displayNBTicTacToe()
{
	displayBoards();
}

// Pointer reference for getting the TicTacToe board from the grid
TicTacToe* NBTicTacToe::getBoard(Coordinate _gridCoords)
{
	return &grid[_gridCoords.x][_gridCoords.y];
}

bool NBTicTacToe::isBoardFull(Coordinate _current)
{
	return getBoard(_current)->t_isBoardFull();
}
#pragma endregion

#pragma region Board Display Logic
void NBTicTacToe::displayCells(int _boardX, int _boardY, int& _counter, int _index, bool _isBoardSelected, Coordinate& _boardCoords)
{
	// Loop through each cell in the row
	for (int cellX = 0; cellX < BOARDSIZE; cellX++)
	{
		// Loop through each row within a cell
		for (int cellY = 0; cellY < BOARDSIZE; cellY++)
		{
			_boardCoords.x = _boardX;
			_boardCoords.y = calculateYPosition(_boardX, cellX) % 3;

			// Determine if the current cell is selected
			_isBoardSelected = validateCurrentBoard(_boardCoords);
			char selectedBoardChar = _isBoardSelected == true ? '*' : '|';

			// Display the selected board character or the cell content
			if (cellY == 0) cout << selectedBoardChar; // Display '*' or '|' at the beginning of a cell row
			else cout << '|'; // Display '|' for the separator between cell rows

			//cout << boardCoords.x + 1 << "," << boardCoords.y + 1;
			displayPlayerOnBoard(_boardCoords, _index, cellY);
			if (cellY == 2) cout << selectedBoardChar;
		}

		// Display the board number (1, 2, 3) on the side of the board when
		// cellX is 2 (end of the row) and boardY is 1 (middle row of boards) 
		if (cellX == 2 && _boardY == 1)
		{
			cout << " < " << _counter; // Display the board number and increment the counter
			_counter++;
		}
	}
}

void NBTicTacToe::displayBoards()
{
	bool isBoardSelected = false;
	int counter = 1, index = 0;
	Coordinate boardCoords;

	cout << "      1 " << "           2" << "            3" << endl;
	cout << "      v " << "           v" << "            v" << endl;

	// Loop through each board
	for (int boardX = 0; boardX < BOARDSIZE; boardX++)
	{
		// Display top bars or dividers for the current board
		displayBarsOrDividers(boardX);

		// Loop through each row of cells in the current board
		for (int boardY = 0; boardY < BOARDSIZE; boardY++)
		{
			// Loop through each cell in the row
			displayCells(boardX, boardY, counter, index, isBoardSelected, boardCoords);

			index++;
			index = index % 3;

			cout << endl;
			if (boardY != 2) displayBarsOrDividers(boardX, true);
		}

		displayBarsOrDividers(boardX);
	}
}
#pragma endregion

#pragma region Display Logic Helper functions and decomp
int NBTicTacToe::calculateYPosition(int _a, int _b)
{
	return (_a * (BOARDSIZE)+_b);
}

#pragma region Displaying Player Logic
char getPlayerForCell(int _value)
{
	char player = ' ';
	if (_value == 1) player =  'X';
	else if (_value == -1) player = 'O';
	else player = ' ';
	return player;
}

void NBTicTacToe::displayPlayerOnBoard(Coordinate _boardCoords, int _index, int _cellY)
{
	TicTacToe board = grid[_boardCoords.x][_boardCoords.y];
	int player = board.getMove(_index, _cellY);
	cout << setw(2) << getPlayerForCell(player) << " ";
}
#pragma endregion

#pragma region Board validation and Selected board seperators
bool NBTicTacToe::validateCurrentBoard(Coordinate _validate)
{
	return currentBoard == _validate;
}

// determines what characters to display based on if this is the selected board
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
	if (_cellY == 0) cout << dividerCharacter; // Display '*' or '|' at the beginning of a cell row
	else cout << '|'; // Display '|' for the separator between cell rows
}
#pragma endregion
#pragma endregion