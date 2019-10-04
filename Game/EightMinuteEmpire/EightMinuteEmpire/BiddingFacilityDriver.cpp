#include "Player.h";

//function that determines the youngest player given a vector of players
inline static Player youngestPlayer(vector<Player> players) {
	Player youngest = players[0];
	for (Player p : players)
		if (p.getAge() < youngest.getAge())
			youngest = p;

	return youngest;
}

int main() {
	cout << "******BIDDING FACILITY******" << endl;
	
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

	//initialize iterator for vector of players
	vector<Player>::iterator ptr;

	//get bids from each player
	cout << "------------ BIDDING STARTED ------------" << endl;
	cout << "Bids must be greater than or equal to zero and less than or equal to coins possessed." << endl;
	for (ptr = players.begin(); ptr < players.end(); ptr++) {
		do {
			cout << *ptr->getName() << ", how much would you like to bid? " << endl;
			ptr->getBiddingFacility()->start();
		} while (*ptr->getBiddingFacility()->getBid() < 0 || *ptr->getBiddingFacility()->getBid() > *ptr->getCoins());
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
		if (*p.getBiddingFacility()->getBid() > *highest[0].getBiddingFacility()->getBid())
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
		bidWinner = youngestPlayer(players);
		cout << "All players have bid zero, therefore the youngest player:  " << *bidWinner.getName() << ", wins the bid." << endl;
	}
	else if (equalCount > 1) {
		bidWinner = youngestPlayer(highest);
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



	getchar();
	getchar();

	return 0;
}