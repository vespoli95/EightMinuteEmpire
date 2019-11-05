#include <iostream>
#include "main.h"
#include "map.h"
#include "GameStart.h"
#include "GameStartDriver.cpp"
#include "BiddingFacilityDriver.cpp"
#include "PlayerDriver.cpp"
#include "CardsDriver.cpp"

using namespace std;

static int driverhi()
{
	//singleton board
	Board board = Board::getInstance();

	//initialize iterator for vector of players
	board.loadmap();
	Player *ant = new Player("Anthony", 23);
	Player *tim = new Player("Tim", 22);
	vector<Player> players{ *ant};
	vector<Player>::iterator plyr;

	//testing PlaceNewArmies
	for (plyr = players.begin(); plyr < players.end(); plyr++)
	{
		/*cout << *plyr->getName() << " please place your first 3 armies." << endl;
		cout << *pNumArmies << " armies remaining." << endl;
		do {
			cout << numArmies << " armies to place. Where do you want to place your next one?" << endl;
			string region;
			cin >> region;
			int amount;
			do {
				cout << "How many would you like to place here?" << endl;
				cin >> amount;
			} while (amount > numArmies || amount <= 0);
			selected_regions->insert(pair<string, int>(region, amount));
			numArmies -= amount;
		} while (numArmies > 0);
*/
		
		map<string, Region*> regions = board.getWorldMap();
		map<string, int> temp{ {"R09", 1} , {"R05", 1}, {"R07", 1} };
		plyr->PlaceNewArmies(3, temp, true, board);

		
		

		//check if adding armies worked
		map<string, Region*>::iterator region2;
		map<string, int>::iterator it2;
		
		for (region2 = regions.begin(); region2 != regions.end(); region2++) {
			cout << region2->first << ":" << endl;
			for (it2 = region2->second->getArmies()->begin(); it2 != region2->second->getArmies()->end(); it2++)
				cout << "\tname: " << it2->first << ", #: " << it2->second << endl;
		}


		/*map<string, int> selected_region = new map<string, int>();
		cout << "Where do you want to place your city?" << endl;
		string region;
		cin >> region;
		int amount;
		selected_region->insert(pair<string, int>(region, 1));
		*/

		map<string, int> selected_region{ {"R01", 1} };
		map<string, Region*>::iterator region_ptr;
		plyr->BuildCity(selected_region, board);

		//test to see if city was added properly
		map<string, int>::iterator city_ptr;
		for (region_ptr = regions.begin(); region_ptr != regions.end(); region_ptr++) {
			cout << region_ptr->first << ": " << endl;
			for (city_ptr = region_ptr->second->getCities()->begin(); city_ptr != region_ptr->second->getCities()->end(); city_ptr++)
				cout << "\tName: " << city_ptr->first << ", #: " << city_ptr->second << endl;
		}


		//testing move armies
		/*map<string, string> *selected_moves = new map<string, string>();
		string army;
		string region;
		cout << "You have " << amount << " moves." << endl;
		do {
			cout << "Which army would you like to move?" << endl;
			cin >> army;
			cout << "Where would you like to move your army?" << endl;
			cin >> region;
			amount--;
		} while (amount > 0);
		moves.insert(pair<string, string>(army, region));*/

		plyr->MoveArmies(1, { { "R01", "R03" } }, board);

		for (region2 = regions.begin(); region2 != regions.end(); region2++) {
			cout << region2->first << ":" << endl;
			for (it2 = region2->second->getArmies()->begin(); it2 != region2->second->getArmies()->end(); it2++)
				cout << "\tname: " << it2->first << ", #: " << it2->second << endl;
		}
		



		getchar();
		getchar();


	}




	


}