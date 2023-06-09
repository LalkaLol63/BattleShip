#include "EasyBot.h"

bool EasyBot::find_new_coordinates()  // ������ ��� ���������� ��� �������
{
    do//�������� ��������� ��� ����������
    {
        Botx = rand() % 10;
        Boty = rand() % 10;
    }while (BotMask.getCellStatus(Botx, Boty) != empty);
	return true;
}
bool EasyBot::Bot_attack(MainArea& Board) //������� ����� ����
{
	if (Board.AttackCheck(Botx, Boty))
	{
		BotMask.setCellStatus(kill, Botx, Boty);

		Ship* checkedShip = BotArea.ShipsCheck(Botx, Boty);
		if (checkedShip != nullptr)
		{
			BotMask.AreaUpdate(*checkedShip);
		}
		delete checkedShip;
		return true;
	}
	else
	{
		return false;
	}
} 