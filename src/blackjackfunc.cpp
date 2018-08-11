#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <array>
#include <string.h>

#include <blackjack.hpp>

using namespace std;

string cardsToString(int card){
	switch(card){
		case CARD_TWO: return "2"; break;
		case CARD_THREE: return "3"; break;
		case CARD_FOUR: return "4"; break;
		case CARD_FIVE: return "5"; break;
		case CARD_SIX: return "6"; break;
		case CARD_SEVEN: return "7"; break;
		case CARD_EIGHT: return "8"; break;
		case CARD_NINE: return "9"; break;
		case CARD_TEN: return "10"; break;
		case CARD_JACK: return "J"; break;
		case CARD_QUEEN: return "Q"; break;
		case CARD_KING: return "K"; break;
		case CARD_ACE: return "A"; break;
	}
	return "";
}

int cardsToValue(int card, int aceHigh){
	switch(card){
		case CARD_TWO: return 2; break;
		case CARD_THREE: return 3; break;
		case CARD_FOUR: return 4; break;
		case CARD_FIVE: return 5; break;
		case CARD_SIX: return 6; break;
		case CARD_SEVEN: return 7; break;
		case CARD_EIGHT: return 8; break;
		case CARD_NINE: return 9; break;
		case CARD_TEN: return 10; break;
		case CARD_JACK: return 10; break;
		case CARD_QUEEN: return 10; break;
		case CARD_KING: return 10; break;
		case CARD_ACE:
			if (aceHigh == 0){
				return 1;
			}else{
				return 11;
			}
			break;
	}
}

void dealToPlayer(enum Player player){
	int playerCard = rand() % FINAL_CARD_ENTRY;

	if(player == PLAYER_HUMAN){
		playerHand[playerCards] = playerCard;
		playerCards++;
	}else{
		dealerHand[dealerCards] = playerCard;
		dealerCards++;
	}
	
}

void printHand(string hand, int total, string playerName) {
	cout << playerName << " " << "Current Hand: " << hand << "\n";
	cout << "Total: " << total << "\n";
	cout << "\n";
	
	return;
}

void printDealerHand(const array<int, CARDS_PER_HAND> hand){
	int total = countHand(dealerHand, 1);

	if (total > 21){
		total = countHand(dealerHand, 0);
	}

	printHand(handToString(hand), total, "Dealer");
}

string handToString(const array<int, CARDS_PER_HAND> hand){
	string outString = "";                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            for (const int &card : hand){
		if(card > -1){
			outString = outString + cardsToString(card) + SPACING_CHARACTER;
		}
	}
	
	return outString;
}

int countHand(const array<int, CARDS_PER_HAND> hand, int aceHigh){
	int total = 0;

	for (const int &card : hand){
		if (card > -1){
			total += cardsToValue(card, aceHigh);
		}
	}

	return total;
}

char getPlayerInput(){
	return getchar();
}

void ClearScreen(){
	cout << string(100, '\n');
}

void MakeDealerMove(){
	int total = countHand(dealerHand, 1);

	if (total > 21){
		total = countHand(dealerHand, 0);
	}

	if(total < 17){
		dealToPlayer(PLAYER_DEALER);
	}
}

void BusySleep(){
	int sleepTime = 100000000;

	for (int i = 0; i < sleepTime; ++i){

	}
}

int CheckForWinner(const array<int, CARDS_PER_HAND> playerHand, const array<int, CARDS_PER_HAND> dealerHand){
	int playerHandTotal = countHand(playerHand, 1);
	int dealerHandTotal = countHand(dealerHand, 1);

	if (playerHandTotal > 21){
		playerHandTotal = countHand(playerHand, 0);
	}

	if (dealerHandTotal > 21){
		dealerHandTotal = countHand(dealerHand, 0);
	}

	printHand(handToString(playerHand), playerHandTotal, "Player");

	if (playerHandTotal > 21){
		if (dealerHandTotal > 21){
			// Draw
			printDealerHand(dealerHand);

			cout << "It's a Draw!" << "\n";

			return 1;
		}else{
			// Player loses
			printDealerHand(dealerHand);

			cout << "Dealer Wins!" << "\n";

			return 1;
		}
	}else if (playerHandTotal == 21){
		if (dealerHandTotal == 21){
			// Draw
			printDealerHand(dealerHand);

			cout << "It's a Draw!" << "\n";

			return 1;
		}else{
			// Player wins
			printDealerHand(dealerHand);

			cout << "Player Wins!" << "\n";

			return 1;
		}
	}else if (dealerHandTotal > 21 && playerHandTotal < 21){
		// Dealer loses
		printDealerHand(dealerHand);

		cout << "Player Wins!" << "\n";

		return 1;
	}else if (dealerHandTotal == 21 && playerHandTotal != 21){
		// Dealer loses
		printDealerHand(dealerHand);

		cout << "Dealer Wins!" << "\n";

		return 1;
	}else if (playerCards == CARDS_PER_HAND && playerHandTotal > dealerHandTotal){
			// Player wins
			printDealerHand(dealerHand);

			cout << "Player Wins!" << "\n";

			return 1;
	}else if (dealerCards == CARDS_PER_HAND && dealerHandTotal > playerHandTotal){
			// Dealer wins
			printDealerHand(dealerHand);
			
			cout << "Dealer Wins!" << "\n";

			return 1;
	}else{
		return 0;
	}
}
