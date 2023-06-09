#include "Game.h"

Game::Game(int BotLevel) : Person()
{
	if (BotLevel == 0)
	{
		Bot = new EasyBot();

	}
	else if (BotLevel == 1)
	{
		Bot = new MediumBot();
	}
	else
	{
		Bot = new SmartBot();
	}
}

bool Game::startGame()
{
	Person.PlayerSetup();
	Bot->BotSetup();

	do
	{
		Person.PlayerMove(Bot->get_bot_area());
		if (Bot->getNumOfAlivedShips() == 0)
		{
			return false;
		}
		Bot->Bot_move(Person.get_player_area());
		if (Person.getNumOfAlivedShips() == 0)
		{
			return false;
		}
	} while (true);
}

Game::~Game()
{
	delete Bot;
}