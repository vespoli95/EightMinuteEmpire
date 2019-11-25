#include "Cards.h"
#include <iostream>

using std::cout;
using std::endl;

class AnvilCard : public Card {

	static vector<string> vect;

public:

	AnvilCard() {
		int randNum = rand() % (vect.size()-1 + 1);
		cout << "Size : " << vect.size() << endl; //for debugging only, remove when not needed
		this->pGood = new string("Anvil");
		this->pAction = new string(vect.back());
		this->pCost = new int(0);
		cout << this->toString() << endl; //for debugging only, remove when not needed
		vect.pop_back();
		


	}	
	
	AnvilCard(bool special) {
		
		this->pGood = new string("Anvil");
		this->pAction = new string("Move 4 Armies");

	}

	string toString() {
		string cardStr = "Action: " + *pAction + ", Good: " +
			*pGood + ", Cost: " + to_string(*pCost);
		return cardStr;
	}

	~AnvilCard() {};

};

class CarrotCard : public Card {

	static vector<string> vect;

public:

	CarrotCard() {
		this->pGood = new string("Carrot");


	}

	CarrotCard(bool special) {
		this->pGood = new string("Carrot");
		this->pAction = new string("Add 3 Armies");

	}

	//string Card::toString() {
	//	string cardStr = "Action: " + *pAction + ", Good: " +
	//		*pGood + ", Cost: " + to_string(*pCost);
	//	return cardStr;
	//}

	~CarrotCard() {};
};

class CrystalCard : public Card {

	static vector<string> vect;

public:

	CrystalCard() {

		this->pGood = new string("Crystal");


	}
		
	CrystalCard(bool special) {

		this->pGood = new string("Crystal");
		this->pAction = new string("Add 2 Armies");

	}

	//string Card::toString() {
	//	string cardStr = "Action: " + *pAction + ", Good: " +
	//		*pGood + ", Cost: " + to_string(*pCost);
	//	return cardStr;
	//}

	~CrystalCard() {};

};

class ForestCard : public Card {

	static vector<string> vect;

public:

	ForestCard() {

		this->pGood = new string("Forest");

	}
		
	ForestCard(bool special) {

		this->pGood = new string("Forest");
		this->pAction = new string("Move 6 Armies");

	}

	//string Card::toString() {
	//	string cardStr = "Action: " + *pAction + ", Good: " +
	//		*pGood + ", Cost: " + to_string(*pCost);
	//	return cardStr;
	//}

	~ForestCard() {};
};

class OreCard : public Card {

	static vector<string> vect;

public:

	OreCard() {

		this->pGood = new string("Ore");


	}
		
	OreCard(bool special) {

		this->pGood = new string("Ore");
		this->pAction = new string("Move 2 Armies via Ship");

	}

	//string Card::toString() {
	//	string cardStr = "Action: " + *pAction + ", Good: " +
	//		*pGood + ", Cost: " + to_string(*pCost);
	//	return cardStr;
	//}

	~OreCard() {};

};

class WildCard : public Card {

	static vector<string> vect;

public:


	WildCard() {

		this->pGood = new string("Wild");


	}

	//string Card::toString() {
	//	string cardStr = "Action: " + *pAction + ", Good: " +
	//		*pGood + ", Cost: " + to_string(*pCost);
	//	return cardStr;
	//}

	~WildCard() {};
	
};
