#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

bool Player::isShipHit(const Coords& c)
{
	int i = 0;
	for (auto e = ship_vector.begin(); e != ship_vector.end(); ++e) //p�tla por�wnuj�ca strza� z koordyntami statk�w
	{
		if (e->isHit(c)) //je�eli komputer trafi�, usuwamy statek z wektora i zwracamy true
		{
			ship_vector.erase(ship_vector.begin() + i);
			return true;
		}
		++i;
	}
	return false;
}
