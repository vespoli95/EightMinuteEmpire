#include "map.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::ios;



int main()
{

	Board& mapofworld = Board::getInstance();
	
	//mapofworld.addregionandcontinent("Canada", "North America");
	//mapofworld.printlist();







	/*
//SHOULD be in the country constructor
//pointer to a particular country
string* start = map[0];
char a = 'a';
for (int i = 0; i < country_array_size; i++) {
	start[i] = a;
	a++;
}
//SHOULD be in the country constructor , see if Continent exists, if not create it and add country to it
Continent america("America");
for (int i = 0; i < country_array_size; i++) {
	cout << start[i] << " ";
}
cout << endl;
cout << &map[0] << endl;
cout << &start << endl;
cout << &map[0][0] << endl;
cout << &start[0] << endl;
america.addcountry(start);
america.printsize();
*/ // Proof of concept Proof of concept


	return 0;
}