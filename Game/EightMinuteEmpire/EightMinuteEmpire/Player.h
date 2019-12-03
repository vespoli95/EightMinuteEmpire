#pragma once
#include <iostream>
#include "BiddingFacility.h"
#include "map.h"
#include <map>
#include "Subject.h"
#include "../../../../../../../OneDrive/Desktop/PlayerStrategies.h"


using namespace std;




class Player : public Subject {
	private:
		int *pCoins;
		int *pAge;
		int *pNumArmies;
		int nbCards;
		int score;
		int *pCities;
		string *pName;
		BiddingFacility *pBiddingFacility;
		map<string, Region> *playerRegions = new map<string, Region>;
		map<string, int> playerGoods;
		map<string, int> playerRegionsMap;
		Hand *playerHand;
		vector<Card>* hand;
		PlayerStrategy* strategy;

		//for observer
		map<string, int> *placed_new_armies;
		string *city_built;
		map<string, string> *army_destroyed;
		map<string, string> *move_army;

	public:
		Player();
		Player(string name, int age);
		~Player();

		inline map<string, int> *getPlacedNewArmies() { return placed_new_armies; };
		inline void setPlacedNewArmies(map<string, int> *current_move) { this->placed_new_armies = current_move; };
		inline string* getCityBuilt() { return city_built; };
		inline void setCityBuilt(string cityBuilt) { *city_built = cityBuilt; };
		inline map<string, string> *getArmyDestroyed() { return army_destroyed; };
		inline void setDestroyArmy(string playerName, string regionName) { 
			map<string, string> *temp = new map<string, string>();
			temp->insert(pair<string, string>(playerName, regionName));
			army_destroyed = temp;
		};
		inline map<string, string> *getMoveArmy() { return move_army; };
		inline void setMoveArmy(string startingPosition, string endPosition) {
			map<string, string> *temp = new map<string, string>();
			temp->insert(pair<string, string>(startingPosition, endPosition));
			move_army = temp;
		};
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
		inline int* getCities() { return pCities; };
		inline void addCard() { nbCards++; };
		inline int getNbCards() { return nbCards; };
		inline void setHand(Hand *h) { playerHand = h; };
		inline Hand* getHand() { return playerHand; };
		inline void setGoods(string key) { playerGoods[key] = playerGoods[key] + 1; };
		inline int getGoods(string key) { return playerGoods[key]; };
		inline map<string, int> getGoods() { return playerGoods; };
		inline map<string, Region> getPlayerRegions() { return *playerRegions; };
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
		string toString();
		static bool equals(Player, Player p2);
		int computeGoods();
		void addCardToHand(Card card);
		string determineContinentOwner(string continent, map<string, Region*> regions);
		void calculateContinents(Board* board);

		map<string, int> computeRegions(Board& board);
		inline void setStrategy(PlayerStrategy* newStrat) { this->strategy = newStrat; }
		inline int executeStrategy(Hand* h, string pn, int c) { return this->strategy->execute(h, pn, c); }

};