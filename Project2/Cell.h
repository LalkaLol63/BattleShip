#pragma once
#include "enums.h"

class Cell
{
private:
	int status;
public:
	Cell();

	Cell(CellStatus newStatus);

	int getStatus() const;

	void setStatus(CellStatus newStatus);
};

