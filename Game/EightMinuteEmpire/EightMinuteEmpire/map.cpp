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

void Continent::addregion(Region& regionname) {
	empire::iterator itr = regionList.find(regionname.name);  //search the worldmap to see if the region already exists
	if (itr == regionList.end()) //if it doesn't exist, add it to the worldmap
	{
		regionList[regionname.name] = &regionname;
		return ;
	}
	cout << "\nRegion already exists!";
	//Region* x = itr->second;
	return;
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
	cmap continents;
}

Board& Board::getInstance() {

	static Board theInstance;

	return theInstance;
}

void Board::addregionandcontinent(string regionname, string continentname) {
	Region& x = Board::addregion(regionname);
	cout << "Region created/found: " << x.name << endl;
	Continent& y = Board::addcontinent(continentname);
	cout << "Continent created/found: " << y.name << endl;
	y.addregion(x);
	y.print();
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
	cout << "Here are the countries that have been created" << endl;
	for (itr = worldmap.begin(); itr != worldmap.end(); ++itr) {
		cout << itr->first << '\n';
	}
	cmap::iterator ctr;
	cout << "Here are the continents that have been created" << endl;
	for (ctr = continents.begin(); ctr != continents.end(); ++ctr) {
		cout << ctr->first << '\n';
	}
}