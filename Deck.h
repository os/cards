#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

using namespace std;

class Deck {
public:
    Deck();
    void shuffle(int times=10000);
    vector<Card> getCards(int count);
    Card draw();
private:
    vector<Card> cards;
};

#endif
