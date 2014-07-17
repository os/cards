#include <time.h>
#include "Deck.h"

Deck:: Deck() {
	for (int iSuit = 0; iSuit < 4; iSuit++)
		for (int iRank = 2; iRank < 15; iRank++)
			cards.push_back(Card(iRank, iSuit)); // fill the deck
}

void Deck::shuffle(int times) {
/* Shuffles the deck */
	int iPick;
	srand(time(0));

	for (int i = 0; i < times; i++) {
		iPick = rand() % 52; // pick a random card
		Card temp = cards[0];
		cards[0] = cards[iPick]; // swap cards
		cards[iPick] = temp;
	}
}

vector<Card> Deck::getCards(int count) {
/* Returns count of cards from the deck and then remove */
	vector<Card> result;

	if (count <= cards.size()) {
		result.assign(cards.end() - count, cards.end());
		cards.erase(cards.end() - count, cards.end());
	}

	return result;
}

Card Deck::draw() {
/* Picks a card from the top and removes it from the deck */
	Card result = cards.back();
	cards.pop_back();
	return result;
}
