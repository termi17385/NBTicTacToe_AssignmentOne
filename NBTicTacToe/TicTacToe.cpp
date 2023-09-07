#include "TicTacToe.h"
#include <stdlib.h>
#include <time.h>

#include<string>
#include<iostream>
#include<iomanip>

using namespace std;

/// <summary>
/// This is a Constructor is it called on the initialisation of the object
/// since this Constructor has no params nothing else is needed, it will run on creation
/// </summary>
TicTacToe::TicTacToe()
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = 0;

	noOfMoves = 0;
}

int TicTacToe::getNoOfMoves()
{
	return noOfMoves;
}

int TicTacToe::getMove(int _x, int _y)
{
	return board[_x][_y];
}

bool TicTacToe::isValidMove(int _x, int _y)
{
	if (board[_x][_y] == 0)
		return true;
	else
		return false;
}

/// <summary>
/// When called, will tell the array at position {x,y} this <seealso cref="player"/> made a move
/// </summary>
void TicTacToe::addMove(int _x, int _y, int _player)
{
	board[_x][_y] = _player;
	noOfMoves++;
}

int TicTacToe::checkRows()
{
	int rowValue = 0;
	for (int i = 0; i < 3; i++)
	{
		rowValue = board[i][0];
		if (rowValue == 0) continue;

		if (rowValue == board[i][1] && rowValue == board[i][2])
			return rowValue;
	}

	return 0;
}

int TicTacToe::checkColumns()
{
	int colValue = 0;
	for (int i = 0; i < 3; i++)
	{
		colValue = board[0][i];
		if (colValue == 0) continue;

		if (colValue == board[1][i] && colValue == board[2][i])
			return colValue;
	}

	return 0;
}

int TicTacToe::checkDiagonals()
{
	//Check diagonals for a win
	// |0,0|0,1|0,2|
	// |---|---|---|
	// |1,0|1,1|1,2|
	// |---|---|---|
	// |2,0|2,1|2,2|
	int diagonalValue = board[1][1];
	
	bool diagonalWin = ((diagonalValue == board[0][0] && diagonalValue == board[2][2]) 
		|| (diagonalValue == board[0][2] && diagonalValue == board[2][0]) && diagonalValue != 0);

	return diagonalWin ? diagonalValue : 0;
}

int TicTacToe::gameStatus()
{
	int winner = 0;
	// First check if this is a draw, if so then skip
	if (noOfMoves >= 9) return 2;

	// Check Rows and Columns, the if statements are so we do not prematurely return.
	winner = checkRows();
	if (winner != 0) return winner;   

	winner = checkColumns();
	if (winner != 0) return winner;

	// Lastly checkDiagonals
	return checkDiagonals();
}

bool TicTacToe::isBoardFull()
{
	return noOfMoves >= 9;
}

//std::string TicTacToe::displayBoard()
//{
//	// Board is obtained as a variable of TicTacToe header file class
//	// this method is part of the TicTacToe class so it can access that variable
//	// in this case the variable board is a multidimensional array.
//	//   - - - - -
//	// | --|---|-- |
//	// | --|---|-- |
//	// | --|---|-- |
//	//   - - - - -
//
//	std::string _board;
//
//	_board = "\n\n";
//	_board += "  - - - - -\n";
//
//	for (int i = 0; i < 3; i++)
//	{
//		_board += "| ";
//		for (int j = 0; j < 3; j++)
//		{
//#pragma region Get Player Symbol
//			char playerSymbol = ' ';
//			if (board[i][j] == 1) playerSymbol = 'X';
//			else if (board[i][j] == -1) playerSymbol = 'O';
//#pragma endregion
//			//_board += setw(1);
//			_board += playerSymbol;
//			_board += " | ";
//		}
//		if (i != 2) _board += "\n  --|---|--\n";
//	}
//
//	_board += "\n  - - - - -\n";
//	_board += "\n\n";
//
//	return _board;
//}
