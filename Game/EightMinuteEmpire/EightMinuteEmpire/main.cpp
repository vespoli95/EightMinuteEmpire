#include <iostream>
#include "main.h"
#include "BiddingFacilityDriver.cpp"
#include "mapDriver.cpp"

using namespace std;

int main()
{
	int answer = -1;
	while (answer != 0) {
		cout << "Hello press 1 for bidding facility driver, 2 for map driver\n";
		cin >> answer;

		if (answer == 1)
			biddingFacilityDriver();
		else if (answer == 2)
			mapDriver();
	}
}