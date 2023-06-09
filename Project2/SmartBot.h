#pragma once
#include "Bot.h"
class SmartBot : public Bot
{
private:
	int FindedX;
	int FindedY;// ���������� ������������ ������
	std::vector<int> shipToFind;
	bool bot_find_ship; // ������ �� ���������� ��� � ����� ������ �������
	int currentDir;
	bool find_new_coordinates() override; // ������ ��� ���������� ��� �������
	bool find_rand_coordinates();
	bool Bot_attack(MainArea& Board) override; //������� ����� ����
	bool coordinatesCheck(int x, int y);
	bool vectorUpdate(int numDeck);
public:
	SmartBot();
};

