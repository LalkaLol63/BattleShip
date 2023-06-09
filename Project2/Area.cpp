#include "Area.h"

Area::Area(int size, CellStatus startStatus)
{
	this->rows = size;
	for (int i = 0; i < rows; i++)
	{
		std::vector<Cell> row;
		for (int j = 0; j < rows ; j++)
		{
			row.push_back(Cell(startStatus));
		}
		matrix.push_back(row);
	}
}

void Area::Clear()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			matrix[i][j].setStatus(empty);
		}
	}
}

bool Area::setCellStatus(CellStatus newState, int x, int y)
{
	if (!isEdgeCase(x, y))
	{
		matrix[x][y].setStatus(newState);
		return true;
	}
	else
	{
		return false;
	}
}

int Area::getCellStatus(int x, int y) const
{
	return matrix[x][y].getStatus();
}

bool Area::isEdgeCase(int x, int y) {
	if (x < 0 || x > this->rows - 1) {
		return true;
	}

	if (y < 0 || y >this->rows -1 ) {
		return true;
	}

	return false;
}

int Area::getRows() const
{
	return this->rows;
}

void Area::AreaUpdate(Ship& ship)
{
	int direction = ship.direction;
	int currentX= ship.startX;
	int currentY = ship.startY;
	int length = ship.length;
	
	for (int l = 0; l < length; l++)
	{
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				int newX = currentX + i;
				int newY = currentY + j;

				if (!isEdgeCase(newX, newY))
				{
					if (matrix[newX][newY].getStatus() == empty)
					{
						matrix[newX][newY].setStatus(occupied);
					}
				}
			}
		}
		switch (direction) {
		case Orientation::NORTH: {currentY++; break; }
		case Orientation::EAST: {currentX++; break; }
		case Orientation::WEST: {currentX--; break; }
		case Orientation::SOUTH: {currentY--; break; }
		}
	}
}