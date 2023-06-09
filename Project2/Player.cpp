#include "Player.h"

Player::Player() : PlayerMask(10, empty), PlayerArea(10, empty) {}

void Player::PlayerSetup()
{
	int startX, startY, orientation, numOfDecks, numOfCurrentChips;
	for (int i = 1; i < 5; i++)
	{
		int numOfDecks = 5 - i;
		int numOfCurrentShips = i;

		while (numOfCurrentShips > 0)
		{

			std::cin >> startX; //

			std::cin >> startY; // 

			std::cin >> orientation; // 

			Orientation direction = static_cast<Orientation>(orientation);

			if (PlayerArea.placeShip(startX, startY, numOfDecks, direction))
			{
				numOfCurrentShips--;
			}
			else
			{
				std::cout << "error" << std::endl;
			}
		}
	}
}

void Player::PlayerMove(MainArea& bot_area)
{
	bool successShot;
	int XtoShoot;
	int YtoShoot;
	
	do
	{
		if (bot_area.getNumOfShipsAlive() == 0)
		{
			break;
		}
		std::cin >> XtoShoot;
		std::cin >> YtoShoot;
		if (bot_area.AttackCheck(XtoShoot, YtoShoot))
		{
			PlayerMask.setCellStatus(kill, XtoShoot, YtoShoot);

			Ship* checkedShip = bot_area.ShipsCheck(XtoShoot, YtoShoot);
			if (checkedShip != nullptr)
			{
				PlayerMask.AreaUpdate(*checkedShip);
			}
			delete checkedShip;
			successShot = true;
		}
		else
		{
			PlayerMask.setCellStatus(occupied, XtoShoot, YtoShoot);
			successShot = false;
		}

	} while (successShot);
}

int Player::getNumOfAlivedShips()
{
	return PlayerArea.getNumOfShipsAlive();
}
MainArea& Player::get_player_area()
{
	return PlayerArea;
}