#include <iostream>
#include "Game.h"

int main()
{

	srand(time(NULL));
	int botLevel;
	std::cin >> botLevel;
	Game BattleShip(botLevel);

	BattleShip.startGame();
}
