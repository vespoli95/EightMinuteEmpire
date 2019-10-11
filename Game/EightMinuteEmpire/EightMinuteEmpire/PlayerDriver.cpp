#include "Player.h"
#include <iostream>
#include <fstream>

using namespace std;


static int playerDriver()
{
	int answer = 0;
	Player *tPlayer = new Player("Jimmy", 42);
	
	do {
		cout << "\n\nPress 1 for BuildCity\n"
			<< "Press 2 for PayCoin\n"
			<< "Press 3 for PlaceNewArmies\n"
			<< "Press 4 for MoveArmies\n"
			<< "Press 5 for MoveOverLand\n"
			<< "Press 6 for DestroyArmy\n"
			<< "Press 0 to exit\n\n";
		cin >> answer;
		switch (answer)
		{
		default: cout << "wrong input "; break;
		case 0: cout << "goodbye!";
		case 1:tPlayer->BuildCity(); break;
		case 2:tPlayer->PayCoin(); break;
		case 3:tPlayer->PlaceNewArmies(); break;
		case 4:tPlayer->MoveArmies(); break;
		case 5:tPlayer->MoveOverLand(); break;
		case 6:tPlayer->DestroyArmy(); break;
		}
	} while (answer != 0);
	return 0;

}