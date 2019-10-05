#include "map.h"

using namespace std;


Region::Region()
{
	name = "";
	regionptr = NULL;
}

Region::Region(string regionname) {

	name = regionname;
	regionptr->array;
}

Continent::Continent()
{
	name = "";
}

Continent::Continent(string continentname) {

	name = continentname;
}

void Continent::print()
{
	empire::iterator itr;

	for (itr = regionList.begin(); itr != regionList.end(); ++itr) {
		cout << itr->first << '\n';
	}
	
}





Board::Board() {
	//create a single map data structure throughout the game instance that hold a pointer to all the continents 
	vmap worldmap;

	//create a single map data structure throughout the game instance that hold a pointer to all the continents 
	map <string, Continent*> continents;
}

Board& Board::getInstance() {

	static Board theInstance;

	return theInstance;
}

void Board::addregionandcontinent(string regionname, string continentname) {
	Region& x = Board::addregion(regionname);
	cout << x.name << endl;
	Continent& y = Board::addcontinent(continentname);
	cout << y.name << endl;
}


Region& Board::addregion(string regionname) {
	vmap::iterator itr = worldmap.find(regionname);  //search the worldmap to see if the region already exists
	if (itr == worldmap.end()) //if it doesn't exist, add it to the worldmap
	{
		Region* v;
		v = new Region(regionname);
		worldmap[regionname] = v;
		return *v;
	}
	cout << "\nRegion already exists!";
	Region* x = itr->second;
	return *x;
}


Continent& Board::addcontinent(string continentname)
{

	cmap::iterator itr = continents.find(continentname); //search the continent map to see if the continent already exists
	if (itr == continents.end()) //if it doesn't exist, add it to the continent map
	{
		Continent* cont;
		cont = new Continent(continentname);
		continents[continentname] = cont;
		return *cont;
	}
	cout << "\nRegion already exists!";
	Continent* x = itr->second;
	return *x;

}


void Board::printlist() {
	vmap::iterator itr;

	for (itr = worldmap.begin(); itr != worldmap.end(); ++itr) {
		cout << itr->first << '\n';
	}
}