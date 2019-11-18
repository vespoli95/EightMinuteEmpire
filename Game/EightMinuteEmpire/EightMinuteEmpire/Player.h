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
		int nbCards;
		int score;
		string *pName;
		BiddingFacility *pBiddingFacility;
		map<string, Region> *playerRegions = new map<string, Region>;
		map<string, int> playerGoods;
		map<string, int> playerRegionsMap;
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
		inline void addCard() { nbCards++; };
		inline int getNbCards() { return nbCards; };
		inline void setHand(Hand *h) { playerHand = h; };
		inline Hand* getHand() { return playerHand; };
		inline void setGoods(string key) { playerGoods[key] = playerGoods[key] + 1; };
		inline int getGoods(string key) { return playerGoods[key]; };
		
		inline void setplayerRegion(map<string, int> map) { playerRegionsMap = map; };
		inline map<string, int>* getplayerRegion() { return &playerRegionsMap; };
		inline int* getplayerRegion(string region) { return &playerRegionsMap[region]; };
		
		inline map<string, int> getGoods() { return playerGoods; };
	//	inline map<string, Region> getPlayerRegions() { return *playerRegions; };
		inline void setScore(int s) { score = s; };
		inline int getScore() { return score; };
		
		bool compare(Player player);
		void PayCoin();
		bool Ignore();
		void MoveArmies(bool moveOverWater, int amount, map<string, string> moves, Board& board);
		void MoveOverLand(int amount, map<string, string> moves, Board& board);
		void MoveOverWater(int amount, map<string, string> moves, Board& board);
		void BuildCity(map<string, int> selected_region, Board& board);
		void PlaceNewArmies(map<string, int> placements, bool gameStart, Board& board);
		void RemoveArmy(Board& board, Region& region);
		bool DestroyArmy(string playerName, string regionName, Board& board);
		vector<int> AndOr(Card& card);
		void DestroyArmy();
		string toString();
		static bool equals(Player, Player p2);
		int computeGoods();
		map<string, int> computeRegions(Board& board);
};