#pragma once
#include "Gamecard.cpp"
#include <string>

class CardsFactory {

public:

	static Card* Create(string type, bool special = false ) {

		if (special) {

			if (type == "Anvil") return new AnvilCard(special);
			if (type == "Carrot") return new CarrotCard(special);
			if (type == "Crystal") return new CrystalCard(special);
			if (type == "Forest") return new ForestCard(special);
			if (type == "Ore") return new OreCard(special);

		}

		if (type == "Anvil") return new AnvilCard();
		if (type == "Carrot") return new CarrotCard();
		if (type == "Crystal") return new CrystalCard();
		if (type == "Forest") return new ForestCard();
		if (type == "Ore") return new OreCard();
		if (type == "Wild") return new WildCard();

		return NULL;
	}

	~CardsFactory(){};


private:

	CardsFactory() {};



};