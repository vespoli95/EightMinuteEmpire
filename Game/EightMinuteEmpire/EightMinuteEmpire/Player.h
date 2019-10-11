#pragma once
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include "BiddingFacility.h"
#include "map.h"


using namespace std;

class Player {
	private:
		int *pCoins;
		int *pAge;
		string *pName;
		BiddingFacility* pBiddingFacility;
		vector<Region*> playerRegion;
		//vector<Cards*> playerHand;

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
		
		void PayCoin();
		void PlaceNewArmies();
		void MoveArmies();
		void MoveOverLand();
		void BuildCity();
		void DestroyArmy();
};