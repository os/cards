#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Hand.h"

using namespace std;

class Player {
public:
	Player(const string &name, const Hand &hand);
	string getName();
	Card play();
	void win(const vector<Card> &cards);
	int points();
	bool canPlay();
	int getPassCount();
	void showHand();
	void pass();
	enum ACTIONS {PASS, PLAY};
private:
    string name;
    Hand hand;
    int passCount;
};

#endif
