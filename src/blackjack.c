#include <stdio.h>
#include <stdlib.h>

#include <blackjack.h>

enum State currentState = STATE_WELCOME_MESSAGE;

playerHand[CARDS_IN_HAND] = {};
dealerHand[CARDS_IN_HAND] = {};

playerCards = 0;
dealerCards = 0;

int main() {
	int gameRunning = 1;


	while (gameRunning == 1){
		switch (currentState){
			case STATE_WELCOME_MESSAGE:
				printf("WELCOME!\n");
				currentState = STATE_SHOW_INSTRUCTIONS;
				break;
			case STATE_SHOW_INSTRUCTIONS:
				printf("H: Hit, S: Stick, Enter: Start\n");
				printf("Press Start to continue... ");
				currentState = STATE_WAIT_FOR_START;
				break;
			case STATE_WAIT_FOR_START:
				getchar();
				currentState = STATE_DEAL_CARDS_PLAYER;
				break;
			case STATE_RESET_ALL_VALUES:
				for (int i = 0; i < CARDS_IN_HAND; i++){
					playerHand[i] = NULL;
				}
				
				for (int i = 0; i < CARDS_IN_HAND; i++){
					dealerHand[i] = NULL;
				}

				playerCards = 0;
				dealerCards = 0;
				break;
			case STATE_DEAL_CARDS_PLAYER:
				dealToPlayer(PLAYER_HUMAN);
				break;
			case STATE_DEAL_CARDS_DEALER:
				dealToPlayer(PLAYER_DEALER);
				break;
			case STATE_WAIT_FOR_PLAYER_CHOICE:
				break;
			case STATE_CALCULATE_HANDS:
				break;
		}
	}

	return 0;
}
