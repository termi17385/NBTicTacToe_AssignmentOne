#pragma once
class Board
{
private:
	int board[3][3];
	void randomizeBoardValues();

public:
	Board() { randomizeBoardValues(); }
	int getBoardValue(int, int);
};

