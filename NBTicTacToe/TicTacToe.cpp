#include "TicTacToe.h"

#include <stdlib.h>
#include <time.h>

#include<string>
#include<iostream>
#include<iomanip>

using namespace std;

const int MAXMOVES = 9;

TicTacToe::TicTacToe()
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			cells[row][col] = 0;

	noOfMoves = 0;
}

int TicTacToe::getNoOfMoves()
{
	return noOfMoves;
}
int TicTacToe::getMove(int _x, int _y)
{
	return cells[_x][_y];
}
void TicTacToe::addMove(int _x, int _y, int _player)
{
	cells[_x][_y] = _player;
	noOfMoves++;
}

int TicTacToe::checkRows()
{
	int rowValue = 0;
	for (int i = 0; i < 3; i++)
	{
		rowValue = cells[i][0];
		if (rowValue == 0) continue;

		if (rowValue == cells[i][1] && rowValue == cells[i][2])
			return rowValue;
	}

	return 0;
}
int TicTacToe::checkColumns()
{
	int colValue = 0;
	for (int i = 0; i < 3; i++)
	{
		colValue = cells[0][i];
		if (colValue == 0) continue;

		if (colValue == cells[1][i] && colValue == cells[2][i])
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
	int diagonalValue = cells[1][1];
	
	bool diagonalWin = ((diagonalValue == cells[0][0] && diagonalValue == cells[2][2]) 
		|| (diagonalValue == cells[0][2] && diagonalValue == cells[2][0]) && diagonalValue != 0);

	return diagonalWin ? diagonalValue : 0;
}

bool TicTacToe::isValidMove(int _x, int _y)
{
	if (cells[_x][_y] == 0)
		return true;
	else
		return false;
}
int TicTacToe::gameStatus()
{
	int winner = 0;
	if (noOfMoves >= 9) return 2;

	winner = checkRows();
	if (winner != 0) return winner;   

	winner = checkColumns();
	if (winner != 0) return winner;

	return checkDiagonals();
}
bool TicTacToe::t_isBoardFull()
{
	return noOfMoves >= MAXMOVES;
}