#include "map.h"
#include "GameLoader.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;

Game::Game() {

	Board& mapofworld = Board::getInstance();
	mapofworld.loadmap();


}


Game& Game::getInstance() {

	static Game theInstance;

	return theInstance;
}

void Game::loadplayers() {



}

static int GameLoader()
{

	Game& newgame = Game::getInstance();


	return 0;
}