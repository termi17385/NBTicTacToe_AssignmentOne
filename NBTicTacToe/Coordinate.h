#pragma once
struct Coordinate
{
	int x = 0;
	int y = 0;

	Coordinate() : x(0), y(0) {} // Default constructor
	Coordinate(int _x, int _y)
	{
		this->x = _x;
		this->y = _y;
	}

	bool operator==(const Coordinate& _other) const
	{
		return (x == _other.x && y == _other.y);
	}
};

