//
// Created by Jeff Buonamici on 2019-10-01.
//

#ifndef EIGHTMINUTEEMPIRE_CARDS_H
#define EIGHTMINUTEEMPIRE_CARDS_H

#include <string>

using namespace std;


class Card {
private:
	string* pAction;
	string* pGood;
	int* pCost;
public:
	Card();
	Card(string action, string good);
	string* getAction();
	string* getGood();
	int* getCost();
	void setCost(int cost);
	string toString();
};

class Hand {
private:
	int* cardsInHand;
	Card* hand[6];
public:
	Hand();
	void slideCards(int pos);
	void deal(Card* card);
	void addCard(Card* card);
	Card exchange(int pos);
	void toString();
};

class Deck {
private:
	Card* cards[42];
	int* numOfCards;
public:
	Deck();
	void deal(Hand* hand);
	void addCard(Card* card);
	void draw(Hand* hand);
	Card* draw();
	void toString();
};


#endif //EIGHTMINUTEEMPIRE_CARDS_H

