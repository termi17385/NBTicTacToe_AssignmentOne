#include "NBTicTacToe.h"
#include <iostream>
#include <iomanip>

using namespace std;

const int GRID_SIZE = 9;
const int BOARD_SIZE = 3;

const std::string BOARD_SEPARATOR = " -----------   -----------   ----------- ";
const std::string ROW_SEPARATOR = "| --|---|-- | | --|---|-- | | --|---|-- |";

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

		displayBoards();

		winningPlayer = getBoard(currentBoard).gameStatus(); // check the win condition

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

			while (getBoard(currentBoard).isBoardFull())
			{
				srand(time(NULL));
				currentBoard = Coordinate(rand() % 3, rand() % 3);
			}
		}

	} while (currentState == IsPlaying);
	determineWinner(winningPlayer);
}

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
		} while (!getBoard(currentBoard).isValidMove(row, col));
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
		} while (!getBoard(currentBoard).isValidMove(row - 1, col - 1));

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

#pragma region Display Boards
///<summary>
/// Handles column separators in the game board display.
///</summary>
///<param name="coord">The coordinate being tracked in the game board.</param>
///<param name="y">The current column index.</param>
void columnSeparator(Coordinate& coord, int y)
{
	if (y % BOARD_SIZE == BOARD_SIZE - 1)
	{
		coord.y++;
		coord.y = coord.y % BOARD_SIZE;
		cout << " |";
	}
	coord = coord;
}

///<summary>
/// Handles row separators in the game board display.
///</summary>
///<param name="coord">The coordinate being tracked in the game board.</param>
///<param name="x">The current row index.</param>
void rowSeparator(Coordinate& coord, int x)
{
	if (x % BOARD_SIZE == BOARD_SIZE - 1)
	{
		coord.x++;
		coord.x = coord.x % BOARD_SIZE;
		if (x != 8) cout << endl << BOARD_SEPARATOR << endl;
	}
	coord = coord;
}

///<summary>
/// Determines the player ('X', 'O', or empty) for a specific grid cell and board position.
///</summary>
///<param name="cell">The cell coordinate.</param>
///<param name="board">The coordinate of the current game board.</param>
///<returns>The player ('X', 'O', or empty) for the cell.</returns>
char NBTicTacToe::getPlayerForCell(Coordinate cell, Coordinate board)
{
	int move = grid[cell.x][cell.y].getMove(board.x % 3, board.y % 3);
	if (move == 1) return 'X';
	else if (move == -1) return 'O';
	else return ' ';
}



///<summary>
/// Displays the game boards along with separators.
///</summary>
void NBTicTacToe::displayBoards()
{
	// current = the current grid we want to access via the loop
	// it is not the same as current board, which is the current board we are playing on

	Coordinate current{};
	current.x = 0;
	current.y = 0;

	// board is the coordinates for the current grid and that grid's board, this allows us to grab
	// information based on what played played on x tile in board.

	Coordinate board{};
	board.x = 0;
	board.y = 0;

	char player = ' ';

	// Initial Separator, adds line to the top
	cout << endl << BOARD_SEPARATOR << endl;
	for (int x = 0; x < GRID_SIZE; x++)
	{
		cout << "|";
		for (int y = 0; y < GRID_SIZE; y++)
		{
			/*
				The loop works by implementing across rows then working down
				for instance we start say in position:

				grid[0][0] Then access the board for that cell

				We do this 3 times before adding a column separator then moving to the next board in the row
				grid[0][0].getMove(0,0);
				grid[0][0].getMove(0,1);
				grid[0][0].getMove(0,2);

				grid[0][1].getMove(0,0);
				grid[0][1].getMove(0,1);
				grid[0][1].getMove(0,2);

				.....

				After that we move down a row

				this repeats the cycle above, 2 more times making sure to create the first 3 tic tac toe boards,
				before we move to the next 3 then the last 3
				grid[0][0].getMove(1,0);
			*/

			// Grabs the current player character for the cell and prints it to console
			cout << setw(1) << " " << getPlayerForCell(current, board);

			// Determines when to add horizontal separators
			if (y != GRID_SIZE - 1) cout << " |";

			columnSeparator(current, y);

			board.y++;
			board.y = board.y % 3;
		}

		rowSeparator(current, x);

		board.x++;
		board.x = board.x % BOARD_SIZE;
		if (x != GRID_SIZE - 1 && x % BOARD_SIZE != 2) cout << endl << ROW_SEPARATOR << endl;
		else if (x % BOARD_SIZE == 2) cout << endl << BOARD_SEPARATOR << endl;
	}
	cout << endl;
}

TicTacToe NBTicTacToe::getBoard(Coordinate _boardCoords)
{
	return grid[_boardCoords.x][_boardCoords.y];
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