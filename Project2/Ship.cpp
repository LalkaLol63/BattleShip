#include "Ship.h"

Ship::Ship(int len, int dir, int x, int y):length(len), direction(dir), startX(x), startY(y)
{
}

Ship::Ship(const Ship& other)
{
	this->length = other.length;
	this->direction = other.direction;
	this->startX = other.startX;
	this->startY = other.startY;
}

bool Ship::shipContains(int x, int y)
{
	int CurrentX = startX;
	int CurrentY = startY;

	for (int i = 0; i < length; i++)
	{
		if (CurrentX == x && CurrentY == y)
		{
			return true;
		}

		switch (direction) {
		case Orientation::NORTH: { CurrentY++; break; }
		case Orientation::EAST: { CurrentX++; break; }
		case Orientation::WEST: { CurrentX--; break; }
		case Orientation::SOUTH: { CurrentY--; break; }
		}
	}
	return false;
}
