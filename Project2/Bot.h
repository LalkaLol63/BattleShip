#pragma once

#include <queue>
#include "MainArea.h"

class Bot {
protected:
	int Botx; // ���������� ��� �������
	int Boty; 
	MainArea BotArea;
	Area BotMask;

	virtual bool find_new_coordinates() = 0; // ������ ��� ���������� ��� �������

	virtual bool Bot_attack(MainArea& Board) = 0; //������� ����� ����

public:

	void BotSetup();
	
	void Bot_move(MainArea& Board);//������� ���� ����

	Bot(); //����������� ����

	int getNumOfAlivedShips();

	MainArea& get_bot_area();
};
