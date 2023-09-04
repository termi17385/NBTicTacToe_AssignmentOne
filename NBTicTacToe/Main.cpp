/*
	Created by Joshua Jones
	on: 04/09/2023

	This is a student project.
*/

#include<iostream>
#include<iomanip>
#include "BoardSystem.h"
#include "Board.h"

using namespace std;

int main()
{
	BoardSystem board(0, 0);
	int x;
	int y;

	do
	{
		board.displayBoards();
		cout << "Select board: "; cin >> x >> y;
		board.select(x, y);
	} while (x != -1 && y != -1);
}