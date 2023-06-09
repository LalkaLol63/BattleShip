#pragma once
#include "Area.h"

class MainArea : public Area
{
private:

	std::vector<Ship*> ships;

	void addShip(Ship& shipToAdd);

	bool isShipNearBy(int x, int y);

	bool isShipKilled(Ship& shipToCheck);
	
public:

	MainArea(int size, CellStatus startStatus);
	bool placeShip(int startX, int startY, int length, Orientation orientation);
	Ship* ShipsCheck(int x, int y);
	bool AttackCheck(int x, int y);
	int getNumOfShipsAlive();
	~MainArea();
};

