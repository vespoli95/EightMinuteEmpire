//
// Created by Jeff Buonamici on 2019-10-01.
//

#include <iostream>
#include <string>
#include "Cards.h"


using namespace std;

// Function for Card
Card::Card() {
	pAction = new string("");
	pGood = new string("");
	pCost = new int(0);
}

Card::Card(string action, string good) {
	pAction = new string(action);
	pGood = new string(good);
	pCost = new int(0);
}

string* Card::getAction() {
	return pAction;
}

string* Card::getGood() {
	return pGood;
}

int* Card::getCost() {
	return pCost;
}

void Card::setCost(int cost) {
	*pCost = cost;
}

string Card::toString() {
	string cardStr = "Action: " + *pAction + ", Good: " +
		*pGood + ", Cost: " + to_string(*pCost);
	return cardStr;
}

// Functions for Hand
Hand::Hand() {
	cardsInHand = new int(0);
}

void Hand::slideCards(int pos) {
	
	while (pos < 5) {
		hand[pos] = hand[pos + 1];
		if (pos == 0)
			hand[pos]->setCost(0);
		else if (pos > 0 && pos <= 2)
			hand[pos]->setCost(1);
		else if (pos > 2 && pos <= 4)
			hand[pos]->setCost(2);
		else if (pos == 5)
			hand[pos]->setCost(3);
		pos++;
	}
	hand[5] = NULL;
}

void Hand::deal(Card* card) {
	if (*cardsInHand < 6) {
		hand[*cardsInHand] = card;
		if (*cardsInHand == 0)
			hand[*cardsInHand]->setCost(0);
		else if (*cardsInHand > 0 && *cardsInHand <= 2)
			hand[*cardsInHand]->setCost(1);
		else if (*cardsInHand > 2 && *cardsInHand <= 4)
			hand[*cardsInHand]->setCost(2);
		else if (*cardsInHand == 5)
			hand[*cardsInHand]->setCost(3);
		(*cardsInHand)++;
	}
}

void Hand::addCard(Card* card) {
	hand[5] = card;
	card->setCost(3);
}

Card Hand::exchange(int pos) {
	Card card = *hand[pos];
	delete hand[pos];
	hand[pos] = NULL;
	cardsInHand--;
	return card;
}

void Hand::toString() {
	/*cout << "Card1-> " << hand[0]->toString() << endl <<
		"Card2-> " << hand[1]->toString() << endl <<
		"Card3-> " << hand[2]->toString() << endl <<
		"Card4-> " << hand[3]->toString() << endl <<
		"Card5-> " << hand[4]->toString() << endl <<
		"Card6-> " << hand[5]->toString() << endl;*/

	for (int i = 0; i < 6; i++)
	{
		if (hand[i] == NULL) {
			cout << "Card" << i << "-> " << "Empty" << endl;
		}
		else {
			cout << "Card" << i <<"-> " << hand[i]->toString() << endl;
		}
	}
}

// Function for Deck
Deck::Deck() {
	numOfCards = new int(0);
}

void Deck::addCard(Card* card) {
	int topOfDeck = *numOfCards;
	cards[topOfDeck] = card;
	(*numOfCards)++;
}

void Deck::draw(Hand* hand) {
	std::cout << "In: " << endl;
	int topOfDeck = --(*numOfCards);
	std::cout << "In: " << endl;
	hand->addCard(cards[topOfDeck]);
	std::cout << "In: " << endl;
}

Card* Deck::draw() {
	int topOfDeck = --(*numOfCards);
	return cards[topOfDeck];
}

void Deck::toString() {
	cout << "Cards: " << endl << " numOfCards: "
		<< *numOfCards << endl;
}