#include "Coords.h"
Coords::~Coords()
{

}

bool Coords::operator==(const Coords & rhs)
{
	return (rhs.x == this->x && rhs.y == this->y);
}
