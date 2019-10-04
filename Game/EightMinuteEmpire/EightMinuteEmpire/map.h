#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

//A class Country holds a vector which is populated by pointers pointing to all countries within itself
class Country
{

public:
	Country();
	Country(string countryname);

private:
	int MAX = 8;
	typedef map<string, Country*> edges;
	Country* ptr;
	string name;

	Country* array[8];
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
	typedef map<string, Country*> empire;
	empire countryList;
	string name;
	Continent* ptr;

	void addcountry(Country& v);

	void printsize();

private:

	friend class Country;
	friend class Board;

};



class Board
{
private:
	typedef map<string, Country*> vmap;
	vmap worldmap;
	typedef map<string, Continent*> cmap;
	cmap continents;
	Board();

	friend class Continent;

public:
	static Board& getInstance();

	void addcountry(Country& countryname);

	void addcontinent(Continent& continentname);

	void printlist();


}; #pragma once
