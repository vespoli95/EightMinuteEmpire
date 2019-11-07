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
	~Region() {};
	inline map<string, int> *getArmies() { return armies; }
	inline map<string, int> *getCities() { return cities; }
	inline map<string, Region*> getLandEdges() { return land_edges; }
	inline map<string, Region*> getMarineEdges() { return marine_edges; }
	inline string getName() { return name; }

private:
	map<string, int> *armies = new map<string, int>();
	map<string, int> *cities = new map<string, int>();
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
public:
	inline Region& getStartingRegion() {return *startingRegion;};
	inline map<string, Region*> getWorldMap() { return worldmap; }
	inline map<string, Continent*> getContinents() { return continents; }
	static Board* getInstance();
	bool DFS(string regionname);
	void addregionandcontinent(string regionname, string continentname);
	Region& findregion(string regionname);
	Region& addregion(string regionname);
	void addlandedge(string edgeid, string regionname1, string regionname2);
	void addmarineedge(string edgeid, string regionname1, string regionname2);
	Continent& addcontinent(string continentname);
	bool addstartingregion(Region& regionname);
	int& getnbofregions();
	bool readfile(string filename);
	bool loadmap();
	void printlist();
	inline string *getLoadedMap() { return loadedMap; }
	Board();
	~Board() {};

private:
	Region *startingRegion = NULL;
	typedef map<string, Region*> vmap;
	vmap worldmap;
	typedef map<string, Continent*> cmap;
	cmap continents;
	int nodes = 0;
	void DFSitr(Region& vertex, vmap& visited);
	string *loadedMap = NULL;
	static Board* s_Instance;

	friend class Continent;
	friend class Region;
	friend class GameStart;
};


