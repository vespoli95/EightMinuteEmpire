#include "ComputeScore.h"
#include "GameStart.h"
#include "Player.h"
#include "map.h"

void computeScore() {
	string winner;
	int score = 0;
	int maxScore = 0;
	Board* mapofworld = Board::getInstance();
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
		temp_player.setGoods("Wild");
		temp_player.setGoods("Wild");
		map<string, int> temp{ {"R13", i + 1} };
		temp_player.PlaceNewArmies(temp, true, *mapofworld);
		players.push_back(temp_player);
	}
	
	for (Player p : players)
	{
		cout << "\ncounting player: " << *p.getName() << endl;
		score= p.computeGoods();
		p.setScore(score);
		cout << "score: " << score <<endl;
		if (score > maxScore) {
			maxScore = score;
			winner = *p.getName();
		}
	}

	

	cout << "\n\n Winner is: " << winner << " with a score of "<<maxScore<<" Congratz!";
}