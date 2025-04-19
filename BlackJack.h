#ifndef BLACKJACK_H
#define BLACKJACK_H
#include "player.h"
#include "deck.h"
class BlackJack {

private:
	Deck deck;
	Player player;
	Player dealer;

public:
	void dealCards();
	void resetHands();
	void playRound();
};
#endif
