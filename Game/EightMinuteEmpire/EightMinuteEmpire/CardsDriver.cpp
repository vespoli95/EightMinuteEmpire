//
// Created by Jeff Buonamici on 2019-10-02.
//

#include <iostream>
#include <string>
#include "Cards.h"
#include "Player.h"

using namespace std;

//Create players based on input for user
static vector<Player> initializePlayers() {
	//initialize players
	int numPlayers;
	vector<Player> players;
	do {
		cout << "\nHow many players? (must be between 2 and 5 inclusive)" << endl;
		cin >> numPlayers;
	} while (numPlayers <= 1 || numPlayers > 5);

	for (int i = 1; i <= numPlayers; i++) {
		cout << "Please enter the name of player " << i << ": ";
		string name;
		cin >> name;
		cout << "Please enter the age of player " << i << ": ";
		int age;
		cin >> age;
		Player temp_player(name, age);
		players.push_back(temp_player);
	}
	return players;
}

static void givePlayersCoins(vector<Player>& players) {
	int numPlayers = players.size();

	for (int i = numPlayers - 1; i >= 0; i--) {
		if (numPlayers == 5)
			players.at(i).setCoins(8);
		else if (numPlayers == 4)
			players.at(i).setCoins(9);
		else if (numPlayers == 3)
			players.at(i).setCoins(11);
		else if (numPlayers == 2)
			players.at(i).setCoins(14);
	}
}

//function that determines the youngest player given a vector of players
static Player youngestPlayers(vector<Player> players) {
	Player youngest = players[0];
	for (Player p : players)
		if (p.getAge() < youngest.getAge())
			youngest = p;

	return youngest;
}

static Player biddingFacilityDriver(vector<Player>& players) {
	cout << "******BIDDING FACILITY******" << endl;

	//initialize iterator for vector of players
	vector<Player>::iterator ptr;

	//get bids from each player
	cout << "------------ BIDDING STARTED ------------" << endl;
	cout << "Bids must be greater than or equal to zero and less than or equal to coins possessed." << endl;
	for (ptr = players.begin(); ptr < players.end(); ptr++) {
		do {
			cout << *ptr->getName() << ", how much would you like to bid? " << endl;
			ptr->getBiddingFacility()->start();
		} while (*ptr->getBiddingFacility()->getBid() < 0 || *ptr->getBiddingFacility()->getBid() > * ptr->getCoins());
	}

	//display bids
	cout << "\nHere are the bids: " << endl;
	for (Player p : players)
		p.showBids();

	//determine the highest bidder, if there isn't one, determine whether all the bids are zero or all are equal
	cout << "\nDetermining the highest bidder..." << endl;
	vector<Player> highest = { players[0] };
	int equalCount = 0;
	int zeroCount = 0;
	for (Player p : players) {
		if (*p.getBiddingFacility()->getBid() > * highest[0].getBiddingFacility()->getBid())
			highest[0] = p;
		else {
			if (*p.getBiddingFacility()->getBid() == *highest[0].getBiddingFacility()->getBid()) {
				equalCount++;
				highest.push_back(p);
			}

			if (*p.getBiddingFacility()->getBid() == 0)
				zeroCount++;
		}
	}

	//assign the player object 'bidWinner' to whoever won the bidding process.
	//if all bids were equal or zero, the youngest player in the player vector wins the bid.
	Player bidWinner;
	if (zeroCount == players.size()) {
		bidWinner = youngestPlayers(players);
		cout << "All players have bid zero, therefore the youngest player:  " << *bidWinner.getName() << ", wins the bid." << endl;
	}
	else if (equalCount > 1) {
		bidWinner = youngestPlayers(highest);
		cout << "Multiple players have bid the same amount, therefore the youngest player:  " << *bidWinner.getName() << ", wins the bid." << endl;
	}
	else {
		bidWinner = highest[0];
		cout << "The highest bidder was: " << *bidWinner.getName() << endl;
	}

	//subtract the bid from the coins of the player who won the bid
	bidWinner.setCoins(*bidWinner.getCoins() - *bidWinner.getBiddingFacility()->getBid());
	cout << *bidWinner.getName() << "'s coins reduced to: " << *bidWinner.getCoins() << endl;

	//let the bid winner choose who they want to start first
	cout << *bidWinner.getName() << ", please choose who starts first: (1 for first player, 2 for second player etc.)" << endl;
	int i = 1;
	for (Player p : players)
		cout << i++ << ". " << *p.getName() << endl;

	Player startsFirst;
	int playerChoice;
	cin >> playerChoice;
	startsFirst = players[playerChoice - 1];
	cout << *bidWinner.getName() << " has chosen " << *startsFirst.getName() << " to start first." << endl;

	return startsFirst;
}

