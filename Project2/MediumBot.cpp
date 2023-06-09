#include "MediumBot.h"

MediumBot::MediumBot() :Bot(), FindedX(0), FindedY(0), bot_find_ship(false)
{
}

bool MediumBot::find_new_coordinates()  // знайти нові координати для вистрілу
{
	if (!bot_find_ship)
	{
        return find_rand_coordinates();
	}
	else
	{
        switch (currentDir)
        {
        case NORTH:
            if (!BotMask.isEdgeCase(Botx, Boty+ 1) && BotMask.getCellStatus(Botx, Boty + 1) == empty)
            {
                Boty++; //якщо підходить то змінюємо значення координат для вистрілу
                return true;
            }
            break;
        case EAST:
            if (!BotMask.isEdgeCase(Botx + 1, Boty) && BotMask.getCellStatus(Botx + 1, Boty) == empty)
            {
                Botx++;
                return true;
            }
            break;
        case SOUTH:
            if (!BotMask.isEdgeCase(Boty - 1, Boty) && BotMask.getCellStatus(Boty - 1, Boty) == empty)
            {
                Boty--;
                return true;
            }
            break;
        case WEST:
            if (!BotMask.isEdgeCase(Botx - 1, Boty) && BotMask.getCellStatus(Botx - 1, Boty) == empty)
            {
                Botx--;
                return true;
            }
            break;
        }
        Boty = FindedY;
        Botx = FindedX;//якщо поточний напрямок не підходить 
        currentDir++;
     
        return false;
	}
}
bool MediumBot::Bot_attack(MainArea& Board) //функція атаки бота
{
	if (Board.AttackCheck(Botx, Boty))
	{
		BotMask.setCellStatus(kill, Botx, Boty);

		Ship* checkedShip = BotArea.ShipsCheck(Botx, Boty);
		if (checkedShip != nullptr)
		{
			BotMask.AreaUpdate(*checkedShip);
            bot_find_ship = false;
		}
        else
        {
            if (!bot_find_ship)
            {
                bot_find_ship = true;
                FindedX = Botx;
                FindedY = Boty;
                currentDir = 0;
            }
         }
        delete checkedShip;
        return true;
	}
	else
	{
        BotMask.setCellStatus(occupied, Botx, Boty);
		return false;
	}
}

bool MediumBot::find_rand_coordinates()
{
    do//рандомно знаходимо нові координати
    {
        Botx = rand() % 10;
        Boty = rand() % 10;
    } while (BotMask.getCellStatus(Botx, Boty) != empty);
    return true;
}
