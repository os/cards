#ifndef CARD_H
#define CARD_H

using namespace std;

class Card {
public:
    Card(int rank, int suit);
    int getRank() const;
    int getSuit();
    string asString();
private:
    int rank;
    int suit;
    static const string RANKS[];
    static const string SUITS[];
};

#endif
