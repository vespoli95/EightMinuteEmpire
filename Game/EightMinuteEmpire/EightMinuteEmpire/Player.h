#pragma once
#include <iostream>
#include <string>
#include "BiddingFacility.h"
#include "map.h"
#include "Cards.h"


using namespace std;

class Player {
	private:
		int *pCoins;
		int *pAge;
		int *pNumArmies;
		string *pName;
		BiddingFacility *pBiddingFacility;
		map<string, Region> *playerRegions = new map<string, Region>;
		
		Hand *playerHand;



	public:
		Player();
		Player(string name, int age);
		
		inline void showBids() { cout << "Name: " << *pName << " / Bid: " << *(pBiddingFacility->getBid()) << endl; };
		inline BiddingFacility* getBiddingFacility() { return pBiddingFacility; };
		inline int* getCoins() { return pCoins; };
		inline void setCoins(int coins) { *pCoins = coins; };
		inline int* getAge() { return pAge; };
		inline void setAge(int age) { *pAge = age; };
		inline string* getName() { return pName; };
		inline void setName(string name) { *pName = name; };
		inline int* getNumArmies() { return pNumArmies; }
		inline void setNumArmies(int numArmies) { *pNumArmies = numArmies; }

		inline void setHand(Hand *h) { playerHand = h; };
		inline Hand* getHand() { return playerHand; };

		
		inline map<string, Region> getPlayerRegions() { return *playerRegions; };
		
		void PayCoin();
		void MoveArmies(int amount, map<string, string> moves, Board &board);
		void MoveOverLandOrWater();
		void BuildCity(map<string, int> selected_region, Board &board);
		void PlaceNewArmies(int numArmies, map<string, int> placements, bool gameStart, Board &board);
		void DestroyArmy();
};