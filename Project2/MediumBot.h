#pragma once
#include "Bot.h"
class MediumBot : public Bot
{
private:
	int FindedX;
	int FindedY;// ���������� ������������ ������

	bool bot_find_ship; // ������ �� ���������� ��� � ����� ������ �������
	int currentDir;
	bool find_new_coordinates() override; // ������ ��� ���������� ��� �������
	bool find_rand_coordinates();
	bool Bot_attack(MainArea& Board) override; //������� ����� ����
public:
	MediumBot();
};

