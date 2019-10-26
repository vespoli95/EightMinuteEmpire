#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "Cards.h"
#include "Player.h"
#include "map.h"

using std::cout;
using std::endl;
using std::cin;

class GameStart {

public:

	Deck* gamedeck;

	~GameStart() {};

	static GameStart& getInstance();
	 
	GameStart();
private:

	int loadPlayers();
	
	Deck* loadDeck(int nbPlayers);
	
};