#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "Cards.h"

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

	GameStart() {

		Board& mapofworld = Board::getInstance();
		 mapofworld.loadmap();
		 gamedeck = loadDeck(loadPlayers());
		
	};

	int loadPlayers() {
		string playerName;
		int nbPlayers, playerAge, count = 1;
		cout << "\n How many players will be playing?" << endl;
		cin >> nbPlayers;

		for (int i = 0; i < nbPlayers; i++) {

			cout << "Player " << count << " what is your name?" << endl;
			cin >> playerName;
			cout << "Player " << count << " what is your age?" << endl;
			cin >> playerAge;

			Player* tPlayer = new Player(playerName, playerAge);
			count++;

		}
		return nbPlayers;
		//GameStart::loadDeck(nbPlayers);
	}
	
	inline Deck* loadDeck(int nbPlayers) {

		Deck* gamedeck = new Deck(nbPlayers);

		return gamedeck;
	}
	
};