#pragma once
#include "Player.h"
#include "EasyBot.h"
#include "MediumBot.h"
#include "SmartBot.h"

class Game
{
private:
	Player Person;
	Bot* Bot;
public:
	Game(int BotLevel);
	
	bool startGame();

	~Game();
};

