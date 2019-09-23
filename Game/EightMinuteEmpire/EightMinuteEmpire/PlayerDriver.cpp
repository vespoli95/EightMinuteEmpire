#include "Player.h";

int main() {
	Player p1("Ant");
	Player p2("Jeff");
	Player p3("Paul");

	vector<Player> players = { p1, p2, p3 };

	vector<Player>::iterator ptr;

	for (ptr = players.begin(); ptr < players.end(); ptr++) {
		(*ptr).getBiddingFacility().start();
	}

	cout << "\nHere are the bids: " << endl;
	for (Player p : players) {
		p.showBids();
	}

	cout << "\nDetermining the highest bidder..." << endl;
	Player highest = players[0];
	// establish counters to determine if the bids from each player are equal and/or all equal to zero 
	int equalCount = 0;
	int zeroCount = 0;
	for (Player p : players) {
		if (p.getBiddingFacility().getBid() > highest.getBiddingFacility().getBid()) {
			highest = p;
		}
		else {
			if (p.getBiddingFacility().getBid() == highest.getBiddingFacility().getBid()) {
				equalCount++;
			}
			if (p.getBiddingFacility().getBid() == 0) {
				zeroCount++;
			}
		}
	}
	Player bidWinner;
	if (zeroCount == players.size()) {
		bidWinner = players[0];
		cout << "All players have bid zero, therefore the first player:  " << bidWinner.getName() << ", wins the bid." << endl;
	}
	else if (equalCount == players.size()) {
		bidWinner = players[0];
		cout << "All players have bid the same amount, therefore the first player:  " << bidWinner.getName() << ", wins the bid." << endl;
	}
	else {
		bidWinner = highest;
		cout << "The highest bidder was: " << bidWinner.getName() << endl;
		bidWinner.setCoins(bidWinner.getCoins() - bidWinner.getBiddingFacility().getBid());
		cout << bidWinner.getName() << "'s coins reduced to: " << bidWinner.getCoins() << endl;
	}

	cout << bidWinner.getName() << ", please choose who starts first: (1 for first player, 2 for second player etc.)" << endl;

	int i = 1;
	for (Player p : players) {
		cout << i++ << ". " << p.getName() << endl;
	}
	Player startsFirst;
	int playerChoice;
	cin >> playerChoice;
	startsFirst = players[playerChoice - 1];

	cout << bidWinner.getName() << " has chosen " << startsFirst.getName() << " to start first." << endl;

	getchar();
	getchar();

	return 0;
}