static int cardsDriver() {

	/* cout << endl << "Creating player..." << endl;
	Player* player = new Player("Jeff", 28);
	cout << "Player: " << *player->getName() << ", Age: " << *player->getAge() << ", Coins: " << *player->getCoins() << endl;



	cout << endl << "Player " << *(player->getName()) << " takes card: ";
	cout << (hand->exchange(2)).toString() << endl;

	cout << endl << "Display Hand: " << endl;
	hand->toString();

	cout << endl << "Slide cards over: " << endl;
	hand->slideCards(2);
	hand->toString();

	cout << endl << "Player " << *(player->getName()) << " draws a card: " << endl;
	hand->addCard(deck->draw());
	hand->toString();

	player->setCoins(11);
	cout << endl << "Player: " << *player->getName() << ", Age: " << *player->getAge() << ", Coins: " << *player->getCoins() << endl;

	*/

	cout << "Setting up game" << endl;
	Deck* deck = new Deck(3);
	deck->toString();
	cout << "Shuffling Deck..." << endl;
	deck->shuffle();
	deck->toString();

	Hand* hand = new Hand();

	cout << "Drawing Hand..." << endl;

	hand->deal(deck->draw());
	hand->deal(deck->draw());
	hand->deal(deck->draw());
	hand->deal(deck->draw());
	hand->deal(deck->draw());
	hand->deal(deck->draw());

	cout << endl << "Display Hand: " << endl;
	hand->toString();

	//Get players
	vector<Player> players = initializePlayers();

	//Create map
	Board& mapofworld = Board::getInstance();
	if (mapofworld.loadmap()) {
		EXIT_FAILURE;
	}

	//Placing armies
	vector<Player>::iterator plyr;
	for (plyr = players.begin(); plyr < players.end(); plyr++)
	{
		map<string, Region*> regions = mapofworld.getWorldMap();
		map<string, int> temp{ {"R09", 3} };
		plyr->PlaceNewArmies(temp, true, mapofworld);

		//check if adding armies worked
		map<string, Region*>::iterator region2;
		map<string, int>::iterator it2;

		for (region2 = regions.begin(); region2 != regions.end(); region2++) {
			cout << region2->first << ":" << endl;
			for (it2 = region2->second->getArmies()->begin(); it2 != region2->second->getArmies()->end(); it2++)
				cout << "\tname: " << it2->first << ", #: " << it2->second << endl;
		}
	}

	//Add Non-player armies to board if only 2 players
	if (players.size() == 2) {
		Player fakePlayer("AIPlayer", 99);
		int num = 0;
		string input;
		for (int i = 10; i > 0; i--) {
			cout << *players[num].getName() << " please place 1 non-player army in a region" << endl;
			cout << "Type in the region name:" << endl;
			cin >> input;
			map<string, int> temp = { {input, 1} };
			fakePlayer.PlaceNewArmies(temp, false, mapofworld);
			
			//check if adding armies worked
			map<string, Region*> regions = mapofworld.getWorldMap();
			map<string, Region*>::iterator region2;
			map<string, int>::iterator it2;

			for (region2 = regions.begin(); region2 != regions.end(); region2++) {
				cout << region2->first << ":" << endl;
				for (it2 = region2->second->getArmies()->begin(); it2 != region2->second->getArmies()->end(); it2++)
					cout << "\tname: " << it2->first << ", #: " << it2->second << endl;
			}
			if (num == 0)
				num++;
			else
				num--;
		}
	}


	//Give players coins
	givePlayersCoins(players);

	//Bidding
	Player startPlayer = biddingFacilityDriver(players);

	//Let player take card
	cout << endl << "Display Hand: " << endl;
	hand->toString();
	int card;
	do {
		cout << "\nWhich card would you like? (must be between 0 and 5 inclusive)" << endl;
		cin >> card;
	} while (card < 0 || card > 5);

	cout << endl << "Player " << (*startPlayer.getName()) << " takes card: ";
	cout << (hand->exchange(card)).toString() << endl;

	//Show cards sliding
	cout << endl << "Slide cards over: " << endl;
	hand->slideCards(card);
	hand->toString();

	cout << endl << "Player " << (*startPlayer.getName()) << " draws a card: " << endl;
	hand->addCard(deck->draw());
	hand->toString();

	cin.get();

	return 0;
}




