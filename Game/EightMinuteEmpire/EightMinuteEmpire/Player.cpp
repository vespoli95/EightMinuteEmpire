#include "Player.h"


static void setArmies(vector<string>& v) {
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

bool Player::Ignore()
{
	char answer;
	cout << "Would you like to ignore this action? (Y/N)" << endl;
	cin >> answer;
	if (answer == 'Y' || answer == 'y')
		return true;
	else if (answer == 'N' || answer == 'n')
		return false;
	else {
		cout << "Incorrect input." << endl;
		this->Ignore();
	}
	return false;
}


void Player::BuildCity(map<string, int> selected_region, Board& board) {
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

void Player::PlaceNewArmies(map<string, int> placements, bool gameStart, Board& board) {
	map<string, Region*> regions = board.getWorldMap();
	map<string, int>::iterator it;
	map<string, Region*>::iterator region;
	map<string, int>::iterator army;
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
	if (!gameStartAndNotGivenStartingRegion) {
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
					if (hasCity || startingRegion.getName() == region->second->getName() || *this->getName() == "AIPlayer") {
						map<string, int>* armies = region->second->getArmies();
						army = armies->find(*getName());
						if (army != armies->end()) {
							army->second += it->second;
						}
						else
							region->second->getArmies()->insert(pair<string, int>(*getName(), it->second));

						matchCount++;
						pNumArmies--;
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


void Player::RemoveArmy(Board& board, Region& region) {
	map<string, int>* armies = region.getArmies();
	map<string, int>::iterator army;

	for (army = armies->begin(); army != armies->end(); army++) {
		if (army->first == *getName()) {
			if (army->second == 1)
				armies->erase(army);
			else
				army->second--;
			break;
		}

	}

}

bool Player::DestroyArmy(string playerName, string regionName, Board& board)
{
	map<string, Region*> regions = board.getWorldMap();
	map<string, Region*>::iterator found;

	found = regions.find(regionName);
	if (found != regions.end()) {
		map<string, int>* armies = found->second->getArmies();
		map<string, int>::iterator army;
		for (army = armies->begin(); army != armies->end(); army++) {
			if (army->first == playerName) {
				if (army->second > 1)
					army->second--;
				else
					armies->erase(army);
				cout << "1 of " << playerName << "'s army deleted on " << regionName << endl;
				return true;
			}
		}
	}
	else {
		cout << "Region does not exist on map." << endl;
		return false;
	}

	cout << "Army unable to be deleted.";
	return false;
}

//returns a vector of the indices of the and/or card selection
vector<int> Player::AndOr(Card& card)
{
	vector<int> chosenCards{};
	int answer;
	bool isOr = false, isAnd = false;
	if (card.getAction()->find("or") != string::npos) {
		isOr = true;
		do {
			cout << "Which action do you want to choose, 1 or 2?" << endl;
			cin >> answer;
		} while (answer != 1 && answer != 2);
		chosenCards.push_back(answer - 1);
	}
	else if (card.getAction()->find("and") != string::npos) {
		chosenCards.push_back(0);
		chosenCards.push_back(1);
	}
	else
		cout << "This card is not an and/or card." << endl;

	return chosenCards;
}


void Player::MoveArmies(bool moveOverWater, int amount, map<string, string> moves, Board& board) {
	map<string, string>::iterator move;
	map<string, Region*>::iterator found;
	map<string, Region*>::iterator edge;
	map<string, Region*> regions = board.getWorldMap();

	for (int i = 0; i < amount; i++) {
		for (move = moves.begin(); move != moves.end(); move++) {
			//find if this players' armies are on the region
			bool playerHasArmyOnRegion = false;
			found = regions.find(move->first);
			map<string, int>::iterator army;
			map<string, int>* armies = found->second->getArmies();
			for (army = armies->begin(); army != armies->end(); army++) {
				if (army->first == *getName()) {
					playerHasArmyOnRegion = true;
				}

			}
			if (playerHasArmyOnRegion) {
				//if they are, find if there's an edge from that region to the region they wish to move to
				if (found != regions.end()) {
					map<string, Region*> edges = moveOverWater ? found->second->getMarineEdges() : found->second->getLandEdges();
					for (edge = edges.begin(); edge != edges.end(); edge++) {
						if (edge->second->getName() == move->second) {
							map<string, int>* armies = edge->second->getArmies();
							armies->insert(pair<string, int>(*getName(), 1));
							RemoveArmy(board, *found->second);
							break;
						}
						else {
							cout << "There's no " << (moveOverWater ? "land" : "marine") << " edge there!" << endl;
						}
					}
				}
			}
			else {
				cout << "You do not have an army on this region!" << endl;
			}

		}
	}

}

bool Player::compare(Player player) {
	if (this->pAge == player.getAge() && this->pCoins == player.getCoins() && this->pName == player.getName()) {
		return true;
	}
	else
		return false;
}

void Player::MoveOverLand(int amount, map<string, string> moves, Board& board)
{
	MoveArmies(false, amount, moves, board);
}

void Player::MoveOverWater(int amount, map<string, string> moves, Board& board)
{
	MoveArmies(true, amount, moves, board);
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

int Player::computeGoods()
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

	//cout << endl << score << endl;

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

	//cout << endl << score << endl;
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

	//cout << endl << score << endl;
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
	//cout << endl << score << endl;

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
	//	cout << endl << score << endl;



	return score;
}

map<string, int> Player::computeRegions(Board& board) {
	map<string, int> results;
	map<string, Region*> regions = board.getWorldMap();
	map<string, Region*>::iterator region_ptr;
	map<string, int>::iterator region_ptr2;
	for (region_ptr = regions.begin(); region_ptr != regions.end(); region_ptr++) {
		//cout << endl << region_ptr->first;
		for (region_ptr2 = region_ptr->second->getArmies()->begin(); region_ptr2 != region_ptr->second->getArmies()->end(); region_ptr2++) {
			//cout << endl << region_ptr2->first << " " << region_ptr2->second;
			if (getName()->_Equal(region_ptr2->first))
				results.insert({ region_ptr->first, region_ptr2->second });
		}
		if (region_ptr->second->getArmies()->empty())
			results.insert({ region_ptr->first, 0 });
	}
	playerRegionsMap = results;
	return results;
}
