#include <iostream>
#include "main.h"
#include "map.h"
#include "GameStart.h"
#include "GameStartDriver.cpp"
#include "BiddingFacilityDriver.cpp"
#include "Observer_Part_3.cpp"
#include "Observer_Part_2.cpp"
using namespace std;

int main()
{
	/*int answer = -1;
	while (answer != 0) {
		cout << "\n\nHello, please choose an option:\n"
			<< "1 Observer driver\n"
			<< "2 Stats Observer driver\n"
			<< "0 to exit\n";
		cin >> answer;

		if (answer == 1)
			obsDriver();
		else if (answer == 2)
			StatDriver();
	}*/

	cout << "Setting up game" << endl;
	Deck* deck = new Deck(3);
	deck->toString();

	system("pause");
	return 0;

}
