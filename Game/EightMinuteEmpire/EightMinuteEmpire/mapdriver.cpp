#include "map.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;


static int mapDriver()
{

	Board& mapofworld = Board::getInstance();	
		
	mapofworld.readfile("resource/map6.txt"); 


	return 0;
}