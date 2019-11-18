#include "GameObservers.h"
#include <iostream>
using namespace std;

int main() {
	//initialize board
	Board *board = Board::getInstance();
	board->loadmap();

	Player *p = new Player("Anthony", 24);
	Player *p2 = new Player("Tim", 24);
	GameObserver *game_observer = new GameObserver(p);
	GameObserver *game_observer2 = new GameObserver(p2);

	p2->PlaceNewArmies({ {"R09", 3} }, true, *board);
	p->BuildCity({ {"R09", 1} }, *board);
	p->PlaceNewArmies({ {"R09", 3} }, true, *board);
	p->BuildCity({ {"R09", 1} }, *board);
	p->DestroyArmy("Tim", "R09", *board);
	p->MoveArmies(false, 2, { {"R09", "R10"} }, *board);

	getchar();
	getchar();

	return 0;
}