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
	for (auto e = ship_vector.begin(); e != ship_vector.end(); ++e) //pêtla porównuj¹ca strza³ z koordyntami statków
	{
		if (e->isHit(c)) //je¿eli komputer trafi³, usuwamy statek z wektora i zwracamy true
		{
			ship_vector.erase(ship_vector.begin() + i);
			return true;
		}
		++i;
	}
	return false;
}
