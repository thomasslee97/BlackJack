#include <stdio.h>
#include <stdlib.h>

#include <array>

#include <blackjack.hpp>

// Current game state
enum State currentState = STATE_WELCOME_MESSAGE;

// Hands of both players
array<int, CARDS_PER_HAND> playerHand = {};
array<int, CARDS_PER_HAND> dealerHand = {};

// Number of cards in both player's hands
int playerCards = 0;
int dealerCards = 0;

int main() {
	// Whether game is running
	int gameRunning = 1;

	// Seed random
	srand (time(NULL));

	while (gameRunning == 1){
		switch (currentState){
			case STATE_WELCOME_MESSAGE: // Display welcome message
				{
					ClearScreen();
					printf("WELCOME!\n");
					currentState = STATE_SHOW_INSTRUCTIONS;
				}
				break;
			case STATE_SHOW_INSTRUCTIONS: // Display game instructions
				{
					printf("H: Hit, S: Stick, Enter: Start\n");
					printf("Press Start to continue... ");
					currentState = STATE_WAIT_FOR_START;
				}
				break;
			case STATE_WAIT_FOR_START:
				{
					// Wait for keypress
					getchar();
					currentState = STATE_RESET_ALL_VALUES;
				}
				break;
			case STATE_RESET_ALL_VALUES: // Reset all variables
				{
					for (int i = 0; i < CARDS_PER_HAND; i++){
						playerHand[i] = -1;
					}
					
					for (int i = 0; i < CARDS_PER_HAND; i++){
						dealerHand[i] = -1;
					}

					playerCards = 0;
					dealerCards = 0;

					currentState = GAME_LOOP;	
				}
				break;
			case GAME_LOOP:
				{
					ClearScreen();

					// Deal 2 cards to both players
					dealToPlayer(PLAYER_HUMAN);
					dealToPlayer(PLAYER_HUMAN);
					dealToPlayer(PLAYER_DEALER);
					dealToPlayer(PLAYER_DEALER);

					int gameOver = 0;

					// Number of time player has chosen "stick";
					int numberOfSticks = 0;

					while (gameOver == 0){
						ClearScreen();
						if (playerCards < CARDS_PER_HAND && dealerCards < CARDS_PER_HAND){ // No player has a full hand
							
							// Check if a player has won
							int winner = CheckForWinner(playerHand, dealerHand);

							// If someone has won, game is over
							if (winner == 1){
								gameOver = 1;
							}else{
								int validChoice = 0;
								
								cout << "Hit or Stick?" << "\n";

								// Get input from player
								while (validChoice == 0){
									char playerChoice = toupper(getPlayerInput());

									if (playerChoice == 'H'){
										dealToPlayer(PLAYER_HUMAN);
										
										validChoice = 1;
									}else if (playerChoice == 'S'){
										validChoice = 1;

										numberOfSticks++;
									}
								}

								MakeDealerMove();

								if(numberOfSticks >= 2){
									int playerTotal = countHand(playerHand, 1);
									int dealerTotal = countHand(dealerHand, 1);

									ClearScreen();
									printHand(handToString(playerHand), playerTotal, "Player");
									printHand(handToString(dealerHand), dealerTotal, "Dealer");

									if (playerTotal > dealerTotal){
										cout << "Player Wins!" << "\n";
									}else if(dealerTotal > playerTotal){
										cout << "Dealer Wins!" << "\n";
									}else{
										cout << "It's a Draw!" << "\n";
									}

									gameOver = 1;
								}
							}
						}else{
							int winner = CheckForWinner(playerHand, dealerHand);

							if (winner == 1){
								gameOver = 1;
							}
						}
					}

					gameRunning = 0;
				}
				break;
		}
	}

	return 0;
}
