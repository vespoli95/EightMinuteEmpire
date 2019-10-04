#include "map.h"

using namespace std;


Country::Country()
{
	name = "";
	ptr = NULL;
}

Country::Country(string countryname) {

	name = countryname;
	ptr->array;
}

Continent::Continent()
{
	name = "";
}

Continent::Continent(string continentname) {

	name = continentname;
}

void Continent::addcountry(Country& countryname)
{
	empire::iterator itr = countryList.find(countryname.name);
	if (itr == countryList.end())
	{
		Country* v;
		v = new Country(countryname.name);
		countryList[countryname.name] = v;
		return;
	}
	cout << "\nCountry already exists!";
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

void Board::addcountry(Country& countryname) {
	vmap::iterator itr = worldmap.find(countryname.name);
	if (itr == worldmap.end())
	{
		Country* v;
		v = new Country(countryname.name);
		worldmap[countryname.name] = v;
		return;
	}
	cout << "\nCountry already exists!";
}

void Board::addcontinent(Continent& continentname)
{

	cmap::iterator itr = continents.find(continentname.name);
	if (itr == continents.end())
	{
		Continent* cont;
		cont = new Continent(continentname.name);
		continents[continentname.name] = cont;
		return;
	}
	cout << "\nCountry already exists!";

}

void Board::printlist() {
	vmap::iterator itr;

	for (itr = worldmap.begin(); itr != worldmap.end(); ++itr) {
		cout << itr->first << '\n';
	}
}