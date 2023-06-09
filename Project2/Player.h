#pragma once
#include "MainArea.h"

class Player
{
private:
	MainArea PlayerArea = MainArea(10, empty);
	Area PlayerMask = Area(10, empty);
public:
	Player();

	void PlayerSetup();

	void PlayerMove(MainArea& bot_area);

	int getNumOfAlivedShips();


	MainArea& get_player_area();
};

