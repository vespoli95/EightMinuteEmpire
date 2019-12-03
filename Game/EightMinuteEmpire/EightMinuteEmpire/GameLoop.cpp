#include "GameLoop.h"
#include <iostream>
//#include <string>
//#include "CardsDriver.cpp"
#include "Player.h"

#include "main.h"


void GameLoop() {
	int nbPlayer = 3;
	vector<Player> players;
	for (int i = 1; i <= nbPlayer; i++)
	{
		string name = "p" + to_string(i);
		Player temp_player(name, 10 + i);
		temp_player.setStrategy(new moderateComputer());
		players.push_back(temp_player);

	}
	Player* activePlayer = &players[0];

	std::cout << "Setting up game" << endl;
	Deck* deck = new Deck(nbPlayer);
	//deck->toString();
	std::cout << "Shuffling Deck..." << endl;
	deck->shuffle();
	//deck->toString();

	Hand* hand = new Hand();

	std::cout << "Drawing Hand..." << endl;

	hand->deal(deck->draw());
	hand->deal(deck->draw());
	hand->deal(deck->draw());
	hand->deal(deck->draw());
	hand->deal(deck->draw());
	hand->deal(deck->draw());

	//cout << endl << "Display Hand: " << endl;
	//hand->toString();

	int choice = NULL;
	bool invalideChoice = true;
	int coins = *activePlayer->getCoins();
	Card chosenCard;
	bool gameON = true;

	do {
		choice = activePlayer->executeStrategy(hand, *activePlayer->getName(), coins);
						  
		chosenCard = hand->exchange(choice);
		hand->slideCards(choice);
		hand->addCard(deck->draw());
		activePlayer->setGoods(*chosenCard.getGood());


		//remove cost of card from player
		activePlayer->setCoins(coins - *chosenCard.getCost());

		//play card;

		std::cout << *chosenCard.getAction();
		
		bool invalideChoice = true;
		do{
			std::cout << "\nSet player strategy:\n0 - dont change anything\n1 - real player\n2 - greedy computer\n3 - moderate player";
			std::cin >> choice;
		
			switch (choice)
			{
				default: std::cout << "keep your selection between 0 and 3!" << endl; break;
				case 0: invalideChoice = false;  break;
				case 1: invalideChoice = false; activePlayer->setStrategy(new realPlayer()); break;
				case 2: invalideChoice = false; activePlayer->setStrategy(new greedyComputer()); break;
				case 3: invalideChoice = false; activePlayer->setStrategy(new moderateComputer()); break;
			}
		} while (invalideChoice);


		// see if game is finished
		activePlayer->addCard();
		gameON = false;
		switch (nbPlayer)
		{
		case 5: for (Player p : players)
			if (p.getNbCards() != 7)
				gameON = true; 
			break;
		case 4: for (Player p : players)
			if (p.getNbCards() != 8)
				gameON = true;
			break;
		case 3: for (Player p : players)
			if (p.getNbCards() != 10)
				gameON = true;
			break;
		case 2: for (Player p : players)
			if (p.getNbCards() != 13)
				gameON = true;
			break;
		}
		
		//pass handle to next player
		if (Player::equals(*activePlayer, players[nbPlayer-1]))
			activePlayer = &players[0];
		else
			activePlayer++;

		std::cin.get();
	} while (gameON);



	cout << "game finished!! ";
}