#pragma once
#include "Cards.h"

class Observer {
public:
	~Observer();
	virtual void Update(string method) = 0;
protected:
	Observer();
};