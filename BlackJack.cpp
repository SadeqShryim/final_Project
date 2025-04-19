#include <iostream>
#include<string>
#include "BlackJack.h"

using namespace std;

BlackJack::BlackJack(const Player& dealer, const Player& player) {
	this->dealer = dealer;
	this->player = player;
}
void BlackJack::playerHand() const {
	cout << "This is your hand: " << endl;
	cout << player.showHand();
	cout << "Total: " << player.getHandValue() << endl << endl;

}
void BlackJack::dealerHand(bool Reveal) const {
	cout << "This is the Dealer's Hand: " << endl;
	if(Reveal){
		cout << dealer.showHand();
		cout << "Total: " << dealer.getHandValue() << endl << endl;
	}
	else {
		cout << dealer.getCardAt(0).toString() << endl;
		cout << "There is one card that is hidden..." << endl;
	}
}
void BlackJack::playRound() {
	reset();
	dealCards();
	playerHand();
	dealerHand(false);
}
void BlackJack::reset() {

	dealer.clearHand();
	player.clearHand();
	
}

void BlackJack::dealCards() {
	reshuffle();


	dealer.addCard(deck.dealCard());
	player.addCard(deck.dealCard());

	dealer.addCard(deck.dealCard());
	player.addCard(deck.dealCard());

}
void BlackJack::reshuffle() {
	if (deck.needsReshuffle()) {
		cout << "The deck is being reshuffled..." << endl;
		deck.shuffle();
	}
}