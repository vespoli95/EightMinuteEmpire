#include "map.h"

using namespace std;


Region::Region()
{
	name = "";
	ptr = NULL;
}

Region::Region(string regionname) {

	name = regionname;
	ptr->array;
}

Continent::Continent()
{
	name = "";
}

Continent::Continent(string continentname) {

	name = continentname;
}

void Continent::addregion(Region& regionname)
{
	empire::iterator itr = regionList.find(regionname.name);
	if (itr == regionList.end())
	{
		Region* v;
		v = new Region(regionname.name);
		regionList[regionname.name] = v;
		return;
	}
	cout << "\nRegion already exists!";
}



void Continent::printsize()
{
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

void Board::addregionobj(Region& regionname) {
	vmap::iterator itr = worldmap.find(regionname.name);  //search the worldmap to see if the region already exists
	if (itr == worldmap.end()) //if it doesn't exist, add it to the worldmap
	{
		Region* v;
		v = new Region(regionname.name);
		worldmap[regionname.name] = v;
		return;
	}
	cout << "\nRegion already exists!";
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
}

void Board::addcontinent(Continent& continentname)
{

	cmap::iterator itr = continents.find(continentname.name); //search the continent map to see if the continent already exists
	if (itr == continents.end()) //if it doesn't exist, add it to the continent map
	{
		Continent* cont;
		cont = new Continent(continentname.name);
		continents[continentname.name] = cont;
		return;
	}
	cout << "\nRegion already exists!";

}

void Board::printlist() {
	vmap::iterator itr;

	for (itr = worldmap.begin(); itr != worldmap.end(); ++itr) {
		cout << itr->first << '\n';
	}
}