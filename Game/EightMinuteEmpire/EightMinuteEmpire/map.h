#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

//A class Region holds a vector which is populated by pointers pointing to all countries within itself
class Region
{

public:
	Region();
	Region(string regionname);

private:
	typedef map<string, Region*> edges;
	Region* regionptr;
	string name;
	Region* array[8];
	edges land_edges;
	edges marine_edges;

	friend class Board;
	friend class Continent;
};


//A class Continent holds a vector which is populated by pointers pointing to all countries within itself
class Continent
{
public:
	Continent();
	Continent(string continentname);
	typedef map<string, Region*> empire;
	empire regionList;
	string name;
	Continent* ptr;

	void addregion(Region& v);

	void printsize();

private:

	friend class Region;
	friend class Board;

};



class Board
{
private:
	typedef map<string, Region*> vmap;
	vmap worldmap;
	typedef map<string, Continent*> cmap;
	cmap continents;
	Board();

	friend class Continent;

public:
	static Board& getInstance();

	void addregionobj(Region& regionname);

	Region& addregion(string regionname);

	void addcontinentobj(Continent& continentname);

	Continent& addcontinent(string continentname);

	void printlist();


};
