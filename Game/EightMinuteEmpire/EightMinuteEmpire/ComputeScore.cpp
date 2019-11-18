#include "ComputeScore.h"
#include "GameStart.h"
#include "Player.h"
#include "map.h"

void computeScore() {
	string winner;
	int score = 0;
	int maxScore = 0;
	Board* mapofworld = Board::getInstance();
	int results;
	map<string, int>::iterator region_ptr2;

	if (mapofworld->loadmap()) {
		EXIT_FAILURE;
	}

	int nbPlayer = 3;

	vector<Player> players;
	for (int i = 1; i <= nbPlayer; i++)
	{
		string name = "p" + to_string(i);
		Player temp_player(name, 10 + i);
		temp_player.setGoods("Forest");
		temp_player.setGoods("Forest");
		temp_player.setGoods("Forest");
		temp_player.setGoods("Carrot");
		temp_player.setGoods("Forest");
		temp_player.setGoods("Crystal");
		//temp_player.setGoods("Wild");
		//temp_player.setGoods("Wild");
		map<string, int> temp{ {"R13", i+1 } };
		temp_player.PlaceNewArmies(temp, true, *mapofworld);
		players.push_back(temp_player);
	}
	for (Player p : players) {
		p.setplayerRegion(p.computeRegions(*mapofworld));
		std::cout<<endl << *p.getplayerRegion("R13") << "\n";
	}

	string regionName;
	Player* win;
	for (int i = 1; i <= 21; i++) {

		if (i < 10)
			regionName = "R0" + std::to_string(i);
		else
			regionName = "R" + std::to_string(i);
		win = &*players.begin();
		for (Player p : players)
		{
			p.setplayerRegion(p.computeRegions(*mapofworld));
			if (*p.getplayerRegion(regionName) > *win->getplayerRegion(regionName))
				win=&p;
		}
		for (Player p : players) {
			p.setplayerRegion(p.computeRegions(*mapofworld));
			//cout << "\n" << regionName << ": " << *win->getName() << ", " << *p.getName() << ", " << *p.getplayerRegion(regionName);
			if (*win->getName() == *p.getName())
				if (*p.getplayerRegion(regionName) != 0) 
					p.setScore(p.getScore() + 1);
			score = p.computeGoods();
			p.setScore(p.getScore() + score);
			//cout << *p.getName()<<", " <<p.getScore()<<endl;
			if (p.getScore() > maxScore) {
				maxScore = p.getScore();
				winner = *p.getName();
			}

		}
	}

			
	

	cout << "\n\n Winner is: " << winner << " with a score of "<<maxScore<<" Congratz!";
}