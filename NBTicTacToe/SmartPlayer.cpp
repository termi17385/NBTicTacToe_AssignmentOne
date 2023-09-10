#include "SmartPlayer.h"
#include <iostream>
using namespace std;

void SmartPlayer::processMove(Coordinate& _movePosition, TicTacToe* _board, int _cellValue)
{
	bool canMove = false;
	bool win = false;
	bool lose = false;

	checkRowsAndColumns(_movePosition, *_board, _cellValue, win, lose);

	if (!win) checkNextBoard(_movePosition, _cellValue);

	addMoveToBoard(_board, _movePosition, _cellValue);
}

void SmartPlayer::checkNextBoard(Coordinate& _movePosition, int _player)
{
	TicTacToe& board = *nbTicTacToe->getBoard(_movePosition);
	TicTacToe boardCopy = board;

	int boardMove = boardCopy.getNoOfMoves();

	cout << "scanning next board for potenial lose or misplay" << endl;

	if (boardMove <= 1)
	{
		cout << "Best Board to Choose" << endl;
		return;
	}

	bool win = false;
	bool lose = false;

	Coordinate tempMove;

	checkRowsAndColumns(tempMove, boardCopy, _player, win, lose);

	if (win || lose)
	{
		cout << "This board would be a deterimental choice" << endl;
		// we need to choose another board
	}

	else
	{
		cout << "This board is a safe option" << endl;
	}
}


void SmartPlayer::checkRowsAndColumns(Coordinate& _move, TicTacToe& _board, int _player, bool& _win, bool& _lose)
{
	TicTacToe boardCopy = _board;
	bool chosen = false;
	
	int index = 0;
	int rowBlockableTargets = 0;
	int columnBlockableTargets = 0;


	for (int x = 0; x < 3 && !chosen; x++)
	{
		for (int y = 0; y < 3 && !chosen; y++)
		{
#pragma region Setup
			Coordinate currentPosition(x,y);
			int previousX = x <= 0 ? 2 : x - 1;
			int nextX = x >= 2 ? 0 : x + 1;

			int previousY = y <= 0 ? 2 : y - 1;
			int nextY = y >= 2 ? 0 : y + 1;

			if (chosen) continue;

			xCell = CellData(boardCopy.getMove(nextX, y), boardCopy.getMove(previousX, y));
			yCell = CellData(boardCopy.getMove(x, nextY), boardCopy.getMove(x, previousY));
			
			bool canMove = boardCopy.isValidMove(currentPosition.x, currentPosition.y);
#pragma endregion
			if (canMove)
			{
				cout << "Looking for potenial win position \n";

				if (yCell.previousCell == yCell.nextCell && yCell.previousCell != 0)
				{
					cout << "Scanning \n";
					if (yCell.previousCell == _player)
					{
						cout << "Winning spot found!" << endl;
						_win = true;
						_lose = false;

						_move = Coordinate(x,y);
						chosen = true;
						continue;
					}
					else
					{
						cout << "Adding Potential Block" << endl;
						index = x + y;

						if (index < 9)
						{
							_lose = true;
							_win = false;

							potentialBlocksRows[index] = Coordinate(x,y);
							rowBlockableTargets++;
						}
					}
				}

				if (xCell.previousCell == xCell.nextCell && xCell.previousCell != 0)
				{
					cout << "Scanning \n";
					if (xCell.previousCell == _player)
					{
						cout << "Winning spot found!" << endl;

						_move = Coordinate(x, y);
						_win = true;
						_lose = false;

						chosen = true;
						continue;
					}
					else
					{
						cout << "Adding Potential Block" << endl;
						index = x + y;

						if (index < 9)
						{
							_lose = true;
							_win = false;

							potentialBlocksColumns[index] = Coordinate(x, y);
							columnBlockableTargets++;
						}
					}
				}
			}
		}
	}

	if (!chosen)
	{
		if (rowBlockableTargets > 0)
		{
			cout << "Blocking Spot" << endl;
			srand(time(NULL));
			_move = potentialBlocksRows[rand() % 9];
		}
		else if (columnBlockableTargets > 0)
		{
			cout << "Blocking Spot" << endl;
			srand(time(NULL));
			_move = potentialBlocksColumns[rand() % 9];
		}
		else
		{
			randomMove(_move, boardCopy);
		}
	}
}

void SmartPlayer::randomMove(Coordinate& _movePosition, TicTacToe& _board)
{
	TicTacToe boardCopy = _board;
	do
	{
		cout << "Randomising Move" << endl;
		_movePosition = Coordinate(rand() % 3, rand() % 3);

	} while (!boardCopy.isValidMove(_movePosition.x, _movePosition.y));
}