#pragma once
#include "Cards.h"

class PlayerStrategy{
public:
	virtual int execute(Hand* hand, string playerName, int playerCoins) = 0;
};

class realPlayer : public PlayerStrategy {
public:
	int execute(Hand* hand, string playerName, int playerCoins);
};
class greedyComputer : public PlayerStrategy {
public:
	int execute(Hand* hand, string playerName, int playerCoins);
};
class moderateComputer : public PlayerStrategy {
public:
	int execute(Hand* hand, string playerName, int playerCoins);
};


