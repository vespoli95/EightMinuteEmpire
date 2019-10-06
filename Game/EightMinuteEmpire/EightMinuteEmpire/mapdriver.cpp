#include "map.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::ios;

void readfile(string filename) {

	string regionname1, continentname, edgeid, regionname2;

	ifstream input(filename, ios::in);

	if (input.fail()) {
		cout << "File does not exist" << endl;
		cout << "Exit Program" << endl;
		return;
	}
	//mapping regions and continents
	while (!input.eof())
	{
		input >> regionname1;
		if (regionname1 == "LE") {
			cout << "switching to Land Edges " << endl;
			break;
		}
		else
		{
			input >> continentname;
			cout << "region name is : " << regionname1 << " which is part of continent: " << continentname << endl;
		}
		
	}
	//mapping land edges
	while (!input.eof())
	{
		input >> edgeid;
		if (edgeid == "ME") {
			cout << "switching to Marine Edges " << endl;
			break;
		}
		else
		{
			input >> regionname1 >> regionname2;
			cout << "edge " << edgeid << " links " << regionname1 << " and region " << regionname2 << " by land " << endl;
		}

	}
	//mapping marine edges
	while (!input.eof())
	{
		input >> edgeid >>regionname1 >> regionname2;
		cout << "edge " << edgeid << " links " << regionname1 << " and region " << regionname2 << " by sea " << endl;

	}
	   
	input.close();

}


int main()
{

	Board& mapofworld = Board::getInstance();	

	readfile("C:\\test.txt");




	return 0;
}