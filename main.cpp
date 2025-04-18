#include <iostream>
#include "player.h"
#include "deck.h"
#include "cards.h"

using namespace std;


int main() {
	Deck deck;
	Player player(100);

	player.addCard(deck.dealCard());
	player.addCard(deck.dealCard());

	cout << "Hand of Player: " << endl;
	cout << player.showHand();

	cout << "Value of Players Hand: " << player.getHandValue() << endl;

	cout << (player.isLose() ? "You lose the hand\n" : "You are still in \n");

	return 0;
}