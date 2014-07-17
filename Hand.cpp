#include <iostream>
#include <assert.h>
#include "Hand.h"

Hand::Hand() {

}

Hand::Hand(const vector<Card> &cards) {
	this->cards = cards;
}

Card Hand::turn() {
/* Returns the first card and removes it from the hand */
	Card card = cards.front();
	cards.erase(cards.begin());
	return card;
}

void Hand::addCards(const vector<Card> &cards) {
/* Add cards to hand */
	vector<Card>::iterator iter = this->cards.end();
	this->cards.insert(iter, cards.begin(), cards.end());
}

void Hand::show() {
/* Print all cards */
	cout << asString();
	cout << endl;
}

string Hand::asString() {
	string result;

	for (int i = 0; i < cards.size(); i++)
		result += cards[i].asString() + " ";

	return result;
}

int Hand::cardCount() {
	return cards.size();
}
