#include "BiddingFacility.h"


	BiddingFacility::BiddingFacility() {
		this->pBid = new int(0);
	}

	BiddingFacility::BiddingFacility(int bid) {
		this->pBid = new int(bid);
	}

	int *BiddingFacility::getBid()
	{
		return pBid;
	}

	void BiddingFacility::setBid(int bid)
	{
		*pBid = bid;
	}

	void BiddingFacility::start() {
		int bid;
		cin >> bid;
		setBid(bid);
	}

