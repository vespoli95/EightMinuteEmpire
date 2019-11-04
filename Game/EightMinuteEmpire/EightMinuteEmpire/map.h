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
	~Region(){};

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
	~Continent() {};
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
	Region* startingRegion;
	Board();
	~Board() {};

	friend class Continent;
	friend class Region;
	friend class GameStart;

public:
	static Board& getInstance();

	bool DFS(string regionname);

	void addregionandcontinent(string regionname, string continentname);

	inline Region& getStartingRegion() {

		return *startingRegion;

	};

	Region& findregion(string regionname);

	Region& addregion(string regionname);

	void addlandedge(string edgeid, string regionname1, string regionname2);

	void addmarineedge(string edgeid, string regionname1, string regionname2);

	Continent& addcontinent(string continentname);

	int& getnbofregions();

	bool readfile(string filename);

	bool loadmap();

	void printlist();


};
