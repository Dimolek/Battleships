#pragma once
#include "Coords.h"
class IGameObserver
{
public:
	//konstruktory/destruktory
	IGameObserver(){}
	virtual ~IGameObserver(){}

	//metody czysto wirtualne
	virtual void computerScored(const Coords &) = 0; //komputer trafia
	virtual void computerMissed(const Coords &) = 0; //komputer nie trafia
	virtual void humanScored(const Coords &) = 0; //gracz ludzki trafia
	virtual void humanMissed(const Coords &) = 0; //gracz ludzki nie trafia
};