#include "Coords.h"
#include "HumanPlayer.h"

HumanPlayer::~HumanPlayer()
{

}

//void HumanPlayer::initShipVector(const std::vector<Ship> & c) // inicjalizacja wektora statkow
//{
//	ship_vector = c; 
//}

//niewykorzystane

/*bool HumanPlayer::checkHit(Coords & c) //sprawdzenie trafienia statku
{
	bool result = false;
	
	for (auto x = ship_vector.begin(); x != ship_vector.end(); ++x)
		if (x->isHit(c)) 
		{ 
			
			result = true;
		}
	
	return result;
}

bool HumanPlayer::isSunk(Coords & c)
{
	bool result = false;
	
	for (auto x = ship_vector.begin(); x != ship_vector.end(); ++x)
		if (x->isHit(c)) 
		{   
			if (x->getCounter() == 0)
			{
				result = true;
				ship_vector.erase(x);
			}
		}
	return result;
}*/