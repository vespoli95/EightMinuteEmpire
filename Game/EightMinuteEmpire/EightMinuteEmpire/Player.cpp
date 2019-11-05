#include "Player.h"


static void setArmies(vector<string> &v) {
	int i = 1;
	vector<string>::iterator ptr;
	for (string s : v) {
		v.push_back("test_" + i++);
	}
	/*for (ptr = v.begin(); ptr < v.end(); ptr++) {
		ptr->"test";
	}*/

}


Player::Player() {
	pName = new string("error");
	pCoins = new int(0);
	pAge = new int(0);
	pBiddingFacility = new BiddingFacility();
	playerHand = new Hand();
	pNumArmies = new int(14);
	//setArmies(*pArmies);
	int i = 1;

}

Player::Player(string name, int age)
{
	pName = new string(name);
	pCoins = new int(12);
	pAge = new int(age);
	pBiddingFacility = new BiddingFacility();
	playerHand = new Hand();
	pNumArmies = new int(14);

	
}




void Player::PayCoin() {
	cout << "You have reached " << *Player::getName() << "::PayCoin(), this will be implemented in a future release\n";
}

void Player::BuildCity(map<string, int> selected_region, Board &board) {
	//testing BuildCity()
	map<string, Region*> regions = board.getWorldMap();
	map<string, Region*>::iterator region_ptr;
	map<string, Region*>::iterator found;
	bool built = false;

	//add city to map of cities within a region if the selected region is valid in the map
	for (region_ptr = regions.begin(); region_ptr != regions.end(); region_ptr++) {
		found = regions.end();
		if (region_ptr->first == selected_region.begin()->first)
			found = region_ptr;
		if (found != regions.end()) {
			found->second->getCities()->insert(pair<string, int>(*getName(), 1));
			built = true;
		}
	}
	if (!built)
		cout << "Can't build a city there!";
}

void Player::PlaceNewArmies(int numArmies, map<string, int> placements, bool gameStart, Board &board) {	
	map<string, Region*> regions = board.getWorldMap();
	map<string, int>::iterator it;
	map<string, Region*>::iterator region;
	int matchCount = 0;
	Region startingRegion = board.getStartingRegion();
	bool gameStartAndNotGivenStartingRegion = false;

	//if its the start of the game, make sure placements given are all on the starting region
	if (gameStart) {
		for (it = placements.begin(); it != placements.end(); it++) {
			if (it->first != startingRegion.getName()) {
				gameStartAndNotGivenStartingRegion = true;
				break;
			}
		}
	}
	if (!gameStartAndNotGivenStartingRegion){
		for (it = placements.begin(); it != placements.end(); it++) {
			if (matchCount == placements.size())
				break;
			for (region = regions.begin(); region != regions.end(); region++) {
				if (region->first == it->first) {
					map<string, int>::iterator c;
					bool hasCity = false;
					for (c = region->second->getCities()->begin(); c != region->second->getCities()->end(); c++) {
						if (c->first == *getName()) {
							hasCity = true;
							break;
						}
					}

					//if has city or on starting region
					if (hasCity || startingRegion.getName() == region->second->getName()) {
						region->second->getArmies()->insert(pair<string, int>(*getName(), it->second));
						matchCount++;
						break;
					}
				}
			}
		}
	}
	else {
		cout << "Not in the starting region! The starting region is: " << startingRegion.getName() << endl;
	}

	

}
void Player::MoveArmies(int amount, map<string, string> moves, Board &board) {
	map<string, string>::iterator move;
	map<string, Region*>::iterator found;
	map<string, Region*>::iterator edge;
	map<string, Region*> regions = board.getWorldMap();


	for (move = moves.begin(); move != moves.end(); move++) {
		bool playerHasArmyOnRegion = false;
		found = regions.find(move->first);
		//find if this players armies are on the region
		map<string, int>::iterator army;
		map<string, int> *armies = found->second->getArmies();
		for (army = armies->begin(); army != armies->end(); army++) {
			if (army->first == *getName())
				return;
		}
		if (found != regions.end()) {
			map<string, Region*> land_edges = found->second->getLandEdges();
			for (edge = land_edges.begin(); edge != land_edges.end(); edge++) {
				if (edge->second->getName() == move->second) {
					map<string, int> *armies = edge->second->getArmies();
					armies->insert(pair<string, int>(*getName(), 1));
					
					break;
				}
			}
		}
	}
}

//void Player::RemoveArmy(Board &board,)

void Player::MoveOverLandOrWater() {
	cout << "You have reached " << *Player::getName() << "::MoveOverLand(), this will be implemented in a future release\n";
}

void Player::DestroyArmy() {
	cout << "You have reached " << *Player::getName() << "::DestroyArmy(), this will be implemented in a future release\n";
}

string Player::toString() {
	return ("player name: " + *Player::getName() + " coins: " + std::to_string(*Player::getCoins()));
}


bool Player::equals(Player p1, Player p2)
{
	if (p1.getName() == p2.getName())
		if (p1.getCoins() == p2.getCoins())
			if (p1.getAge() == p2.getAge())
				return true;
	return false;
}

int Player::computeScore()
{
	if (getGoods("Wild")) {
		cout << "you have " << getGoods("Wild") << " wild goods to distribute";
		cout << endl << "you can you your wild cards on:\n1. Carrot\n2. Forest\n3. Anvil\n4. Crystal\n5. Ore\n";
		int choice;
		for (int i = 0; i < getGoods("Wild"); i++) {
			cout << "choose wild card : ";
			cin >> choice;
			switch (choice)
			{
			default:cout << "wrong input try again";
				break;
			case 1:setGoods("Carrot"); break;
			case 2:setGoods("Forest"); break;
			case 3:setGoods("Anvil"); break;
			case 4:setGoods("Crystal"); break;
			case 5:setGoods("Ore"); break;
			}
		}
	}
	int score = 0;
	int goodsCalc = getGoods("Carrot");
	if (goodsCalc != 0)
		if (goodsCalc <= 3)
			score++;
		else if (goodsCalc <= 5)
			score = score + 2;
		else if (goodsCalc <= 7)
			score = score + 4;
		else if (goodsCalc >= 8)
			score = score + 7;

	cout << endl << score << endl;

	goodsCalc = getGoods("Forest");
	if (goodsCalc != 0)
		if (goodsCalc <= 2)
			score++;
		else if (goodsCalc <= 4)
			score = score + 2;
		else if (goodsCalc <= 5)
			score = score + 4;
		else if (goodsCalc >= 6)
			score = score + 7;

	cout << endl << score << endl;
	goodsCalc = getGoods("Anvil");
	if (goodsCalc != 0)
		if (goodsCalc <= 2)
			score++;
		else if (goodsCalc <= 4)
			score = score + 2;
		else if (goodsCalc <= 6)
			score = score + 4;
		else if (goodsCalc >= 7)
			score = score + 7;

	cout << endl << score << endl;
	goodsCalc = getGoods("Crystal");
	if (goodsCalc != 0)
		if (goodsCalc <= 1)
			score++;
		else if (goodsCalc <= 2)
			score = score + 2;
		else if (goodsCalc <= 3)
			score = score + 4;
		else if (goodsCalc >= 4)
			score = score + 7;
	cout << endl << score << endl;

	goodsCalc = getGoods("Ore");
	if (goodsCalc != 0)
		if (goodsCalc <= 2)
			score++;
		else if (goodsCalc <= 3)
			score = score + 2;
		else if (goodsCalc <= 4)
			score = score + 4;
		else if (goodsCalc >= 5)
			score = score + 7;
	cout << endl << score << endl;



	return score;
}