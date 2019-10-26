#include <iostream>
#include <fstream>
#include "map.h"
#include "Gamestart.h"


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
	//cout << "\nRegion already exists!";
	//Region* x = itr->second;
	return;
}

void Continent::print()
{
	empire::iterator itr;

	for (itr = regionList.begin(); itr != regionList.end(); ++itr) {
		cout << itr->first << '\n';
		//cout << itr->second->name << '\n'; //test to see if both return same content
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

void Board::DFSitr(Region& vertex, vmap& visited)
{	
	// Mark the current node as visited and print it
	visited[vertex.name] = &vertex;
	cout << vertex.name << " ";
	
	// Recur for all adjacent nodes to this node 
	vmap::iterator itr;
	vmap::iterator chk;
	for (itr = vertex.land_edges.begin(); itr != vertex.land_edges.end(); ++itr){
		string regionname = itr->second->name;
		chk = visited.find(regionname);
		Region* ptr = itr->second;
		if (chk == visited.end()) {
			DFSitr(*ptr, visited);
		}
	}
	vmap::iterator mitr;
	vmap::iterator mchk;
	for (mitr = vertex.marine_edges.begin(); mitr != vertex.marine_edges.end(); ++mitr) {
		string mregionname = mitr->second->name;
		mchk = visited.find(mregionname);
		Region* mptr = mitr->second;
		if (mchk == visited.end()) {
			DFSitr(*mptr, visited);
		}
	}
}

// DFS traversal of the nodes reachable from node
bool Board::DFS(string regionname)
{
	typedef map<string, Region*> vmap;
	vmap visited;
	vmap* visitedptr = &visited;
	int verification;

	Region& vertex = findregion(regionname);
	cout <<"\n"<<"The DFS is as follows | ";
	DFSitr(vertex, *visitedptr);
	verification = visited.size();

	if(verification==nodes){
		cout <<"| all  " << nodes << " regions accounted for! " << endl;
		cout << "Map is valid" << endl;
		return true;
	}
	else {
		cout << "| there is(are)  " << (nodes-verification) << " node(s) missing for this graph to be connected! " << endl;

		cout << "Map is invalid !" << endl;
		return false;
	}
}

void Board::addregionandcontinent(string regionname, string continentname) {
	Region& x = Board::addregion(regionname);
	++nodes;
	//cout << "Region created/found: " << x.name << endl;
	Continent& y = Board::addcontinent(continentname);
	//cout << "Continent created/found: " << y.name << endl;
	y.addregion(x);
	//y.print();
}

Region& Board::findregion(string regionname) {
	vmap::iterator itr = worldmap.find(regionname);  //search the worldmap to see if the region already exists
	if (itr == worldmap.end()) 
	{
		cout << "\nRegion doesn't exists!";
	}
	//cout << "\nRegion already exists!";
	Region* x = itr->second;
	return *x;
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
	//cout << "\nRegion already exists!";
	Region* x = itr->second;
	return *x;
}

void Board::addlandedge(string edgeid, string regionname1, string regionname2) {
	Region& x = findregion(regionname1);
	Region& y = findregion(regionname2);

	//place <edgeid,region1 pointer> in Land Edge of region1
	vmap::iterator itr = x.land_edges.find(edgeid);  
	if (itr == x.land_edges.end()) {
		x.land_edges[edgeid] = &y;
	}
	//place <edgeid,region2 pointer> in Land Edge of region2
	vmap::iterator cnt = y.land_edges.find(edgeid);  
	if (cnt == y.land_edges.end())
	{
		y.land_edges[edgeid] = &x;
	}

	return;

}

void Board::addmarineedge(string edgeid, string regionname1, string regionname2) {
	Region& x = findregion(regionname1);
	Region& y = findregion(regionname2);

	//place <edgeid,region1 pointer> in Land Edge of region1
	vmap::iterator itr = x.marine_edges.find(edgeid);
	if (itr == x.marine_edges.end()) {
		x.marine_edges[edgeid] = &y;
	}
	//place <edgeid,region2 pointer> in Land Edge of region2
	vmap::iterator cnt = y.marine_edges.find(edgeid);
	if (cnt == y.marine_edges.end())
	{
		y.marine_edges[edgeid] = &x;
	}

	return;

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
	//cout << "\nContinent already exists!";
	Continent* x = itr->second;
	return *x;

}

int& Board::getnbofregions() {

	return nodes;
}

bool Board::readfile(string filename) {

	string regionname1, continentname, edgeid, regionname2;

	ifstream input(filename, ios::in);

	if (input.fail()) {
		cout << "File does not exist" << endl;
		//cout << "Program will terminate safely" << endl;
		return false;
	}
	//mapping regions and continents
	while (!input.eof())
	{
		input >> regionname1;

		if ((regionname1.length() < 3) && (regionname1 != "LE")) {
			cout << "File does not contain valid map format" << endl;
			//cout << "Program will terminate safely" << endl;
			return false;
		}

		if (regionname1 == "LE") {
			//cout << "switching to Land Edges " << endl;
			break;
		}
		else
		{
			input >> continentname;

			if (continentname.length() < 3) {
				cout << "File does not contain valid map format" << endl;
				//cout << "Program will terminate safely" << endl;
				return false;
			}
			//cout << "region name is : " << regionname1 << " which is part of continent: " << continentname << endl;
			addregionandcontinent(regionname1, continentname);
		}

	}
	//mapping land edges
	while (!input.eof())
	{
		input >> edgeid;

		if ((edgeid.length() < 3) && (edgeid != "ME")) {
			cout << "File does not contain valid map format" << endl;
			//cout << "Program will terminate safely" << endl;
			return false;
		}

		if (edgeid == "ME") {
			//cout << "switching to Marine Edges " << endl;
			break;
		}
		else
		{
			input >> regionname1 >> regionname2;

			if ((regionname1.length() < 3) || (regionname2.length() < 3)) {
				cout << "File does not contain valid map format" << endl;
				//cout << "Program will terminate safely" << endl;
				return false;
			}

			//cout << "edge " << edgeid << " links " << regionname1 << " and region " << regionname2 << " by land " << endl;
			addlandedge(edgeid, regionname1, regionname2);
		}

	}
	//mapping marine edges
	while (!input.eof())
	{
		input >> edgeid >> regionname1 >> regionname2;
		
		if ((edgeid.length() < 3) || (regionname1.length() < 3) || (regionname2.length() < 3)) {
			cout << "File does not contain valid map format" << endl;
			//cout << "Program will terminate safely" << endl;
			return false;
		}

		//cout << "edge " << edgeid << " links " << regionname1 << " and region " << regionname2 << " by sea " << endl;
		addmarineedge(edgeid, regionname1, regionname2);
	}

	input.close();

	if (DFS("R01")) {

		printlist();
		return true;
	}
	else
	{
		return false;
	}

}

void Board::loadmap() {
	string folder = "resource/", answer, file, ext = ".txt";
	bool pursue = true;
	int count = 0;

	while (pursue) {
		cout << "\n\nHello, please enter the name of the map you want to load: " << endl;
		cin >> answer;
		file = folder + answer + ext;

		if (readfile(file)) {
			pursue = false;
		}
		else {
			count++;
			file = "";

			if (count == 5) {
				cout << "Attempt #" << count << "! Too many failed attempts, please try again later" << endl;
				pursue = false;
				break;
			}

			cout << "Attempt #" << count << "\nPlease try again" << endl;

		}

	}

}

void Board::printlist() {
	typedef map<string, Region*> rmap;
	//Print all the regions on the board and its respective edges
	vmap::iterator itr;
	cout << "Here are the "<< nodes <<" countries that have been created" << endl;
	for (itr = worldmap.begin(); itr != worldmap.end(); ++itr) {
		cout << itr->first << '\n';
		//print each edge within each continent
		rmap::iterator landitr;
		for (landitr = itr->second->land_edges.begin(); landitr != itr->second->land_edges.end(); ++landitr) {
			cout << '\t' << landitr->first << '\t' << landitr->second->name << '\n';
		}
		rmap::iterator seaitr;
		for (seaitr = itr->second->marine_edges.begin(); seaitr != itr->second->marine_edges.end(); ++seaitr) {
			cout << '\t' << seaitr->first << '\t' << seaitr->second->name << '\n';
		}
		cout << '\n';
	}
	
	//Print all the continents on the board and which regions they include
	cmap::iterator ctr;
	cout << "Here are the continents that have been created" << endl;
	for (ctr = continents.begin(); ctr != continents.end(); ++ctr) {
		cout << ctr->first << '\n';
		//print each region within each continent
		rmap::iterator cnt;
		for(cnt = ctr->second->regionList.begin(); cnt != ctr->second->regionList.end();++cnt){
		cout << '\t' << cnt->first << " ";
		}
		cout << '\n';
	}
	



	//cout << "Here are the edges present for each country " << endl;
	//for (itr = worldmap.begin(); itr != worldmap.end(); ++itr) {
	//	cout << itr->second << '\n';
	//}


}