#pragma once
#include "Bot.h"
class EasyBot : public Bot
{

private: 
	bool find_new_coordinates() override; // знайти нові координати для вистрілу

	bool Bot_attack(MainArea& Board) override; //функція атаки бота
};

