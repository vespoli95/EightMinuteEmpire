#include "map.h"
#include "GameStart.h"
#include <iostream>
#include <fstream>


using std::cout;
using std::endl;
using std::cin;


GameStart::GameStart() {
	gamedeck = NULL;
	Board& mapofworld = Board::getInstance();
	if (mapofworld.loadmap()) {
		EXIT_FAILURE;
	}
	else
	{
		gamedeck = loadDeck(loadPlayers());
	}


}

int GameStart::loadPlayers() {
	string playerName;
	int nbPlayers, playerAge, count = 1;
	cout << "\n How many players will be playing?" << endl;
	cin >> nbPlayers;

	if (nbPlayers <= 0) {

		return 0;
	}
	else {

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


}

Deck* GameStart::loadDeck(int nbPlayers) {

	if (nbPlayers == 0) {

		cout << "You need at least 1 player, please try again later" << endl;
	}

	else {
		Deck* gamedeck = new Deck(nbPlayers);

		return gamedeck;
	}
}

GameStart& GameStart::getInstance()
{
	static GameStart gameInstance;

	return gameInstance;
};