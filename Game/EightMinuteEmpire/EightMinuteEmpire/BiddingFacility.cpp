#include "BiddingFacility.h"


	BiddingFacility::BiddingFacility() {
		this->bid = 0;
	}

	BiddingFacility::BiddingFacility(int bid) {
		this->bid = bid;
	}

	void BiddingFacility::start() {
		cout << "How much would you like to bid? " << endl;
		int bid;
		cin >> bid;
		setBid(bid);
	}

	int BiddingFacility::getBid() const
	{
		return bid;
	}

	void BiddingFacility::setBid(int bid)
	{
		this->bid = bid;
	}
