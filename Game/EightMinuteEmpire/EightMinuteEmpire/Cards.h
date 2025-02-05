//
// Created by Jeff Buonamici on 2019-10-01.
//

#ifndef EIGHTMINUTEEMPIRE_CARDS_H
#define EIGHTMINUTEEMPIRE_CARDS_H

#include <string>
#include <vector>

using namespace std;


class Card {
private:
	/*Made this PROTECTED for Assignment 4 Part 1*/
	//string* pAction;
	//string* pGood;
	//int* pCost;


public:
	Card();
	Card(string action, string good);
	string* getAction();
	string* getGood();
	int* getCost();
	void setCost(int cost);
	virtual string toString();
	~Card() {};

protected:
	string* pAction;
	string* pGood;
	int* pCost;
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
	vector<Card>* cards;
	int* numOfCards;
	void initialize(int numPlayers);
public:
	Deck();
	Deck(int numPlayers);
	//void deal(Hand* hand);
	void addCard(Card* card);
	void draw(Hand* hand);
	void shuffle();
	Card* draw();
	void toString();
};


#endif //EIGHTMINUTEEMPIRE_CARDS_H

