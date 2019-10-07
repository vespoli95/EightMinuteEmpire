#include "map.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;


int main()
{

	Board& mapofworld = Board::getInstance();	

	//mapofworld.readfile("C:\\map8.txt"); // SUCCESS
	mapofworld.readfile("C:\\fail8.txt"); // DISCONNECTED GRAPH

	mapofworld.printlist();

	mapofworld.DFS("R06");

	return 0;
}