#include "Player.h";

Player::Player() {
	pName = new string("");
	pCoins = new int(12);
	pBiddingFacility = new BiddingFacility();
}

Player::Player(string name) {
	pName = new string(name);
	pCoins = new int(12);
	pBiddingFacility = new BiddingFacility();
}

Player::Player(string name, int age)
{
	pName = new string(name);
	pCoins = new int(12);
	pAge = new int(age);
	pBiddingFacility = new BiddingFacility();

}

string *Player::getName()
{
	return pName;
}

void Player::setName(string name)
{
	*pName = name;
}

int *Player::getCoins() {
	return pCoins;
}

void Player::setCoins(int coins) {
	*pCoins = coins;
}

int * Player::getAge()
{
	return pAge;
}

void Player::setAge(int age)
{
	*pAge = age;
}

BiddingFacility *Player::getBiddingFacility()
{
	return pBiddingFacility;
}

void Player::showBids()
{
	cout << "Name: " << *pName << " / Bid: " << *(pBiddingFacility->getBid()) << endl;

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