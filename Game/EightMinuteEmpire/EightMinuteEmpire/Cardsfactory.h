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

vector<string> AnvilCard::vect = { "Add 3 Armies or move 4 Armies", "Move 3 Armies via Ship", "Build City","Move 4 Armies","Add 3 Armies or Move 3 Armies","Move 5 Armies","Add 3 Armies","Add 3 Armies"};
vector<string> CarrotCard::vect = {"Build City","Destroy 1 Army and Add 1 Army","Add 3 Armies","Move 4 Armies","Move 5 Armies","Add 3 Armies","Move 3 Armies via Ship","Move 4 Armies","Build City"};
vector<string> CrystalCard::vect = {"Add 2 Armies","Add 2 Armies","Move 2 Armies","Add 1 Army"};
vector<string> ForestCard::vect = { "Move 3 Armies","Add 3 Armies","Destroy 1 Army or Build City","Add 2 Armies or Move 3 Armies","Move 4 Armies via Ship","Build City","Move 3 Armies via Ship"};
vector<string> OreCard::vect = { "Move 2 Armies","Move 3 Armies via Ship","Move 2 Armies via Ship","Add 3 Armies","Add 3 Armies","Add 2 Armies"};
vector<string> WildCard::vect = { "Move 2 Armies","Move 2 Armies","Add 2 Armies"};