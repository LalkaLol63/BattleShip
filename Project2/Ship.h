#pragma once
#include "enums.h"
class Ship
{
public:

	int length;
	int direction;
	int startX;
	int startY;
	
	Ship(int len, int dir, int x, int y);
	Ship(const Ship& other);
	bool shipContains(int x, int y);
};

