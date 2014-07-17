#include <iostream>
#include "Player.h"

Player::Player(const string &name, const Hand &hand) {
	this->name = name;
	this->hand = hand;
	passCount = 0;
}

string Player::getName() {
/* Returns user name */
	return name;
}

Card Player::play() {
/* Returns the last card on hand */
	return hand.turn();
}

void Player::win(const vector<Card> &cards) {
/* Adds cards to user's hand */
	hand.addCards(cards);
}

int Player::points() {
/* Returns user points */
	return hand.cardCount();
}

bool Player::canPlay() {
/* Returns user availability */
	return points() > 0;
}

void Player::showHand() {
/* Shows user hand */
	cout << name << ": " << hand.asString() << endl;
}

int Player::getPassCount() {
/* Returns user pass count */
	return passCount;
}

void Player::pass() {
/* Adds one more pass */
	passCount++;
}
