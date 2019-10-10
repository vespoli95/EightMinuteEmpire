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
		int *pAge;
		string *pName;
		BiddingFacility *pBiddingFacility;
	public:
		Player();
		Player(string name);
		Player(string name, int age);
		BiddingFacility *getBiddingFacility();
		void showBids();
		int *getCoins();
		void setCoins(int coins);
		int *getAge();
		void setAge(int age);
		string *getName();
		void setName(string name);
		void PayCoin();
		void PlaceNewArmies();
		void MoveArmies();
		void MoveOverLand();
		void BuildCity();
		void DestroyArmy();
};