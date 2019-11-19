#include "GameObservers.h"
#include <iostream>
#include <map>
using namespace std;

static bool checkEndGame(Player* p, Player* p2) {
	if (p->getNbCards() >= 8 && p2->getNbCards() >= 8) {
		cout << "The game has ended!" << endl;
		return true;
	}
	else
		return false;
}

int StatDriver() {
	//initialize board
	Board* board = Board::getInstance();
	if (board->loadmap()) {
		EXIT_FAILURE;
	}



	Deck* deck = new Deck(3);
	deck->toString();
	cout << "Shuffling Deck..." << endl;
	deck->shuffle();
	deck->toString();

	Hand* hand = new Hand();

	cout << "Drawing Hand..." << endl;

	hand->deal(deck->draw());
	hand->deal(deck->draw());
	hand->deal(deck->draw());
	hand->deal(deck->draw());
	hand->deal(deck->draw());
	hand->deal(deck->draw());

	Player* p = new Player("Anthony", 24);
	Player* p2 = new Player("Tim", 24);
	GameObserver* game_observer = new GameObserver(p);
	GameObserver* game_observer2 = new GameObserver(p2);
	StatisticsObserver* stats_observer = new StatisticsObserver(p);
	StatisticsObserver* stats_observer2 = new StatisticsObserver(p2);

	p2->PlaceNewArmies({ {"R09", 2} }, true, *board);
	p2->BuildCity({ {"R09", 1} }, *board);
	p->PlaceNewArmies({ {"R09", 2} }, true, *board);
	p->BuildCity({ {"R09", 1} }, *board);
	p->DestroyArmy("Tim", "R09", *board);
	p->setGoods("Forest");
	p->setGoods("Forest");
	p->setGoods("Forest");
	p->setScore(p->computeGoods());

	map<string, Region*> regions = board->getWorldMap();
	//check if adding armies worked
	map<string, Region*>::iterator region2;
	map<string, int>::iterator it2;

	for (region2 = regions.begin(); region2 != regions.end(); region2++) {
		cout << region2->first << ":" << endl;
		for (it2 = region2->second->getArmies()->begin(); it2 != region2->second->getArmies()->end(); it2++)
			cout << "\tname: " << it2->first << ", #: " << it2->second << endl;
	}

	/*map<string, Continent*> continents = board->getContinents();
	map<string, Continent*>::iterator it;
	for (it = continents.begin(); it != continents.end(); it++)
	{
		determineContinentOwner(it->first, it->second->regionList);
	}*/
	
	for (int i = 0; i < 8; i++) {
		p->addCardToHand(hand->exchange(0));
		hand->slideCards(0);
		hand->addCard(deck->draw());
		p2->addCardToHand(hand->exchange(0));
		hand->slideCards(0);
		hand->addCard(deck->draw());
		if (checkEndGame(p, p2)) {
			p->Notify("EndGame");
			p2->Notify("EndGame");
		}
	}


	cin.get();
	cin.get();

	return 0;
}