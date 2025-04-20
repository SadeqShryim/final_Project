#include <iostream>
#include <string>
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
	//need to add checkGame if Blackjack or not 
	if (checkGame(player)) {
		cout << "Blackjack!!! You Win!!!" << endl;
		adjust(1);
		return;
	}

	playerTurn();

	!player.isLose() ? dealerTurn() : whoWon();
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

void BlackJack::playerTurn() {
	int choice;
	bool v = true;
	cout << endl << endl;
	playerHand();
	while(v){
		
		if (player.isLose()) {
			cout << "You busted!" << endl;
			v = false;
		}
		cout << "Choose: \n1) Hit\n2) Stand " << endl;
		cout << "---------" << endl;
		cin >> choice;

		if (choice == 1) {
			cout << "You chose to Hit" << endl;
			player.addCard(deck.dealCard());
		}
		else if (choice == 2) {
			cout << "You chose to Stand" << endl;
			v = false;
		}
		else {
			cout << "Invalid Entry. 1 -- HIT or 2 -- Stand" << endl << endl;
		}
	}
}

void BlackJack::dealerTurn() {
	cout << endl << endl;
	dealerHand(true);

	while (dealer.getBalance() < 17) {
		cout << "Dealer Hits" << endl;
		dealer.addCard(deck.dealCard());
		dealerHand(true);
	}

	cout << (dealer.isLose() ? "Dealer Busted" : "Dealer Stands"); 	
}

void BlackJack::adjust(int outcome) {
	if (outcome == 1) {
		player.updateBalance(player.getBalance() + 1);
	}
	else if (outcome == -1) {
		player.updateBalance(player.getBalance() + 1);
	}
	//else draw (outcome = 0) nothing changes
}
void BlackJack::whoWon() {
	int pTotal = player.getHandValue();
	int dTotal = dealer.getHandValue();

	cout << "Final Hands" << endl;

	playerHand();
	dealerHand(true);
	if (player.isLose()) {
		cout << "You Busted, Dealer Wins" << endl;
		adjust(-1);
	}
	else if (dealer.isLose()) {
		cout << "Dealer Busted, You Win!" << endl;
		adjust(1);
	}
	else if (pTotal > dTotal) {
		cout << "You Win!" << endl;
		adjust(1);
	}
	else if (pTotal < dTotal) {
		cout << "Dealer Wins!" << endl;
		adjust(-1);
	}
	else {
		cout << "DRAW!!!" << endl;
		adjust(0);
	}

	cout << "Your Current Balance: $" << player.getBalance() << endl;
}

bool BlackJack::checkGame(const Player& player) const {
	return (this->player.getHandValue() == 21 and this->player.getHand().size() == 2);
}
