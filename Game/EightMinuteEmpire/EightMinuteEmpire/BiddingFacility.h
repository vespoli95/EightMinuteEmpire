#pragma once
#include <iostream>

using namespace std;

class BiddingFacility {
	private:
		int bid;
	public:
		BiddingFacility();
		BiddingFacility(int bid);
		void start();
		int getBid() const;
		void setBid(int bid);
};