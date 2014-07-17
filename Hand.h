#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

using namespace std;

class Hand {
public:
	Hand();
	Hand(const vector<Card> &cards);
	Card turn();
    void show();
    void addCards(const vector<Card> &cards);
    int cardCount();
    string asString();
private:
    vector<Card> cards;
};

#endif
