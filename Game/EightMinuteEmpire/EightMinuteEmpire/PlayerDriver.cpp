#include "Player.h";

int main() {

	//initialize players
	Player p1("Ant");
	Player p2("Jeff");
	Player p3("Paul");
	Player p4("Marty");
	vector<Player> players = { p1, p2, p3, p4 };

	//initialize iterator for vector of players
	vector<Player>::iterator ptr;

	//get bids from each player
	for (ptr = players.begin(); ptr < players.end(); ptr++) {
		cout << *ptr->getName() << ", how much would you like to bid?" << endl;
		ptr->getBiddingFacility()->start();
	}
	 
	//display bids
	cout << "\nHere are the bids: " << endl;
	for (Player p : players) {
		p.showBids();
	}

	//determine the highest bidder, if there isn't one, determine whether all the bids are zero or all are equal
	cout << "\nDetermining the highest bidder..." << endl;
	Player highest = players[0];
	int equalCount = 0;
	int zeroCount = 0;
	for (Player p : players) {
		if (*p.getBiddingFacility()->getBid() > *highest.getBiddingFacility()->getBid()) {
			highest = p;
		}
		else {
			if (*p.getBiddingFacility()->getBid() == *highest.getBiddingFacility()->getBid()) {
				equalCount++;
			}
			if (*p.getBiddingFacility()->getBid() == 0) {
				zeroCount++;
			}
		}
	}

	//assign the player object 'bidWinner' to whoever won the bidding process.
	//if all bids were equal or zero, the first player in the player vector wins the bid.
	Player bidWinner;
	if (zeroCount == players.size()) {
		bidWinner = players[0];
		cout << "All players have bid zero, therefore the first player:  " << *bidWinner.getName() << ", wins the bid." << endl;
	}
	else if (equalCount == players.size()) {
		bidWinner = players[0];
		cout << "All players have bid the same amount, therefore the first player:  " << *bidWinner.getName() << ", wins the bid." << endl;
	}
	else {
		bidWinner = highest;
		cout << "The highest bidder was: " << *bidWinner.getName() << endl;
	}

	//subtract the bid from the coins of the player who won the bid
	bidWinner.setCoins(*bidWinner.getCoins() - *bidWinner.getBiddingFacility()->getBid());
	cout << *bidWinner.getName() << "'s coins reduced to: " << *bidWinner.getCoins() << endl;

	//let the bid winner choose who they want to start first
	cout << *bidWinner.getName() << ", please choose who starts first: (1 for first player, 2 for second player etc.)" << endl;
	int i = 1;
	for (Player p : players) {
		cout << i++ << ". " << *p.getName() << endl;
	}
	Player startsFirst;
	int playerChoice;
	cin >> playerChoice;
	startsFirst = players[playerChoice - 1];
	cout << *bidWinner.getName() << " has chosen " << *startsFirst.getName() << " to start first." << endl;

	//delete pointers when they are no longer needed


	getchar();

	return 0;
}