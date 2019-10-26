#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "Cards.h"
#include "Player.h"

using std::cout;
using std::endl;
using std::cin;

class GameStart {

public:

	Deck* gamedeck;

	~GameStart() {};

	inline static GameStart& getInstance()
	{
				static GameStart theInstance;

		return theInstance;
	};
	 

private:

	GameStart();

	int loadPlayers();
	
	Deck* loadDeck(int nbPlayers);
	
};