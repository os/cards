#include <string>
#include "Card.h"
#include "Utils.h"

string const Card::RANKS[] = {
	"Jack",
	"Queen",
	"King",
	"Ace"
};

string const Card::SUITS[] = {
	"Spades",
	"Hearts",
	"Diamonds",
	"Clubs"
};

Card::Card(int rank=2, int suit=0) {
    this->rank = rank;
    this->suit = suit;
}

int Card::getRank() const {
/* Returns card rank */
	return rank;
}

int Card::getSuit() {
/* Returns card suit */
	return suit;
}

string Card::asString() {
/* Returns the string representations of the card */
	return (rank > 10 ? RANKS[rank - 11].substr(0, 1) : toString(rank))
		   + SUITS[suit].substr(0, 1); // Jack = 11 and its RANKS[] index is 0
}
