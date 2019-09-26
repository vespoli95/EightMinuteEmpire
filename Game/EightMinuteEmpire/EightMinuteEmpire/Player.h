#pragma once
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include "BiddingFacility.h"

using namespace std;

class Player {
	private:
		int *pCoins;
		string *pName;
		BiddingFacility *pBiddingFacility;
	public:
		Player();
		Player(string name);
		BiddingFacility *getBiddingFacility();
		void showBids();
		int *getCoins();
		void setCoins(int coins);
		string *getName();
		void setName(string name);
		void PayCoin();
		void PlaceNewArmies();
		void MoveArmies();
		void MoveOverLand();
		void BuildCity();
		void DestroyArmy();
};