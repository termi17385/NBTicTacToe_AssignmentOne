#pragma once
struct Coordinate
{
	int x = 0;
	int y = 0;

	Coordinate() : x(0), y(0) {} // Default constructor
	Coordinate(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	/// <summary>
	/// Operator Overloading, used to compare 2 coordinates
	/// </summary>
	bool operator==(const Coordinate& _other) const
	{
		return (x == _other.x && y == _other.y);
	}
};

