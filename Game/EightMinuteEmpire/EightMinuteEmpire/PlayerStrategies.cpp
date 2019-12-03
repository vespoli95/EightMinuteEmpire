#pragma once
#include "PlayerStrategies.h"
#include <iostream>



int realPlayer::execute(Hand* hand, string playerName, int playerCoins) {
	int choice = NULL;
	bool invalideChoice = true;
	int coins = playerCoins;
	do {

		std::cout << "\nactive player: " << playerName << endl << "Please choose a card to play from the following: " << endl;
		hand->toString();
		std::cin >> choice;

		// select a card to play
		switch (choice)
		{
		default: std::cout << "keep your selection between 0 and 5!" << endl; break;
		case 0:invalideChoice = false; break;
		case 1:if (coins < 1) { std::cout << "You dont have enough coins!" << endl; }
			  else { invalideChoice = false; } break;
		case 2:if (coins < 1) { std::cout << "You dont have enough coins!" << endl; }
			  else { invalideChoice = false; } break;
		case 3:if (coins < 2) { std::cout << "You dont have enough coins!" << endl; }
			  else { invalideChoice = false; } break;
		case 4:if (coins < 2) { std::cout << "You dont have enough coins!" << endl; }
			  else { invalideChoice = false; } break;
		case 5:if (coins < 3) { std::cout << "You dont have enough coins!" << endl; }
			  else { invalideChoice = false; } break;
		}

	} while (invalideChoice);

	return choice;
}

int greedyComputer::execute(Hand *hand, string playerName, int playerCoins)
{
	hand->toString();
	cout << "\n\n" << playerName << ", " << playerCoins<<"\n\n";
	Card card;
	string action;
	int cost;
	for (int i = 0; i < 6; i++){
		card = hand->peak(i);
		action = *card.getAction();
		cost = *card.getCost();
		cout <<endl<< card.toString()<<endl;
		if (action.find("Build") != string::npos) {
			if (playerCoins >= cost)
				return i;
		}
		if (action.find("Destroy") != string::npos) {
			if (playerCoins >= cost)
				return i;
		}
	}
	return 0;

}

int moderateComputer::execute(Hand* hand, string playerName, int playerCoins)
{
	hand->toString();
	cout << "\n\n" << playerName << ", " << playerCoins << "\n\n";
	Card card;
	string action;
	int cost;
	for (int i = 0; i < 6; i++) {
		card = hand->peak(i);
		action = *card.getAction();
		cost = *card.getCost();
		cout << endl << card.toString() << endl;
		if (action.find("Add") != string::npos) {
			if (playerCoins >= cost)
				return i;
		}
		if (action.find("Move") != string::npos) {
			if (playerCoins >= cost)
				return i;
		}
	}
	return 0;
}