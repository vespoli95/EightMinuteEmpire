#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::cin;

class GameStart {

public:

	inline static GameStart& getInstance()
	{
				static GameStart theInstance;

		return theInstance;
	};

	inline void loadplayers() {
		//do something2 
	};
	
	~GameStart() {};


private:

	inline GameStart() {

		Board& mapofworld = Board::getInstance();
		mapofworld.loadmap();


	};
	
	
};