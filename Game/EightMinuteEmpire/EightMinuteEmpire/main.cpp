#include <iostream>
#include "main.h"
#include "BiddingFacilityDriver.cpp"
#include "mapDriver.cpp"
#include "PlayerDriver.cpp"

using namespace std;

int main()
{
	int answer = -1;
	while (answer != 0) {
		cout << "\n\nHello, please choose an option:\n"
			<< "1 for bidding facility driver\n"
			<< "2 for map driver\n"
			<< "3 for player driver\n"
			<< "0 to exit\n";
		cin >> answer;

		if (answer == 1)
			biddingFacilityDriver();
		else if (answer == 2)
			mapDriver();
		else if (answer == 3)
			playerDriver();
	}
}