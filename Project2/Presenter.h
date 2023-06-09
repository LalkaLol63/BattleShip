#pragma once
#include "Area.h" 
class Presenter
{
public:
	virtual void DisplayArea(Area area) = 0;
};

class ConsolePresenter : Presenter
{
public:
	void DisplayArea(Area area) override
	{
		for (int i = area.getRows()-1; i >= 0; i--)
		{
			for (int j = 0; j < area.getRows(); j++)
			{
				std::cout << area.getCellStatus(j,i) << " ";
			}
			std::cout << std::endl;
		}
	}
};
