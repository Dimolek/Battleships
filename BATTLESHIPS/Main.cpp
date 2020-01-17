#include "SFML/Graphics.hpp"
#include <iostream>
#include "GUI.h"
#include "Game.h"
#define WIDTH 800// 1024
#define HEIGHT 600// 768
#define MAP_SIZE 5
#define SHIPS_AMOUNT 5

int main()
{	
	Game GameObj(MAP_SIZE, SHIPS_AMOUNT);
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Statki", sf::Style::Close);
	window.setVerticalSyncEnabled(true);
	//window.setFramerateLimit(120);
	GUI GUI(GameObj, WIDTH, HEIGHT, GameObj.get_size(), GameObj.get_shipsAmount());

	GameObj.registerObserver(&GUI);
	try	{ GUI.drawMenu(window, WIDTH, HEIGHT, GameObj); }
	catch (const std::runtime_error& error)
	{ std::cout << error.what();
	system("PAUSE");}
}