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
	char ans = ' ';
	bool debug = false;
	
	cout << "Do you want to display debug information? (Y/N): "; cin >> ans;
	debug = ans == 'Y' || ans == 'y';

	BoardSystem board(0, 0, debug);
	int x;
	int y;

	do
	{
		board.displayBoards();
		cout << "Select board: "; cin >> x >> y;
		board.boardSelection(x, y);
	} while (x != -1 && y != -1);
}