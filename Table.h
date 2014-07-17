#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include "Card.h"

using namespace std;

class Table {
public:
	Table();
	bool win(const Card &card);
	vector<Card> getCards();
	void show();
private:
	vector<Card> cards;
};

#endif
