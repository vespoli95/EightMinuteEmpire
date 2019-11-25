#include "Cards.h"
#include <iostream>

using std::cout;
using std::endl;

class AnvilCard : public Card {

	static vector<string> vect;

public:

	AnvilCard() {

		this->pGood = new string("Anvil");
		this->pAction = new string(vect.back());
		this->pCost = new int(0);
		//cout << *pGood <<" Size : " << vect.size() << endl; //for debugging only, remove when not needed
		//cout << this->toString() << endl; //for debugging only, remove when not needed
		vect.pop_back();
				
	}	
	
	AnvilCard(bool special) {
		
		this->pGood = new string("Anvil");
		this->pAction = new string("Move 4 Armies");
		this->pCost = new int(0);
	}
	
	~AnvilCard() {};

};

class CarrotCard : public Card {

	static vector<string> vect;

public:

	CarrotCard() {
		this->pGood = new string("Carrot");
		this->pAction = new string(vect.back());
		this->pCost = new int(0);

		vect.pop_back();

	}

	CarrotCard(bool special) {
		this->pGood = new string("Carrot");
		this->pAction = new string("Add 3 Armies");
		this->pCost = new int(0);
	}

	~CarrotCard() {};
};

class CrystalCard : public Card {

	static vector<string> vect;

public:

	CrystalCard() {

		this->pGood = new string("Crystal");
		this->pAction = new string(vect.back());
		this->pCost = new int(0);
		vect.pop_back();

	}
		
	CrystalCard(bool special) {

		this->pGood = new string("Crystal");
		this->pAction = new string("Add 2 Armies");
		this->pCost = new int(0);
	}
	
	~CrystalCard() {};

};

class ForestCard : public Card {

	static vector<string> vect;

public:

	ForestCard() {

		this->pGood = new string("Forest");
		this->pAction = new string(vect.back());
		this->pCost = new int(0);
		vect.pop_back();
	}
		
	ForestCard(bool special) {

		this->pGood = new string("Forest");
		this->pAction = new string("Move 6 Armies");
		this->pCost = new int(0);
	}
	
	~ForestCard() {};
};

class OreCard : public Card {

	static vector<string> vect;

public:

	OreCard() {

		this->pGood = new string("Ore");
		this->pAction = new string(vect.back());
		this->pCost = new int(0);
		vect.pop_back();

	}
		
	OreCard(bool special) {

		this->pGood = new string("Ore");
		this->pAction = new string("Move 2 Armies via Ship");
		this->pCost = new int(0);
	}

	~OreCard() {};

};

class WildCard : public Card {

	static vector<string> vect;

public:
	
	WildCard() {

		this->pGood = new string("Wild");
		this->pAction = new string(vect.back());
		this->pCost = new int(0);
		vect.pop_back();

	}

	~WildCard() {};
	
};
