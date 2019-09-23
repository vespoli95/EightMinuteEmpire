#include "Player.h"

Player::Player() {
	name = "";
	coins = 12;
}

Player::Player(string name) {
	this->name = name;
	coins = 12;
}

BiddingFacility& Player::getBiddingFacility()
{
	return biddingFacility;
}

void Player::showBids()
{
	cout << "Name: " << name << " / Bid: " << biddingFacility.getBid() << endl;

}

string Player::getName()
{
	return name;
}

void Player::setName(string name)
{
	this->name = name;
}

void Player::Print() {
	cout << "Name: " << name << " / Coins: " << coins << endl;
}

int Player::getCoins() {
	return coins;
}

void Player::setCoins(int coins) {
	this->coins = coins;
}

void Player::PayCoin() {

}

void Player::BuildCity() {

}

void Player::PlaceNewArmies() {

}

void Player::MoveArmies() {

}

void Player::MoveOverLand() {

}

void Player::DestroyArmy() {

}