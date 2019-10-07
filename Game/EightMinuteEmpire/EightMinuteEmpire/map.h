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
	string* array[8];
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

	void addregion(Region& regionname);

	void print();

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
	int nodes = 0;
	void DFSitr(Region& vertex, vmap& visited);
	Board();

	friend class Continent;
	friend class Region;

public:
	static Board& getInstance();

	void DFS(string regionname);

	void addregionandcontinent(string regionname, string continentname);

	Region& findregion(string regionname);

	Region& addregion(string regionname);

	void addlandedge(string edgeid, string regionname1, string regionname2);

	void addmarineedge(string edgeid, string regionname1, string regionname2);

	Continent& addcontinent(string continentname);

	int& getnbofregions();

	void readfile(string filename);

	void printlist();


};
