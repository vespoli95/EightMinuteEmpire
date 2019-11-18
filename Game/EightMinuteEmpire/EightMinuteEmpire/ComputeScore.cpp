#include "ComputeScore.h"
#include "GameStart.h"
#include "Player.h"
#include "map.h"

void main() {
	string winner;
	int score = 0;
	int maxScore = 0;
	Board* mapofworld = Board::getInstance();

	if (mapofworld->loadmap()) {
		EXIT_FAILURE;
	}

	int nbPlayer = 3;

	vector<Player> playerss;
	playerss.reserve((nbPlayer));

	for (int i = 1; i <= nbPlayer; i++)
	{
		cout << "\n\n\n" <<i<<"\n\n\n";
		string name = "p" + to_string(i);
		Player temp_player(name, 10 + i);
		temp_player.setGoods("Forest");
		temp_player.setGoods("Forest");
		temp_player.setGoods("Forest");
		temp_player.setGoods("Carrot");
		temp_player.setGoods("Forest");
		temp_player.setGoods("Crystal");
		//temp_player.setGoods("Wild");
		//temp_player.setGoods("Wild");*/
		//map<string, int> temp{ {"R13", i + 1} };
		//temp_player.PlaceNewArmies(temp, true, *mapofworld);
		cout << temp_player.toString();
		playerss.push_back(temp_player);
	}
	cout << "\n\n\n OK4\n\n\n" << playerss.size();
	std::vector<Player>::iterator it;
	for (it = playerss.begin(); it!=playerss.end();++it)
	{
		
		cout << "\ncounting player: " << *it->getName() << endl;
		score= it->computeGoods();
		it->setScore(score);
		cout << "score: " << score <<endl;
		if (score > maxScore) {
			maxScore = score;
			winner = *it->getName();
		}
	}
	
	

	cout << "\n\n Winner is: " << winner << " with a score of "<<maxScore<<" Congratz!";
}