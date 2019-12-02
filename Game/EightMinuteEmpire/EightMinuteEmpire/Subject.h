#pragma once
#include <list>
#include "cards.h"
using namespace std;

class Observer;

class Subject {
public:
	virtual void Attach(Observer* o);
	virtual void Detach(Observer* o);
	virtual void Notify(string method);
	Subject();
	~Subject();
private:
	list<Observer*> *_observers;

};