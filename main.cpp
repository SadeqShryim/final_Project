#include <iostream>
#include "player.h"
#include "deck.h"
#include "cards.h"
#include "BlackJack.h"
using namespace std;


int main() {
	//player test
	/*Deck deck;
	Player player(100);

	player.addCard(deck.dealCard());
	player.addCard(deck.dealCard());

	cout << "Hand of Player: " << endl;
	cout << player.showHand();

	cout << "Value of Players Hand: " << player.getHandValue() << endl;

	cout << (player.isLose() ? "You lose the hand\n" : "You are still in \n");*/

	////blackjack test - part 1
	Player player(100);
	Player dealer(0);
	BlackJack testGame(dealer, player);

	cout << "BLACK JACK" << endl;

	testGame.reset();
	testGame.dealCards();

	testGame.playerHand();
	testGame.dealerHand(false);

	testGame.playerTurn();


	cout << "Chose: \n1) Hit\n2) Stand " << endl;
	cout << "---------" << endl;
	return 0;
}