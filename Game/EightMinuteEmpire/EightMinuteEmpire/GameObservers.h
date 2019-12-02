#pragma once
#include "Player.h"

class Observer {
public:
	~Observer() {};
	virtual void Update(string method) = 0;
protected:
	Observer() {};
};

//ConcreteObserver
class GameObserver : public Observer
{
public:
	GameObserver();
	GameObserver(Player* s);
	~GameObserver();
	void Update(string method);
	void display(string method);
	void setSubject(Player*);

private:
	Player *_subject;
};

class StatisticsObserver : public Observer
{
	public:
		StatisticsObserver();
		StatisticsObserver(Player* p);
		~StatisticsObserver();
		void Update(string method);
		void display(string method);
		void setSubject(Player*);
	private:
		Player* _subject;
};
