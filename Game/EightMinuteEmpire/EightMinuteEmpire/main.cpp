#include <iostream>
#include "main.h"
#include "GameStart.cpp"
#include "BiddingFacilityDriver.cpp"
//#include "PlayerDriver.cpp"
#include "CardsDriver.cpp"

using namespace std;

int main()
{/*
	int answer = -1;
	while (answer != 0) {
		cout << "\n\nHello, please choose an option:\n"
			<< "1 for bidding facility driver\n"
			<< "2 for map driver\n"
			<< "3 for player driver\n"
			<< "4 for cards driver\n"
			<< "0 to exit\n";
		cin >> answer;

		if (answer == 1)
			biddingFacilityDriver();
		else if (answer == 2)
			GameLoader();
		else if (answer == 3)
			playerDriver();
		else if (answer == 4)
		cardsDriver();
	}*/
	GameLoader();

}
