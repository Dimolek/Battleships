#pragma once
#include "IGameObserver.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"
#include "Ship.h"
#include <list>
#include <vector>
#include <iostream>

class Game
{
private:
	HumanPlayer h_player;
	ComputerPlayer c_player;
	std::vector<IGameObserver*> observer_vector; //wektor obserwatorow
	int map_size;
	int number_of_ships;

public:
	//konstruktory/destruktory
	Game(int x = 0, int y = 0) : map_size(x), number_of_ships(y) {}
	~Game();

	//akcesory
	std::vector<Ship> get_computerShips() const {return c_player.get_shipVector();} //pobranie wektora statków gracza komputerowego
	std::vector<Ship> get_humanShips() const {return h_player.get_shipVector();} //pobranie wektora statków gracza ludzkiego
	int get_humanCounter() const {return h_player.get_score();} //pobranie wyniku
	int get_size() const {return map_size;}; //pobranie rozmiaru mapy
	int get_shipsAmount() const {return number_of_ships;}; //pobranie iloœci statków do ustawienia

	//metody
	bool registerObserver(IGameObserver*); //dodanie obserwatora

	void addShips(std::vector<Ship>); //uruchomienie metody inicjalizuj¹cej wektor statków gracza ludzkiego
	void computeraddShips(); //uruchomienie metody tworzêcej wektor statków gracza komputerowego

	void computerTurn(); //zarz¹dzanie tur¹ komputera
	void humanTurn(const Coords &); //zarz¹dzanie tur¹ gracza ludzkiego
	bool gameEnded(); //sprawdzenie, czy gra siê nie skoñczy³a(któryœ z wektorów statków nie jest pusty)
};