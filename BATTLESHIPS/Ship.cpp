#include "Coords.h"
#include "Ship.h"

Ship::Ship()
{

}
Ship::Ship(const std::vector<Coords> & c)
{
	ship_length = c.size();
	ship_coords = c;
}
Ship::~Ship()
{

}	

bool Ship::isHit(const Coords & c)
{
	for (auto e = ship_coords.begin(); e != ship_coords.end(); ++e)
	{
		if (*e == c)
		{ 
			return true; 
		}
	}	
	return false;
}