#include "map.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;


int main()
{

	Board& mapofworld = Board::getInstance();	

	//mapofworld.readfile("C:\\map1.txt"); // SUCCESS
	//mapofworld.readfile("C:\\map5.txt"); // SUCCESS
	//mapofworld.readfile("C:\\map6.txt"); // SUCCESS
	//mapofworld.readfile("C:\\map8.txt"); // SUCCESS
	//mapofworld.readfile("C:\\map9.txt"); // SUCCESS
	//mapofworld.readfile("C:\\map10.txt"); // SUCCESS
	//mapofworld.readfile("C:\\map12.txt"); // SUCCESS
	//mapofworld.readfile("C:\\map14.txt"); // SUCCESS

	//mapofworld.readfile("C:\\fail8.txt"); // DISCONNECTED GRAPH

	mapofworld.printlist();

	mapofworld.DFS("R02");

	return 0;
}