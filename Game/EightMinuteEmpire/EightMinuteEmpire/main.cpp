/*#include <iostream>
#include "main.h"
#include "map.h"
#include "GameStart.h"
#include "GameStartDriver.cpp"
#include "BiddingFacilityDriver.cpp"
#include "PlayerDriver.cpp"
#include "CardsDriver.cpp"
#include "GameLoop.h"
#include "ComputeScore.h"

using namespace std;

int main()
{
	int answer = -1;
	while (answer != 0) {
		cout << "\n\nHello, please choose an option:\n"
			<< "1 for bidding facility driver\n"
			<< "2 for GameStart driver\n"
			<< "3 for player driver\n"
			<< "4 for cards driver\n"
			<< "5 for main game loop(part 3) driver\n"
			<< "6 for compute score (part 6) driver\n"
			<< "0 to exit\n";
		cin >> answer;

		if (answer == 1)
			biddingFacilityDriver();
		else if (answer == 2)
			GameLoader();
		//else if (answer == 3)
			//driverhi();
		else if (answer == 4)
			cardsDriver();
		else if (answer == 5)
			GameLoop();
		else if (answer == 6)
			computeScore();
	}
	
}
*/