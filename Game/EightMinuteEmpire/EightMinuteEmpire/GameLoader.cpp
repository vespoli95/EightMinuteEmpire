#include "map.h"
#include "GameLoader.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;



static int GameLoader()
{

	Board& mapofworld = Board::getInstance();

	mapofworld.loadmap();

	return 0;
}