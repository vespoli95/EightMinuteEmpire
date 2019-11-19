#include "GameObservers.h"
#include "Player.h"
#include <iostream>
using std::cout;
using std::endl;

GameObserver::GameObserver() {};

GameObserver::GameObserver(Player* s)
{
	_subject = s;
	_subject->Attach(this);
};

GameObserver::~GameObserver()
{

	_subject->Detach(this);
};

void GameObserver::Update(string method)
{

	display(method);
};

void GameObserver::display(string method)
{
	map<string, int> *placed_new_armies = _subject->getPlacedNewArmies();
	string *city_built = _subject->getCityBuilt();
	map<string, string> *army_destroyed = _subject->getArmyDestroyed();
	map<string, string> *move_army = _subject->getMoveArmy();

	cout << endl;

	if (method == "PlaceNewArmies")
		cout << *_subject->getName() << " placed "  << placed_new_armies->begin()->second << " armies on region " << placed_new_armies->begin()->first << endl;
	else if (method == "BuildCity")
		cout << *_subject->getName() << " built a city on region " << *city_built << endl;
	else if (method == "DestroyArmy")
		cout << *_subject->getName() << " destroyed 1 of " << army_destroyed->begin()->first << "'s armies on region " << army_destroyed->begin()->second << endl;
	else if (method == "MoveArmies")
		cout << *_subject->getName() << " moved an army from region " << move_army->begin()->first << " to " << move_army->begin()->second << endl;

	cout << endl;

}

void GameObserver::setSubject(Player *s)
{
	_subject = s;
	_subject->Attach(this);
}


StatisticsObserver::StatisticsObserver() {};

StatisticsObserver::StatisticsObserver(Player* p)
{
	_subject = p;
	_subject->Attach(this);
};

StatisticsObserver::~StatisticsObserver()
{

	_subject->Detach(this);
};

void StatisticsObserver::Update(string method)
{
	display(method);
};

void StatisticsObserver::display(string method)
{
	string name = *_subject->getName();
	int* coins = _subject->getCoins();
	int points = _subject->getScore();
	int* citiesLeft = _subject->getCities();
	int cities = 3 - *citiesLeft;
	if (method == "EndGame") {
		cout << name << " has " << points << " points." << endl;
		cout << name << " has " << *coins << " coins." << endl;
		cout << name << " has " << points << " points." << endl;
		cout << name << " has " << cities << " cities placed." << endl;
	}
	else {
		if (method == "PlaceNewArmies" || method == "BuildCity" || method == "DestroyArmy" || method == "MoveArmies") {
			cout << name << " has " << *coins << " coins." << endl;
			cout << name << " has " << points << " points." << endl;
			cout << name << " has " << cities << " cities placed." << endl;
		} else 
			cout << method << endl;
	}
}

void StatisticsObserver::setSubject(Player* p)
{
	_subject = p;
	_subject->Attach(this);
}

