#include "Cards.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

static int cardsfactorydriver(){


	int nbPlayers = 0;

	cout << "How many players will be playing? (enter number from 1 to 5)" << endl;
	cin >> nbPlayers;
	cout << "Setting up deck" << endl;
	Deck* deck = new Deck(nbPlayers);
	deck->toString();

	return 0;
}