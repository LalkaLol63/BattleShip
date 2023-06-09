#include "Bot.h"
#include <iostream>
#include "Presenter.h"

Bot::Bot() :Botx(0), Boty(0), BotMask(10, empty), BotArea(10, empty) {}

void Bot::BotSetup()
{
	int startX, startY, numOfDecks, numOfCurrentChips;
	Orientation orientation;
	for (int i = 1; i < 5; i++)
	{
		int numOfDecks = 5 - i;
		int numOfCurrentShips = i;

		while (numOfCurrentShips > 0)
		{
			do {
				startX = rand() % 10; //

				startY = rand() % 10; // 

				orientation = static_cast<Orientation>(rand() % 4);

			} while (!BotArea.placeShip(startX, startY, numOfDecks, orientation));

			numOfCurrentShips--;
		}
	}
}
void Bot::Bot_move(MainArea& Player_Board)
{
	do {
		if (Player_Board.getNumOfShipsAlive() == 0)
		{
			break;
		}
		while (!find_new_coordinates()) {}//знаходимо нові координати
	} while (Bot_attack(Player_Board)); //якщо бот промахнувся, то хід бота переходить до гравця і хід бота завершено

}

int Bot::getNumOfAlivedShips()
{
	return BotArea.getNumOfShipsAlive();
}

MainArea& Bot::get_bot_area()
{
	return BotArea;
}
