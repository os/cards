#include <iostream>
#include "Table.h"

Table::Table() {

}

bool Table::win(const Card &card) {
/* Puts the card on the table and checks if it wins */
	cards.push_back(card);

	for (int i = 0; i < (cards.size() - 1); i++)
		if (card.getRank() == cards[i].getRank())
			return true;

	return false;
}

vector<Card> Table::getCards() {
/* Returns the cards, including the winning one */
	vector<Card> result;

	for (int i = 0; i < cards.size(); i++) {
		if (cards[i].getRank() == cards.back().getRank()) {
			result.assign(cards.begin() + i, cards.end());
			cards.erase(cards.begin() + i, cards.end());
			break;
		}
	}

	return result;
}

void Table::show() {
/* Displays the cards on table */
	cout << "TABLE: ";
	if (!cards.size()) cout << "EMPTY";

	for (int i = 0; i < cards.size(); i++) {
		if (i) cout << '|';
		cout << cards[i].asString();
	}

	cout << endl;
}
