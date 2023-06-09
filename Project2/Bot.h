#pragma once

#include <queue>
#include "MainArea.h"

class Bot {
protected:
	int Botx; // координати для вистрілу
	int Boty; 
	MainArea BotArea;
	Area BotMask;

	virtual bool find_new_coordinates() = 0; // знайти нові координати для вистрілу

	virtual bool Bot_attack(MainArea& Board) = 0; //функція атаки бота

public:

	void BotSetup();
	
	void Bot_move(MainArea& Board);//функція ходу бота

	Bot(); //конструктор бота

	int getNumOfAlivedShips();

	MainArea& get_bot_area();
};
