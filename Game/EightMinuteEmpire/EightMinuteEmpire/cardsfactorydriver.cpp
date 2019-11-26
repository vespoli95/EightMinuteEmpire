#include "Cards.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

static int cardsfactorydriver(){

	bool keepgoing = true;
	int nbPlayers = 0;
	
	cout << "How many players will be playing?" << endl;

	while ((std::cout << "Enter a number from 1 to 5:")	&& (!(std::cin >> nbPlayers) || nbPlayers < 1 || nbPlayers > 5)) {
		std::cout << "That's not a number between 1 and 5; ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	cout << "Setting up deck" << endl;
	Deck* deck = new Deck(nbPlayers);
	deck->toString();

	return 0;
}