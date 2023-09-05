#include"BoardSystem.h"
#include<iostream>
#include<iomanip>
#include "Board.h"

#include <string>

using namespace std;

// Bar selection and non selection, are the board top and bottom bars
const std::string BAR_SELECTION = "  * * * * *  ";
const std::string BAR_NO_SELECTION =  "  - - - - -  ";

// Divider selection and no selection are the boards cell divider
const std::string DIVIDER_SELECTION = "* --|---|-- *";
const std::string DIVIDER_NO_SELECTION = "| --|---|-- |";

void BoardSystem::boardSelection(int x, int y)
{
	currentBoard.x = x - 1;
	currentBoard.y = y - 1;
}

int BoardSystem::calculateYPosition(int a, int b)
{
	return (a * (BOARDSIZE / 3) + b);
}

void showCharacter(int value)
{
	std::string p = " ";
	if (value == 1) p = " X ";
	else if (value == -1) p = " O ";
	else p = " ";
	cout << setw(2) << p;
}

bool BoardSystem::checkXY(int x, int y)
{
	return currentBoard.x == x && currentBoard.y == y;
}

/// <summary>
/// Simple function for displaying divdiers or bars for the board,
/// very reusable and automatically handles checking if the board is selected
/// </summary>
void BoardSystem::displayBarsOrDividers(int _x, bool _isDivider = false)
{
	std::string selection = _isDivider ? DIVIDER_SELECTION : BAR_SELECTION;
	std::string noSelection = _isDivider ? DIVIDER_NO_SELECTION : BAR_NO_SELECTION;

	for (int i = 0; i < 3; i++)
	{
		std::string barType = noSelection;
		barType = checkXY(_x, i) ? selection : noSelection;
		cout << barType;
	}
	cout << endl;
}

/// <summary>
/// Formatt for displaying the coords of each board, this
/// is mainly used so I can check if the console is correctly
/// displaying each board in the right position
/// </summary>
void displayDebugCoordinates(int _x, int _y)
{
	cout << _x + 1 << "," << _y + 1;
}

// TODO: Better handle decomposition, smooth out the code a bit then implement remaining parts of assignment

void BoardSystem::displayBoards()
{	
	int boardSize = BOARDSIZE / 3; // Could probably be a secondary constant ¯\_(ツ)_/¯
	bool isBoardSelected = false;
	
	int counter = 1; // used to display 1 - 3 on the side for helping people to know the coords.

	cout << "      1 " << "           2" << "            3" << endl;
	cout << "      v " << "           v" << "            v" << endl;

	// Loop through each board
	for (int boardX = 0; boardX < boardSize; boardX++)
	{
		// Display top bars or dividers for the current board
		displayBarsOrDividers(boardX);

		// Loop through each row of cells in the current board
		for (int boardY = 0; boardY < boardSize; boardY++)
		{
			// Loop through each cell in the row
			for (int cellX = 0; cellX < boardSize; cellX++)
			{
				// Loop through each row within a cell
				for (int cellY = 0; cellY < boardSize; cellY++)
				{
					Coordinate boardCoords(boardX, calculateYPosition(boardX, cellX) % 3);
					
					// Determine if the current cell is selected
					isBoardSelected = currentBoard.x == boardCoords.x && currentBoard.y == boardCoords.y;
					char selectedBoardChar = isBoardSelected == true ? '*' : '|';

					// Display the selected board character or the cell content
					if(cellY == 0) 
						cout << selectedBoardChar; // Display '*' or '|' at the beginning of a cell row
					else
						cout << '|'; // Display '|' for the separator between cell rows
					
					if(debug) displayDebugCoordinates(boardCoords.x, boardCoords.y);
					else showCharacter(boards[boardCoords.x][boardCoords.y].getBoardValue(cellX,cellY));

					if(cellY == 2)cout << selectedBoardChar;
				}

				// Display the board number (1, 2, 3) on the side of the board when
				// cellX is 2 (end of the row) and boardY is 1 (middle row of boards) 
				if (cellX == 2 && boardY == 1) 
				{
					cout << " < " << counter; // Display the board number and increment the counter
					counter++;
				}
			}

			cout << endl;
			if(boardY != 2) displayBarsOrDividers(boardX, true);
		}

		displayBarsOrDividers(boardX);
	}
}