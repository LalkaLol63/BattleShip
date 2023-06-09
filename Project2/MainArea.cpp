#include "MainArea.h"

MainArea::MainArea(int size, CellStatus startStatus):Area(size, startStatus)
{
}

bool MainArea::placeShip(int startX, int startY, int length, Orientation orientation)
{
	int x = startX;
	int y = startY;

	// Перевірка границь матриці
	bool isWithinBounds = true;
	switch (orientation) {
	case Orientation::NORTH: isWithinBounds = (startY + length <= rows); break;
	case Orientation::EAST: isWithinBounds = (startX + length <= rows); break;
	case Orientation::WEST: isWithinBounds = (startX - length + 1 >= 0); break;
	case Orientation::SOUTH: isWithinBounds = (startY - length + 1 >= 0); break;
	}

	if (isWithinBounds) //якщо сам корабель потрапляє в матрицю, то робимо перевірку всіх клітинок корабля, та клітинок навколо
	{

		for (int i = 0; i < length; i++)
		{
			if (matrix[x][y].getStatus() != empty)
			{
				return false;  // Клітинка є точкою, або зайнята палубою
			}

			if (isShipNearBy(x, y))
			{
				return false; // Клітинки навколо є палубами
			}

			switch (orientation) {
			case Orientation::NORTH: { y++; break; }
			case Orientation::EAST: { x++; break; }
			case Orientation::WEST: { x--; break; }
			case Orientation::SOUTH: { y--; break; }
			}
		}

		// Якщо перевірка пройдена, розміщуємо корабель
		Ship* newShip = new Ship(length, orientation, startX, startY);
		ships.push_back(newShip);
		addShip(*newShip);
		return true;
	}

	return false;  // Вихід за границі поля
}

Ship* MainArea::ShipsCheck(int x, int y)
{
	Ship* killedShip = nullptr;
	for (int i = 0; i < ships.size(); i++)
	{
		if (ships[i]->shipContains(x, y))
		{
			if (isShipKilled(*ships[i]))
			{
				killedShip = new Ship(*ships[i]);
				ships.erase(std::next(ships.begin(), i));
				break;
			}
		}
	}
	return killedShip;
}

bool MainArea::isShipKilled(Ship& shipToCheck)
{
	int tempX = shipToCheck.startX;
	int tempY = shipToCheck.startY;
	int killsCounter = 0;

	for (int i = 0; i < shipToCheck.length; i++)
	{
		if (matrix[tempX][tempY].getStatus() == kill)
		{
			killsCounter++;
		}
		switch (shipToCheck.direction) {
		case Orientation::NORTH: { tempX++; break; }
		case Orientation::EAST: { tempX++; break; }
		case Orientation::WEST: { tempY--; break; }
		case Orientation::SOUTH: { tempY--; break; }
		}
	}
	
	return killsCounter == shipToCheck.length;
}
bool MainArea::isShipNearBy(int x, int y) {

	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			if (!isEdgeCase(i, j)) {
				if (matrix[i][j].getStatus() == deck) {
					return true;  // Клітка навколо є палубою
				}
			}
		}
	}
	return false;
}

bool MainArea::AttackCheck(int x, int y)
{
	if (matrix[x][y].getStatus() == deck)
	{
		matrix[x][y].setStatus(kill);
		return true;
	}
	return false;
}

void MainArea::addShip(Ship& shipToAdd) {

	int x = shipToAdd.startX;
	int y = shipToAdd.startY;
	int length = shipToAdd.length;
	int orientation = shipToAdd.direction;

	for (int i = 0; i < length; i++) {
		matrix[x][y].setStatus(deck);

		switch (orientation) {
		case Orientation::NORTH: {y++; break; }
		case Orientation::EAST: {x++; break; }
		case Orientation::WEST: {x--; break; }
		case Orientation::SOUTH: {y--; break; }
		}
	}
	AreaUpdate(shipToAdd); //заповнити корабель точками по контуру
}

int MainArea::getNumOfShipsAlive()
{
	return ships.size();
}

MainArea::~MainArea()
{
	for (Ship* ship : ships)
	{
		delete ship;
	}
}
