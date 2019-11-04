#pragma once
#include "Player.h"

//using std::cout;
//using std::endl;
//using std::cin;



class GameStart {

public:

	GameStart();

	~GameStart() {};

	static GameStart& getInstance();



private:

	int loadPlayers();

	Deck* loadDeck(int nbPlayers);

	Deck* gamedeck;
};

