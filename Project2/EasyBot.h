#pragma once
#include "Bot.h"
class EasyBot : public Bot
{

private: 
	bool find_new_coordinates() override; // ������ ��� ���������� ��� �������

	bool Bot_attack(MainArea& Board) override; //������� ����� ����
};

