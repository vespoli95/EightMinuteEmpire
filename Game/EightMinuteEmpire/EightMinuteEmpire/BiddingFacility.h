#pragma once
#include <iostream>

using namespace std;

class BiddingFacility {
private:
	int *pBid;
public:
	BiddingFacility();
	BiddingFacility(int bid);
	virtual ~BiddingFacility();
	void start();
	int *getBid();
	void setBid(int bid);
};

