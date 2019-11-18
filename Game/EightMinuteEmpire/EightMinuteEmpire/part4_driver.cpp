//#include <iostream>
//#include "main.h"
//#include "map.h"
//#include "GameStart.h"
//#include "GameStartDriver.cpp"
//#include "BiddingFacilityDriver.cpp"
//#include "PlayerDriver.cpp"
//#include "CardsDriver.cpp"
//
//using namespace std;
//
//int main()
//{
//	//singleton board
//	Board *board = Board::getInstance();
//
//	//initialize iterator for vector of players
//	board->loadmap();
//	Player *ant = new Player("Anthony", 23);
//	Player *tim = new Player("Tim", 22);
//	Player *john = new Player("John", 50);
//	vector<Player> players{ *ant, *tim};	
//	map<string, Region*> regions = board->getWorldMap();
//	vector<Player>::iterator plyr;
//
//	for (plyr = players.begin(); plyr < players.end(); plyr++)
//	{
//		//---- PlaceNewArmies() ---- 
//		int armiesToPlace;
//
//		cout << *plyr->getName() << ", how many armies would you like to place?" << endl;
//		cin >> armiesToPlace;
//		map<string, int> temp{ };
//		do {
//			cout << armiesToPlace << " armies to place. Where do you want to place your next one?" << endl;
//			string region;
//			cin >> region;
//			int amount;
//			do {
//				cout << "How many would you like to place here?" << endl;
//				cin >> amount;
//			} while (amount > armiesToPlace || amount <= 0);
//			temp.insert({region, amount});
//			armiesToPlace -= amount;
//		} while (armiesToPlace > 0);
//
//		plyr->PlaceNewArmies(temp, false, *board);
//
//
//		//check if adding armies worked
//		map<string, Region*>::iterator region2;
//		map<string, int>::iterator it2;
//		
//		cout << "\ ---- PlaceNewArmies() ---- \n";
//		for (region2 = regions.begin(); region2 != regions.end(); region2++) {
//			cout << region2->first << ":" << endl;
//			for (it2 = region2->second->getArmies()->begin(); it2 != region2->second->getArmies()->end(); it2++)
//				cout << "\tname: " << it2->first << ", #: " << it2->second << endl;
//		}
//
//		//---- PlaceNewArmies() ----
//
//		//---- DestroyArmy() ---- 
//		cout << "\n ---- DestroyArmy() ---- \n";
//		plyr->DestroyArmy("Anthony", "R09", *board);
//
//		for (region2 = regions.begin(); region2 != regions.end(); region2++) {
//			cout << region2->first << ":" << endl;
//			for (it2 = region2->second->getArmies()->begin(); it2 != region2->second->getArmies()->end(); it2++)
//				cout << "\tname: " << it2->first << ", #: " << it2->second << endl;
//		}
//
//		//---- DestroyArmy() ---- 
//
//		//---- BuildCity() ----
//		cout << "\n ---- BuildCity() ---- \n";
//		
//		cout << "Where do you want to place your city?" << endl;
//		string region_2;
//		cin >> region_2;
//		int amount_2;
//		map<string, int> temp_2{};
//		temp_2.insert({ region_2, amount_2 });
//		
//
//		map<string, Region*>::iterator region_ptr;
//		plyr->BuildCity(temp_2, *board);
//
//		//test to see if city was added properly
//		map<string, int>::iterator city_ptr;
//		for (region_ptr = regions.begin(); region_ptr != regions.end(); region_ptr++) {
//			cout << region_ptr->first << ": " << endl;
//			for (city_ptr = region_ptr->second->getCities()->begin(); city_ptr != region_ptr->second->getCities()->end(); city_ptr++)
//				cout << "\tName: " << city_ptr->first << ", #: " << city_ptr->second << endl;
//		}
//		//---- BuildCity() ----
//		
//
//
//		//---- MoveArmies() ----
//		cout << "\n ---- MoveArmies() ---- \n";
//		string army;
//		string region_3;
//		int amount_moves = 3;
//		cout << "You have " << 3 << " moves." << endl;
//		do {
//			map<string, string> temp_3{};
//			cout << "Which region is the army you want to move on?" << endl;
//			cin >> army;
//			cout << "Where would you like to move this army?" << endl;
//			cin >> region_3;
//			temp_3.insert({ army, region_3 });
//			plyr->MoveArmies(false, 1, temp_3, *board);	
//			for (region2 = regions.begin(); region2 != regions.end(); region2++) {
//				cout << region2->first << ":" << endl;
//				for (it2 = region2->second->getArmies()->begin(); it2 != region2->second->getArmies()->end(); it2++)
//					cout << "\tname: " << it2->first << ", #: " << it2->second << endl;
//			}
//			amount_moves--;
//		} while (amount_moves > 0);
//
//
//	
//		//---- MoveArmies() ----
//		
//
//		getchar();
//		getchar();
//
//
//	}
//
//
//	return 0;
//
//	
//
//
//}