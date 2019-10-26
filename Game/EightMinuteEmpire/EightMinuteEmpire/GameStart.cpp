#include "GameStart.h"
#include <iostream>
#include <fstream>


using std::cout;
using std::endl;
using std::cin;

GameStart::GameStart() {

	Board& mapofworld = Board::getInstance();
	mapofworld.loadmap();
	gamedeck = loadDeck(loadPlayers());

}

int GameStart::loadPlayers() {
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
	
}

Deck* GameStart::loadDeck(int nbPlayers) {

	Deck* gamedeck = new Deck(nbPlayers);

	return gamedeck;
}

GameStart& GameStart::getInstance()
{
	static GameStart gameInstance;

	return gameInstance;
};

int GameLoader()
{

	GameStart& gameplay = GameStart::getInstance();
	

	return 0;
}