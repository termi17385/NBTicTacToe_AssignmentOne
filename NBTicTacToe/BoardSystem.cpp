#include"BoardSystem.h"
#include<iostream>
#include<iomanip>
#include "Board.h"

#include <string>

using namespace std;

const std::string ALLSTARS = "  * * * * *  ";
const std::string NOSTARS =  "  - - - - -  ";

const std::string D_ALLSTARS = "* --|---|-- *";
const std::string D_NOSTARS = "| --|---|-- |";

int BoardSystem::calculatePosition(int a, int b)
{
	return (a * (BOARDSIZE / 3) + b);
}

void debugCoords(int a, int b)
{
	cout << a + 1 << "," << b + 1;
}

void showCharacter(int value)
{
	std::string p = " ";
	if (value == 1) p = " X ";
	if (value == -1) p = " O ";

	cout << setw(2) << p;
}

bool BoardSystem::checkXY(int x, int y)
{
	return selectedBoard.x == x && selectedBoard.y == y;
}

void BoardSystem::displayBar(int _x)
{
	std::string barType = NOSTARS;
	barType = checkXY(_x, 0) ? ALLSTARS : NOSTARS;
	cout << barType;
	barType = checkXY(_x, 1) ? ALLSTARS : NOSTARS;
	cout << barType;
	barType = checkXY(_x, 2) ? ALLSTARS : NOSTARS;
	cout << barType << endl;
}

void BoardSystem::displayDivider(int _x)
{
	std::string barType = NOSTARS;
	barType = checkXY(_x, 0) ? D_ALLSTARS : D_NOSTARS;
	cout << barType;
	barType = checkXY(_x, 1) ? D_ALLSTARS : D_NOSTARS;
	cout << barType;
	barType = checkXY(_x, 2) ? D_ALLSTARS : D_NOSTARS;
	cout << barType << endl;
}

void BoardSystem::displayBoards()
{	
	int boardSize = BOARDSIZE / 3;
	bool isBoardSelected = false;
	Coordinate boardCoords;

	cout << "      1 " << "           2" << "            3" << endl;

	for (int boardX = 0; boardX < boardSize; boardX++)
	{
		displayBar(boardX);

		for (int boardY = 0; boardY < boardSize; boardY++)
		{
			for (int cellX = 0; cellX < boardSize; cellX++)
			{
				for (int cellY = 0; cellY < boardSize; cellY++)
				{
					boardCoords.y = calculatePosition(boardX, cellX) % 3;
					boardCoords.x = boardX;
					
					isBoardSelected = selectedBoard.x == boardCoords.x && selectedBoard.y == boardCoords.y;
					char selectedBoardChar = ' ';
					selectedBoardChar = isBoardSelected == true ? '*' : '|';

					if(cellY == 0) cout << selectedBoardChar;
					else cout << '|';
					debugCoords(boardCoords.x, boardCoords.y);
					//showCharacter(boards[positionx][positiony].getBoardValue(cellX,cellY));
					if(cellY == 2)cout << selectedBoardChar;

				}
			}
			cout << endl;
			if(boardY != 2) displayDivider(boardX);
		}

		displayBar(boardX);
	}
}

void BoardSystem::select(int x, int y)
{
	selectedBoard.x = x - 1;
	selectedBoard.y = y - 1;
}
