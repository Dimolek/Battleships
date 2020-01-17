#pragma once
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <algorithm>

class FileOperations
{
public:
	//konstruktory/destruktory
	FileOperations();
	~FileOperations();

	//metody
	static void save(const int&, const std::string &); //dodaje wygranego do listy zwyci�zc�w
	static std::vector<std::pair<std::string, int>> load(); //wczytuje list� zwyci�zc�w do wektora, oraz j� sortuje
};