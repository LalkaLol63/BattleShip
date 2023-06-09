#pragma once
#include "Cell.h"
#include <iostream>
#include <vector>
#include "enums.h"
#include "Ship.h"

class Area
{
protected:

	std::vector<std::vector<Cell> > matrix;
	int rows;

public:

	Area(int size, CellStatus startStatus);

	bool isEdgeCase(int x, int y);

	void Clear(); 

	bool setCellStatus(CellStatus status, int x, int y);

	int getRows() const;

	int getCellStatus(int x, int y) const;

	void AreaUpdate(Ship& ship);
};
