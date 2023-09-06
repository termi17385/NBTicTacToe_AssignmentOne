#include "NBTicTacToe.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Bar selection and non selection, are the board top and bottom bars
const std::string BAR_SELECTION = "  * * * * *  ";
const std::string BAR_NO_SELECTION = "  - - - - -  ";

// Divider selection and no selection are the boards cell divider
const std::string DIVIDER_SELECTION = "* --|---|-- *";
const std::string DIVIDER_NO_SELECTION = "| --|---|-- |";

const int GRID_SIZE = 9;

#pragma region GamePlay
void NBTicTacToe::play()
{
	// What is the counterpart of this function in the original code?
	// Answer, in the original code the counter part is run();
	int player = 1;
	int winningPlayer = 0;

	do
	{
		int x, y;
		processMove(x,y,player);

		//cout << endl;
		//displayBoards();
		//cout << endl;

		winningPlayer = grid[currentBoard.x][currentBoard.y].gameStatus(); // check the win condition

		// 1 = X, -1 = O and 0 = no one has won
		if (winningPlayer == 1 || winningPlayer == -1) 
		{ 
			currentState = GameOver; 
		}
		else if (winningPlayer == 2)
		{
			fullBoards++;
		}

		currentState = fullBoards >= 9 ? GameDrawn : currentState;

		if (currentState == IsPlaying)
		{
			player = player == 1 ? -1 : 1;
			currentBoard = Coordinate(x, y);
			
			cout << endl;
			displayBoards();
			cout << endl;


			while (grid[currentBoard.x][currentBoard.y].isBoardFull())
			{
				srand(time(NULL));
				currentBoard = Coordinate(rand() % 3, rand() % 3);
			}			
		}

	} while (currentState == IsPlaying);

	cout << endl;
	displayBoards();
	cout << endl;

	determineWinner(winningPlayer);
}

bool NBTicTacToe::isBoardFull(Coordinate _cBoard)
{
	return grid[_cBoard.x][_cBoard.x].getNoOfMoves() >= 9;
}

void NBTicTacToe::determineWinner(int _winner)
{
	if (currentState == GameDrawn)
	{
		cout << "The game has reached a draw! No winners :(";
		return;
	}

	if (currentState == GameOver)
	{
		if (_winner == 1)
			cout << "Player {X} has won the game!";

		if (_winner == -1)
			cout << "Player {O} has won the game!";
	}

	else cout << "Unexpected Win Condition, Could be a fault?";
}
#pragma endregion

#pragma region Player Moves
void NBTicTacToe::getXMove(int& x, int& y)
{
	srand(time(NULL));
	cout << "Player " << "X" << " entering move now...." << endl;

	if (!isBoardFull(currentBoard))
	{
		int row, col;

		do
		{
			row = rand() % 3;
			col = rand() % 3;
		} while (!grid[currentBoard.x][currentBoard.y].isValidMove(row, col));
		x = row;
		y = col;
	}
}

void NBTicTacToe::getOMove(int& x, int& y)
{
	cout << "Player " << "O" << " enter move: ";

	if (!isBoardFull(currentBoard))
	{
		int row, col;
		do
		{
			cin >> row >> col;
			cout << endl;
		} while (!grid[currentBoard.x][currentBoard.y].isValidMove(row - 1, col - 1));

		x = row - 1;
		y = col - 1;
	}
}

void NBTicTacToe::processMove(int& _x, int& _y, int& _player)
{
	(_player == 1) ? getXMove(_x, _y) : getOMove(_x, _y);
	grid[currentBoard.x][currentBoard.y].addMove(_x, _y, _player);
}
#pragma endregion

#pragma region Board Display Methods
void displayDividerCharacter(int _cellY, bool _selected)
{
	char dividerCharacter = _selected == true ? '*' : '|';
	if (_cellY == 0) cout << dividerCharacter; // Display '*' or '|' at the beginning of a cell row
	else cout << '|'; // Display '|' for the separator between cell rows
}

char showCharacter(int value)
{
	char p = ' ';
	if (value == 1) p =  'X';
	else if (value == -1) p = 'O';
	else p = ' ';
	return p;
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
			for (int cellX = 0; cellX < BOARDSIZE; cellX++)
			{
				// Loop through each row within a cell
				for (int cellY = 0; cellY < BOARDSIZE; cellY++)
				{
					boardCoords.x = boardX;
					boardCoords.y = calculateYPosition(boardX, cellX) % 3;

					// Determine if the current cell is selected
					isBoardSelected = checkXY(boardCoords);
					char selectedBoardChar = isBoardSelected == true ? '*' : '|';

					// Display the selected board character or the cell content
					if (cellY == 0) cout << selectedBoardChar; // Display '*' or '|' at the beginning of a cell row
					else cout << '|'; // Display '|' for the separator between cell rows

					//cout << boardCoords.x + 1 << "," << boardCoords.y + 1;
					TicTacToe board = grid[boardCoords.x][boardCoords.y];
					int player = board.getMove(index, cellY);

					cout << setw(2) << showCharacter(player) << " ";
					if (cellY == 2) cout << selectedBoardChar;
				}

				// Display the board number (1, 2, 3) on the side of the board when
				// cellX is 2 (end of the row) and boardY is 1 (middle row of boards) 
				if (cellX == 2 && boardY == 1)
				{
					cout << " < " << counter; // Display the board number and increment the counter
					counter++;
				}
			}

			index++;
			index = index % 3;

			cout << endl;
			if (boardY != 2) displayBarsOrDividers(boardX, true);
		}

		displayBarsOrDividers(boardX);
	}
}

int NBTicTacToe::calculateYPosition(int _a, int _b)
{
	return (_a * (BOARDSIZE) + _b);
}

bool NBTicTacToe::checkXY(Coordinate _validate)
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
		barType = checkXY({_x,i}) ? selection : noSelection;
		cout << barType;
	}
	cout << endl;
}
#pragma endregion