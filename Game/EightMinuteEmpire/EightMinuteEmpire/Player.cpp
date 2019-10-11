#include "BiddingFacility.h";
#include "Player.h";

Player::Player() {
	pName = new string("error");
	pCoins = new int(0);
	pAge = new int(0);
	pBiddingFacility = new BiddingFacility();
}

Player::Player(string name, int age)
{
	pName = new string(name);
	pCoins = new int(12);
	pAge = new int(age);
	pBiddingFacility = new BiddingFacility();
}













void Player::PayCoin() {
	cout << "You have reached " << *Player::getName() << "::PayCoin(), this will be implemented in a future release\n";
}

void Player::BuildCity() {
	cout << "You have reached " << *Player::getName() << "::BuildCity(), this will be implemented in a future release\n";
}

void Player::PlaceNewArmies() {
	cout << "You have reached " << *Player::getName() << "::PlaceNewArmies(), this will be implemented in a future release\n";
}

void Player::MoveArmies() {
	cout << "You have reached " << *Player::getName() << "::MoveArmies(), this will be implemented in a future release\n";
}

void Player::MoveOverLand() {
	cout << "You have reached " << *Player::getName() << "::MoveOverLand(), this will be implemented in a future release\n";
}

void Player::DestroyArmy() {
	cout << "You have reached " << *Player::getName() << "::DestroyArmy(), this will be implemented in a future release\n";
}