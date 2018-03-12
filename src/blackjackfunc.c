#include <stdio.h>

#include <blackjack.h>

char* cardsToString(int card){
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

	playerHand[playerCards] = playerCard;
}

void printHand(enum Player player, char* hand) {
	printf("Hello makefiles!\n");
	
	return;
}
