#include <iostream>
#include <iomanip>
#include "Game.h"

Game::Game() {

}

void Game::start() {
/* Starts the game */
	displayInfo();
	initSettings();
	deck.shuffle();
	createPlayers();
	displaySeperator();

	int iWinner = 0, availablePasses, userAction;

	// play game
	for (int iTurn = 0, iPlayer = 0;
		   	 iTurn < turnLimit && activePlayers() > 1;
			 iTurn++, iPlayer = iTurn % players.size()) {
		if (!players[iPlayer].canPlay()) continue;

		availablePasses = passLimit - players[iPlayer].getPassCount();

		if (availablePasses) {
			table.show();
			players[iPlayer].showHand();
			cout << "It's your turn!" << endl;
			cout << "You still have " << availablePasses << " more pass";
			if (availablePasses > 1) cout << "es"; // plural form
			cout << endl;
			// check user answer
			userAction = askUserAction();
			if (userAction == Player::PASS) { // skip?
				players[iPlayer].pass();
				continue;
			}

			displaySeperator();
		}

		if (table.win(players[iPlayer].play()))
			players[iPlayer].win(table.getCards());
	}

	players[0].showHand();
	// check player points and find the winner
	for (int iPlayer = 1; iPlayer < players.size(); iPlayer++) {
		players[iPlayer].showHand();

		if (players[iPlayer].points() > players[iWinner].points())
			iWinner = iPlayer;
	}


	cout << "Winner is " << players[iWinner].getName() << endl;
}

void Game::displayInfo() {
/* Displays game title */
	cout << ":: BORINGAME ::" << endl;
}

void Game::initSettings() {
/* Gets game settings from the user */
	do {
		do {
			cout << "Please enter player count: ";
			cin >> playerCount;

			if (playerCount < 2)
				cout << "There must be at least 2 players!" << endl;
		} while (playerCount < 2);

		do {
			cout << "Please enter hand size: ";
			cin >> handSize;

			if (handSize < 2)
				cout << "Hand size cannot be less than 2!" << endl;
		} while (handSize < 2);

		if (playerCount * handSize > 52)
			cout << "Required card count exceeds the deck size!" << endl;
	} while (playerCount * handSize > 52);

	do {
		cout << "Please enter turn limit: ";
		cin >> turnLimit;

		if (turnLimit < playerCount)
			cout << "Turn limit cannot be less than player count!" << endl;
	} while (turnLimit < playerCount);

	do {
		cout << "Please enter pass limit: ";
		cin >> passLimit;

		if (passLimit < 0)
			cout << "Pass limit cannot be less than 0" << endl;
	} while (passLimit < 0);
}

void Game::createPlayers() {
/* Creates players */
	string playerName;

	for (int iPlayer = 0; iPlayer < playerCount; iPlayer++) {
		cout << "Player " << iPlayer + 1 << " name: ";
		cin >> playerName;
		players.push_back(Player(playerName, Hand(deck.getCards(handSize))));
	}
}

int Game::activePlayers() {
/* Returns the count of players who has card(s) to play */
	int result = 0;

	for (int i = 0; i < players.size(); i++)
		if (players[i].canPlay()) result++;

	return result;
}

int Game::askUserAction() {
/* Gets user input */
	int result;

	do {
		cout << "Pass(0) or Play(1): ";
		cin >> result;
	} while (result < 0 || result > 1);

	return result;
}

void Game::displaySeperator() {
	cout << setw(30) << setfill('*') << "" << setfill(' ') << endl;
}
