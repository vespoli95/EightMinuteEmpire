#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::cin;

class Game{

public:

	static Game& getInstance();
	void loadplayers();

private:

	Game();
	~Game() {};
	
};