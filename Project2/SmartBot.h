#pragma once
#include "Bot.h"
class SmartBot : public Bot
{
private:
	int FindedX;
	int FindedY;// координати новознайденої палуби
	std::vector<int> shipToFind;
	bool bot_find_ship; // прапор чи знаходится бот в режимі пошуку корабля
	int currentDir;
	bool find_new_coordinates() override; // знайти нові координати для вистрілу
	bool find_rand_coordinates();
	bool Bot_attack(MainArea& Board) override; //функція атаки бота
	bool coordinatesCheck(int x, int y);
	bool vectorUpdate(int numDeck);
public:
	SmartBot();
};

