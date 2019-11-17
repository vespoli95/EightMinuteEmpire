#pragma once
#include <list>
#include "Observer.h"
using namespace std;

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