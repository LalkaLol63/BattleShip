#pragma once
#include "Bot.h"
class MediumBot : public Bot
{
private:
	int FindedY;// координати новознайденої палуби

	bool bot_find_ship; // прапор чи знаходится бот в режимі пошуку корабля
	int currentDir;
	bool find_new_coordinates() override; // знайти нові координати для вистрілу
	bool find_rand_coordinates();
	bool Bot_attack(MainArea& Board) override; //функція атаки бота
public:
	MediumBot();
};

