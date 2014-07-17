#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Deck.h"
#include "Player.h"
#include "Table.h"

using namespace std;

class Game {
public:
    Game();
    void start();
    void end();
    int activePlayers();
private:
    Deck deck;
    Table table;
    vector<Player> players;
    int turnLimit;
    int passLimit;
    int playerCount;
    int handSize;

    int askUserAction();
    void displayInfo();
    void initSettings();
    void createPlayers();
    void displaySeperator();
};

#endif
