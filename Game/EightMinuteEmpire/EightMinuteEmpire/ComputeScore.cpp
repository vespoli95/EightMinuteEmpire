#include "ComputeScore.h"
#include "GameStart.h"
#include "Player.h"
#include "map.h"

void computeScore() {

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
		players.push_back(temp_player);


	}

	for (Player p : players)
	{
		cout << "counting player: " << *p.getName() << endl;
		cout << "score: " << p.computeScore() << endl;
	}
}