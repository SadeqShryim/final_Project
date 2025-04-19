#ifndef BLACKJACK_H
#define BLACKJACK_H
#include "player.h"
#include "deck.h"
using namespace std;
class BlackJack {

private:
	Deck deck;
	Player player;
	Player dealer;

public:
	BlackJack(const Player& dealer,const Player& player);
	void playerHand() const;
	void dealerHand(bool Reveal) const;
	void playRound();
	void reset();
	void dealCards();
	void reshuffle();

};
#endif
