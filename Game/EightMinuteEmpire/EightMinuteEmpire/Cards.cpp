//
// Created by Jeff Buonamici on 2019-10-01.
//

#include <iostream>
#include <string>
#include "Cards.h"
#include <time.h>
#include "Cardsfactory.h"


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
	//delete hand[pos];
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
			cout << "Card" << i << "-> " << hand[i]->toString() << endl;
		}
	}
}

// Function for Deck
Deck::Deck() {
	numOfCards = new int(0);
}

Deck::Deck(int numPlayers) {
	numOfCards = new int(0);
	initialize(numPlayers);
}

void Deck::addCard(Card* card) {
	int topOfDeck = *numOfCards;
	cards->push_back(*card);
	//cards->at(topOfDeck) = *card;
	(*numOfCards)++;
}

void Deck::draw(Hand* hand) {
	std::cout << "In: " << endl;
	int topOfDeck = --(*numOfCards);
	std::cout << "In: " << endl;
	hand->addCard(&cards->at(topOfDeck));
	std::cout << "In: " << endl;
}

Card* Deck::draw() {
	int topOfDeck = --(*numOfCards);
	return &cards->at(topOfDeck);
}

void Deck::shuffle() {
	int num = cards->size() - 1;
	srand(time(NULL));

	// Starting with the last element in array
	// Swap it to a random position in the array.
	for (int i = num; i > 0; i--) {

		// Random value from 0 to i
		int j = rand() % (i + 1);

		// Swap positions
		Card temp = cards->at(i);
		cards->at(i) = cards->at(j);
		cards->at(j) = temp;
	}
}

void Deck::toString() {
	cout << "Cards: " << endl;

	for (int i = 0; i < cards->size(); i++) {
		cout << cards->at(i).toString() << endl;
	}

	cout << "numOfCards: " << *numOfCards << endl;
}

//TODO: create a Deck of cards using the Factory Design Pattern
void Deck::initialize(int numPlayers) {
	cout << "Creating Deck..." << endl;

	cards = new vector<Card>;
	Card* card1 = new Card("Move 3 Armies", "Forest");
	Card* card2 = new Card("Add 3 Armies", "Forest");

	Card* card4 = new Card("Destroy 1 Army or Build City", "Forest");
	Card* card5 = new Card("Add 2 Armies or Move 3 Armies", "Forest");
	Card* card6 = new Card("Move 4 Armies via Ship", "Forest");
	Card* card7 = new Card("Build City", "Forest");
	Card* card8 = new Card("Move 3 Armies via Ship", "Forest");
	Card* card9 = new Card("Build City", "Carrot");
	Card* card10 = new Card("Destroy 1 Army and Add 1 Army", "Carrot");
	Card* card11 = new Card("Add 3 Armies", "Carrot");
	Card* card12 = new Card("Move 4 Armies", "Carrot");
	Card* card13 = new Card("Move 5 Armies", "Carrot");
	Card* card14 = new Card("Add 3 Armies", "Carrot x 2");
	Card* card15 = new Card("Move 3 Armies via Ship", "Carrot");

	Card* card17 = new Card("Move 4 Armies", "Carrot");
	Card* card18 = new Card("Build City", "Carrot");

	Card* card20 = new Card("Add 3 Armies or move 4 Armies", "Anvil");
	Card* card21 = new Card("Move 3 Armies via Ship", "Anvil");
	Card* card22 = new Card("Build City", "Anvil");
	Card* card23 = new Card("Move 4 Armies", "Anvil x 2");
	Card* card24 = new Card("Add 3 Armies or Move 3 Armies", "Anvil");
	Card* card25 = new Card("Move 5 Armies", "Anvil");
	Card* card26 = new Card("Add 3 Armies", "Anvil");
	Card* card27 = new Card("Move 2 Armies", "Ore");
	Card* card28 = new Card("Move 3 Armies via Ship", "Ore");

	Card* card30 = new Card("Move 2 Armies via Ship", "Ore");
	Card* card31 = new Card("Add 3 Armies", "Ore");
	Card* card32 = new Card("Add 3 Armies", "Ore");
	Card* card33 = new Card("Add 2 Armies", "Ore");
	Card* card34 = new Card("Add 2 Armies", "Crystal");
	Card* card35 = new Card("Add 2 Armies", "Crystal");
	Card* card36 = new Card("Move 2 Armies", "Crystal");
	Card* card37 = new Card("Add 1 Army", "Crystal");

	Card* card39 = new Card("Move 2 Armies", "Wild");
	Card* card40 = new Card("Move 2 Armies", "Wild");
	Card* card41 = new Card("Add 2 Armies", "Wild");
	Card* card42 = new Card("Add 3 Armies", "Anvil");

	this->addCard(card1);
	this->addCard(card2);

	this->addCard(card4);
	this->addCard(card5);
	this->addCard(card6);
	this->addCard(card7);
	this->addCard(card8);
	this->addCard(card9);
	this->addCard(card10);
	this->addCard(card11);
	this->addCard(card12);
	this->addCard(card13);
	this->addCard(card14);
	this->addCard(card15);

	this->addCard(card17);
	this->addCard(card18);

	this->addCard(card20);
	this->addCard(card21);
	this->addCard(card22);
	this->addCard(card23);
	this->addCard(card24);
	this->addCard(card25);
	this->addCard(card26);
	this->addCard(card27);
	this->addCard(card28);

	this->addCard(card30);
	this->addCard(card31);
	this->addCard(card32);
	this->addCard(card33);
	this->addCard(card34);
	this->addCard(card35);
	this->addCard(card36);
	this->addCard(card37);

	this->addCard(card39);
	this->addCard(card40);
	this->addCard(card41);
	this->addCard(card42);

	if (numPlayers == 5) {
		Card* card3 = new Card("Move 6 Armies", "Forest");
		Card* card16 = new Card("Add 3 Armies", "Carrot x 2");
		Card* card19 = new Card("Move 4 Armies", "Anvil x2");
		Card* card29 = new Card("Move 2 Armies via Ship", "Ore");
		Card* card38 = new Card("Add 2 Armies", "Crystal");

		this->addCard(card3);
		this->addCard(card16);
		this->addCard(card19);
		this->addCard(card29);
		this->addCard(card38);
	}

}
