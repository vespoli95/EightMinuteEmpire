//
// Created by Jeff Buonamici on 2019-10-02.
//

#include <iostream>
#include <string>
#include "Cards.h"
#include "Player.h"

using namespace std;


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

	//initialize players
	int numPlayers;

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

static int cardsDriver(){
	/*cout << "Creating Deck..." << endl;

	Card* card1 = new Card("Move 3 Armies", "Forest");
	Card* card2 = new Card("Add 3 Armies", "Forest");
	Card* card3 = new Card("Move 6 Armies", "Forest");
	Card* card4 = new Card("Destroy 1 Army or Build City", "Forest");
	Card* card5 = new Card("Add 2 Armies or Move 3 Armies", "Forest");
	Card* card6 = new Card("Move 4 Armies via Ship", "Forest");
	Card* card7 = new Card("Build City", "Forest");
	Card* card8 = new Card("Move 3 Armies via Ship", "Forest");
	Card* card9 = new Card("Build City", "Carrot");
	Card* card10 = new Card("Destroy 1 Army and Add 1 Army", "Carrot");
	Card* card11 = new Card("Add 3 Armies", "Carrot");
	Card* card12 = new Card("Move 4 Armies", "Carrot");
	Card* card13 = new Card("Move 5 Armies", "Carrot");
	Card* card14 = new Card("Add 3 Armies", "Carrot x 2");
	Card* card15 = new Card("Move 3 Armies vis Ship", "Carrot");
	Card* card16 = new Card("Add 4 Armies or Move 2 Armies", "Carrot");
	Card* card17 = new Card("Move 4 Armies", "Carrot");
	Card* card18 = new Card("Build City", "Carrot");
	Card* card19 = new Card("Move 4 Armies", "Anvil");
	Card* card20 = new Card("Add 3 Armies or move 4 Armies", "Anvil");
	Card* card21 = new Card("Move 3 Armies via Ship", "Anvil");
	Card* card22 = new Card("Build City", "Anvil");
	Card* card23 = new Card("Move 4 Armies", "Anvil x 2");
	Card* card24 = new Card("Add 3 Armies or Move 3 Armies", "Anvil");
	Card* card25 = new Card("Move 5 Armies", "Anvil");
	Card* card26 = new Card("Add 3 Armies", "Anvil");
	Card* card27 = new Card("Move 2 Armies", "Ore");
	Card* card28 = new Card("Move 3 Armies vis Ship", "Ore");
	Card* card29 = new Card("Move 2 Armies vis Ship", "Ore");
	Card* card30 = new Card("Move 2 Armies vis Ship", "Ore");
	Card* card31 = new Card("Add 3 Armies", "Ore");
	Card* card32 = new Card("Add 3 Armies", "Ore");
	Card* card33 = new Card("Add 2 Armies", "Ore");
	Card* card34 = new Card("Add 2 Armies", "Crystal");
	Card* card35 = new Card("Add 2 Armies", "Crystal");
	Card* card36 = new Card("Move 2 Armies", "Crystal");
	Card* card37 = new Card("Add 1 Army", "Crystal");
	Card* card38 = new Card("Add 2 Armies", "Crystal");
	Card* card39 = new Card("Move 2 Armies", "Wild");
	Card* card40 = new Card("Move 2 Armies", "Wild");
	Card* card41 = new Card("Add 2 Armies", "Wild");
	Card* card42 = new Card("Add 3 Armies", "Anvil");

	Hand* hand = new Hand();
	Deck* deck = new Deck();

	deck->addCard(card1);
	deck->addCard(card2);
	deck->addCard(card3);
	deck->addCard(card4);
	deck->addCard(card5);
	deck->addCard(card6);
	deck->addCard(card7);
	deck->addCard(card8);
	deck->addCard(card9);
	deck->addCard(card10);
	deck->addCard(card11);
	deck->addCard(card12);
	deck->addCard(card13);
	deck->addCard(card14);
	deck->addCard(card15);
	deck->addCard(card16);
	deck->addCard(card17);
	deck->addCard(card18);
	deck->addCard(card19);
	deck->addCard(card20);
	deck->addCard(card21);
	deck->addCard(card22);
	deck->addCard(card23);
	deck->addCard(card24);
	deck->addCard(card25);
	deck->addCard(card26);
	deck->addCard(card27);
	deck->addCard(card28);
	deck->addCard(card29);
	deck->addCard(card30);
	deck->addCard(card31);
	deck->addCard(card32);
	deck->addCard(card33);
	deck->addCard(card34);
	deck->addCard(card35);
	deck->addCard(card36);
	deck->addCard(card37);
	deck->addCard(card38);
	deck->addCard(card39);
	deck->addCard(card40);
	deck->addCard(card41);
	deck->addCard(card42);

	cout << "Drawing Hand..." << endl;

	hand->deal(deck->draw());
	hand->deal(deck->draw());
	hand->deal(deck->draw());
	hand->deal(deck->draw());
	hand->deal(deck->draw());
	hand->deal(deck->draw());


	cout << endl << "Display Hand: " << endl;
	hand->toString();

	cout << endl << "Creating player..." << endl;
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
	



	// Create cards
	/*Card *cards[10] = {new Card("Move4","Carrot"),
			new Card("Move","Bean"),
			new Card("Move1","Iron"),
			new Card("Move2","Tomato"),
			new Card("Move3","Apple"),
			new Card("Move4","Banana"),
			new Card("Move5","Wood")};

	Deck *deck = new Deck();
	for(int i = 0; i < 7; i++) {
		deck->addCard(cards[i]);
		cout << cards[i] << endl;
	}*/
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

	vector<Player> players;
	Player startPlayer = biddingFacilityDriver(players);

	cin.get();

	return 0;
}




