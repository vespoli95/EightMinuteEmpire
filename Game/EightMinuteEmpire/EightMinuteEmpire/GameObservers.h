#pragma once
#include "Observer.h"
#include "Player.h"

//ConcreteObserver
class GameObserver : public Observer
{
public:
	GameObserver();
	GameObserver(Player* s);
	~GameObserver();
	void Update(string method);
	void display(string method);
	void stats();
	void setSubject(Player*);

private:
	Player *_subject;
};
